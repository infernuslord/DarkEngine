// $Header: r:/t2repos/thief2/src/portal/mapper.c,v 1.26 2000/02/19 12:32:43 toml Exp $
//
// Setup/initialization etc. for port demo

#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>


#include <lg.h>
#include <2d.h>
#include <fix.h>
#include <lgsprntf.h>
#include <r3d.h>
#include <tmpalloc.h>
#include <mprintf.h>

#include <timer.h>
#include <tminit.h>

#include <ptmap.h>
#include <recip.h>

#include <mapper.h>
#include <ptmapper.h>

#include <profile.h>

#ifdef FLOAT_TMAP
#include <math.h>
#include <memall.h>
#include <dbmem.h>   // must be last header! 
#endif

extern int scale;
extern bool tm_on;
int scanline;

bool poly_lit;

double fda,fdb,fdc;
double gda,gdb,gdc;
double one=1.0;

extern double tmap_data[9];
static fix tmap_data_fix[9];

extern void my_error(char *s);


// enable various asm routines in ptmapper

//#define UNCLIPPED_ASM
//#define CLIPPED_ASM

#define USE_ASM_OUTER_LOOP
#define RPI_UNLIT_ASM


#define MAX_LENGTH 1024
#define NUM_ENTRIES 32

extern int pixel_count[NUM_ENTRIES];
extern uchar length_mapping[MAX_LENGTH];

// fast conversion from float to fix
//   hack value for float to int is 2^52
//   this corresponds to "right shifting".
//   to convert from float to fix, we want
//   to rightshift less, so we use 2^(52-16)

#if 1

  static double convert_hack;
  #define HACK_VALUE ((double) (1 << 18) * (1 << 18) * 1.5)

  #define fast_float_to_fix(x)  \
     (convert_hack = (x) + HACK_VALUE, * (fix *) &convert_hack)

#else

  #define fast_float_to_fix(x)  float_to_fix(x)

#endif


///////////////////////////////////////////////////
//
//   General scan conversion routines
//

#define MAX_HEIGHT  768

int y_max, y_min;
extern bool span_clip;

static int xdata[MAX_HEIGHT][2];
static fix idata[MAX_HEIGHT][2];
static fix uvdata[MAX_HEIGHT][2];

void reset_scan_buffer(void)
{
   y_max = -1;
   y_min = MAX_HEIGHT;
}

//   note we just scan convert into a table
//   rather than have to try to cope with
//   edges in the main code

#define SHADES fix_make(16,0)

void scan_convert(r3s_point *p1, r3s_point *p2)
{  PROF
   r3s_point *temp;

   int left, y1,y2;
   fix x,dx, i,di;

   // swap so point p1 is first
   if (p1->grp.sy > p2->grp.sy) {
      temp = p1;
      p1 = p2;
      p2 = temp;
      left = 1;
   } else
      left = 0;

   y1 = fix_cint(p1->grp.sy);
   y2 = fix_cint(p2->grp.sy);
   
   if (y1 == y2) { END_PROF; return; }

   // update the global max/min scanline counter
   if (y1 < y_min)
      y_min = y1;
   if (y2 > y_max)
      y_max = y2;

   // compute slope w.r.t. y axis
   dx = fix_div(p2->grp.sx - p1->grp.sx, p2->grp.sy - p1->grp.sy);

   // compute scan location, fixed up to the next crossing
   x = p1->grp.sx + fix_mul(dx, fix_ceil(p1->grp.sy) - p1->grp.sy);

   if (poly_lit) {
      di = (p2->grp.i - p1->grp.i)*SHADES * 65536 / (p2->grp.sy - p1->grp.sy);
      i  = p1->grp.i*SHADES + fix_mul(di, fix_ceil(p1->grp.sy) - p1->grp.sy);
      if (di < 0) di += 1;

      // now generate all crossings for this edge
      while (y1 < y2) {
         xdata[y1][left] = fix_cint(x);
         idata[y1][left] = i;
         x += dx;
         i += di;
         ++y1;
      }
   } else {
#if 1
      pt_scan_convert(x, &xdata[y1][left], dx, y2 - y1);
#else
      // now generate all crossings for this edge
      while (y1 < y2) {
         xdata[y1][left] = fix_cint(x);
         x += dx;
         ++y1;
      }
#endif
   }
   END_PROF;
}

void scan_convert_uv(r3s_point *p1, r3s_point *p2)
{  PROF

   int left, y1,y2, j;
   fix x,dx, i,di, dy_fixup, delta_y;
   int this_x, prev_x, x_step;
   fix du2, dv2, x_fixup;
   uv_scan_info info;

   fix u,v, du,dv;
   fix u_adjust[4], v_adjust[4];

   // swap so point p1 is first
   if (p1->grp.sy > p2->grp.sy) {
#if 0
      r3s_point *temp;
      temp = p1;
      p1 = p2;
      p2 = temp;
      left = 1;
#else
      // only bother computing uv values down the left
      scan_convert(p1, p2);
      return;
#endif
   } else
      left = 0;

   y1 = fix_cint(p1->grp.sy);
   y2 = fix_cint(p2->grp.sy);
   
   if (y1 == y2) { END_PROF; return; }

   // update the global max/min scanline counter
   if (y1 < y_min)
      y_min = y1;
   if (y2 > y_max)
      y_max = y2;

   // compute u_adjust, v_adjust tables
   u = 0;
   v = 0;
   du = tmap_data_fix[3] >> 2;
   dv = tmap_data_fix[4] >> 2;
   for (j=3; j >= 0; --j) {
      u_adjust[j] = u;
      v_adjust[j] = v;
      u += du;
      v += dv;
   }   

   // compute slope w.r.t. y axis
   delta_y  = p2->grp.sy - p1->grp.sy;
   dy_fixup = fix_ceil(p1->grp.sy) - p1->grp.sy;

   dx = fix_div(p2->grp.sx - p1->grp.sx, delta_y);

   // compute scan location, fixed up to the next crossing
   x = p1->grp.sx + fix_mul(dx, dy_fixup);

#if 0
   // naive implementation for u,v,du,dv as floats

   // duv slope
   du = (p2->grp.u - p1->grp.u) / ((p2->grp.sy - p1->grp.sy) / 65536.0);
   dv = (p2->grp.v - p1->grp.v) / ((p2->grp.sy - p1->grp.sy) / 65536.0);

   // subpixel corrected
   u = p1->grp.u + du * dy_fixup / 65536;
   v = p1->grp.v + dv * dy_fixup / 65536;
#endif
   // fixes

   // duv slope
   du = fast_float_to_fix((p2->grp.u - p1->grp.u) / delta_y * 65536.0);
   dv = fast_float_to_fix((p2->grp.v - p1->grp.v) / delta_y * 65536.0);

   // subpixel corrected vertically
   u = fast_float_to_fix(p1->grp.u) + fix_mul(du, dy_fixup);
   v = fast_float_to_fix(p1->grp.v) + fix_mul(dv, dy_fixup);

   du2 = tmap_data_fix[3];
   dv2 = tmap_data_fix[4];

   x_fixup = fix_ceil(x)-x;
   u += fix_mul(x_fixup, du2);
   v += fix_mul(x_fixup, dv2);

   x_step = fix_int(dx); // take the floor of the x step size
   
   du = tmap_data_fix[6] + du2 * x_step;   // compute vertical step
   dv = tmap_data_fix[7] + dv2 * x_step;   // compute vertical step

   du2 += du;   // alternate step goes one further to the right
   dv2 += dv;

   info.x   =  x;
   info.dx  = dx;
   info.u   =  u;
   info.v   =  v;
   info.du  = du;
   info.dv  = dv;
   info.du2 = du2;
   info.dv2 = dv2;

   if (poly_lit) {
      di = (p2->grp.i - p1->grp.i)*SHADES * 65536 / (p2->grp.sy - p1->grp.sy);
      i  = p1->grp.i*SHADES + fix_mul(di, fix_ceil(p1->grp.sy) - p1->grp.sy);
      if (di < 0) di += 1;

      this_x = fix_cint(x);

      // now generate all crossings for this edge
      while (y1 < y2) {
         xdata[y1][0] = this_x;
         uvdata[y1][0] = u;
         uvdata[y1][1] = v;
         idata[y1][left] = i;
         i += di;
         x += dx;

         prev_x = this_x;
         this_x = fix_cint(x);

         if (prev_x + x_step == this_x) {
            u  += du;
            v  += dv;
         } else {
            u  += du2;
            v  += dv2;
         }
         ++y1;
      }
   } else {
#if 1
      pt_scan_convert_uv(&info, &xdata[y1][0], &uvdata[y1][0], y2-y1);
#else
      this_x = fix_cint(x);
      while (y1 < y2) {
         xdata[y1][0] = this_x;
         uvdata[y1][0] = u;
         uvdata[y1][1] = v;
         x += dx;

         prev_x = this_x;
         this_x = fix_cint(x);

         if (prev_x + x_step == this_x) {
            u  += du;
            v  += dv;
         } else {
            u  += du2;
            v  += dv2;
         }
         ++y1;
      }
#endif
   }
   END_PROF;
}


///////////////////////////////////////////////////
//
//   Triangle scan conversion routines
//
// This takes a triangle and sets y_min, y_max,
//    and xdata,udata,vdata within that range
//
// A trivial implementation can build upon the
// above scan converters; however, that's not
// particularly efficient.
//
// requires we've computed the triangle u,v slopes
// into tmap_data as seen in compute_duv_tri_full.

#if 0
   #define fix_frac_ceil(n)  (fix_ceil(n) - (n))
#else
   #define fix_frac_ceil(n)  ((-n) & 65535)  // two's complement hack
#endif


// draw a horizontal trapeziod
void tri_flat(r3s_phandle l0, r3s_phandle l1, r3s_phandle r0, r3s_phandle r1)
{
   fix xl, xr, dxl, dxr, u,v,du,dv, du2,dv2, x_step, prev_x, this_x;
   fix delta_y, y_adjust;
   int y;

   y_min = fix_cint(l0->grp.sy);
   y_max = fix_cint(l1->grp.sy);

   // compute right info

   xr = r0->grp.sx;
   delta_y = r1->grp.sy - r0->grp.sy;
   y_adjust = fix_frac_ceil(r0->grp.sy);

   dxr = fix_div(r1->grp.sx - r0->grp.sx, delta_y);
   xr += fix_mul(dxr, y_adjust);

   // compute left info

   xl = l0->grp.sx;
   delta_y = l1->grp.sy - l0->grp.sy;
   y_adjust = fix_frac_ceil(l0->grp.sy);

   dxl = fix_div(l1->grp.sx - l0->grp.sx, delta_y);
   xl += fix_mul(dxl, y_adjust);

   // determine what the two different x steps are
   x_step = fix_int(dxl); // take the floor of the x step size
   
   this_x = fix_cint(xl);

   u = v = du = dv = du2 = dv2 = 0;

   for (y=y_min; y < y_max; ++y) {
      xdata[y][0] = this_x;
      xdata[y][1] = fix_cint(xr);
      uvdata[y][0] = u;
      uvdata[y][0] = v;
      xr += dxr;
      xl += dxl;

      prev_x = this_x;
      this_x = fix_cint(xl);

      if (prev_x + x_step == this_x) {
         u  += du;
         v  += dv;
      } else {
         u  += du2;
         v  += dv2;
      }
   }
}

// draw a triangle with two edges on left, one on right
void tri_two_left(r3s_phandle top, r3s_phandle mid, r3s_phandle bot)
{
   fix xl, xr, dxl, dxr, u,v,du,dv;
   fix delta_y, y_adjust;
   int y, y_between;

   y_min = fix_cint(top->grp.sy);
   y_max = fix_cint(bot->grp.sy);
   y_between = fix_cint(mid->grp.sy);

   // compute right info

   xr = top->grp.sx;
   delta_y = bot->grp.sy - top->grp.sy;
   y_adjust = fix_frac_ceil(top->grp.sy);

   dxr = fix_div(bot->grp.sx - top->grp.sx, delta_y);
   xr += fix_mul(dxr, y_adjust);

   // compute first edge left info

   xl = top->grp.sx;
   delta_y = mid->grp.sy - top->grp.sy;
   y_adjust = fix_frac_ceil(top->grp.sy);

   dxl = fix_div(mid->grp.sx - top->grp.sx, delta_y);
   xl += fix_mul(dxl, y_adjust);
   
   du = fix_div((mid->grp.u - top->grp.u)*65536, delta_y);
   dv = fix_div((mid->grp.v - top->grp.v)*65536, delta_y);

   u = top->grp.u*65536 + fix_mul(du, y_adjust);
   v = top->grp.v*65536 + fix_mul(dv, y_adjust);

   for (y=y_min; y < y_between; ++y) {
      xdata[y][0] = fix_cint(xl);
      xdata[y][1] = fix_cint(xr);
      xl += dxl;
      xr += dxr;
   }

   // now update the left edge

   xl = mid->grp.sx;
   delta_y = bot->grp.sy - mid->grp.sy;
   y_adjust = fix_frac_ceil(mid->grp.sy);

   dxl = fix_div(bot->grp.sx - mid->grp.sx, delta_y);
   xl += fix_mul(dxl, y_adjust);

   for (y=y_between; y < y_max; ++y) {
      xdata[y][0] = fix_cint(xl);
      xdata[y][1] = fix_cint(xr);
      xl += dxl;
      xr += dxr;
   }
}

// draw a triangle with two edges on right, one on left
void tri_two_right(r3s_phandle top, r3s_phandle mid, r3s_phandle bot)
{
   fix xl, xr, dxl, dxr;
   fix delta_y, y_adjust;
   int y, y_between;

   y_min = fix_cint(top->grp.sy);
   y_max = fix_cint(bot->grp.sy);
   y_between = fix_cint(mid->grp.sy);

   // compute left info

   delta_y = bot->grp.sy - top->grp.sy;
   y_adjust = fix_frac_ceil(top->grp.sy);

   dxl = fix_div(bot->grp.sx - top->grp.sx, delta_y);
   xl = top->grp.sx + fix_mul(dxl, y_adjust);

   // compute first edge right info

   delta_y = mid->grp.sy - top->grp.sy;
   y_adjust = fix_frac_ceil(top->grp.sy);

   dxr = fix_div(mid->grp.sx - top->grp.sx, delta_y);
   xr = top->grp.sx + fix_mul(dxl, y_adjust);
   
   for (y=y_min; y < y_between; ++y) {
      xdata[y][0] = fix_cint(xl);
      xdata[y][1] = fix_cint(xr);
      xl += dxl;
      xr += dxr;
   }

   // now update the right edge

   delta_y = bot->grp.sy - mid->grp.sy;
   y_adjust = fix_frac_ceil(mid->grp.sy);

   dxr = fix_div(bot->grp.sx - mid->grp.sx, delta_y);
   xr = mid->grp.sx + fix_mul(dxl, y_adjust);

   for (y=y_between; y < y_max; ++y) {
      xdata[y][0] = fix_cint(xl);
      xdata[y][1] = fix_cint(xr);
      xl += dxl;
      xr += dxr;
   }
}

void scan_convert_tri_uv(r3s_phandle *vp)
{
   int sy[3];

   sy[0] = fix_cint(vp[0]->grp.sy);
   sy[1] = fix_cint(vp[1]->grp.sy);
   sy[2] = fix_cint(vp[2]->grp.sy);

   // there are four meaningful cases:
   //     1:  two left edges
   //     2:  two right edges
   //     3:  horizontal top edge
   //     4:  horizontal bottom edge

   // So we have three main triangle scanners:
   //     1:  tri_two_left(pleft0, pleft1, pleft2) (right == pleft0->pleft2)
   //     2:  tri_two_right(prt0, prt1, prt2) (left == prt0->prt2)
   //     3:  tri_flat(pleft0,pleft1, prt0, prt1)

   // ideally, we wouldn't do our equality tests first,
   // because we could infer them from some inequality tests.
   // however, we could only infer them half the time, so
   // we don't bother for now, since the code would be less clear.

   if (sy[0] == sy[1]) {
      if (sy[0] == sy[2])
         y_min = y_max = 0;
      if (sy[2] < sy[0])
         tri_flat(vp[2],vp[1], vp[2],vp[0]);
      else 
         tri_flat(vp[0],vp[2], vp[1],vp[2]);
   } else if (sy[0] == sy[2]) {
      if (sy[1] < sy[0])
         tri_flat(vp[1],vp[0], vp[1],vp[2]);
      else
         tri_flat(vp[2],vp[1], vp[0],vp[1]);
   } else if (sy[1] == sy[2]) {
      if (sy[0] < sy[1])
         tri_flat(vp[0],vp[2], vp[0],vp[1]);
      else
         tri_flat(vp[1],vp[0], vp[2],vp[0]);

   // now come the normal 3! cases
   // we've designed the called functions so that
   // the parameters always appear in top to bottom
   // order, for ease of verifying correctness

   } else if (sy[0] < sy[1]) {
      if (sy[1] < sy[2])
         tri_two_right(vp[0], vp[1], vp[2]); // 0 < 1 < 2
      else if (sy[0] < sy[2]) // 0 < 1, 2 < 1
         tri_two_left(vp[0], vp[2], vp[1]);  // 0 < 2 < 1
      else
         tri_two_right(vp[2], vp[0], vp[1]); // 2 < 0 < 1
   } else {
      if (sy[0] < sy[2])
         tri_two_left(vp[1], vp[0], vp[2]);  // 1 < 0 < 2
      else if (sy[1] < sy[2]) // 1 < 0, 2 < 0
         tri_two_right(vp[1], vp[2], vp[0]); // 1 < 2 < 0
      else
         tri_two_left(vp[2], vp[1], vp[0]);  // 2 < 1 < 0
   }
}     

extern uchar *pt;

double u_step_data, v_step_data;

void real_render_poly_lit_float(int y0, int y1)
{  PROF
   int x,len, i;
   int row;
   uchar *dest, *destcore;
   float a,b,c, ma,mb,mc;

#ifdef DBG_ON
   if (y0 < y_min || y0 >= y_max || y1 < y_min || y1 > y_max) {
      mprintf("Invalid real render: %d-%d in %d-%d\n", y0,y1, y_min, y_max);
      END_PROF;
      return;
   }
#endif

   ma = tmap_data[0] + tmap_data[6] * y0;
   mb = tmap_data[1] + tmap_data[7] * y0;
   mc = tmap_data[2] + tmap_data[8] * y0;

   row = grd_bm.row;
   destcore = grd_bm.bits + y0 * row;

   for (i=y0; i < y1; ++i) {
      x   = xdata[i][0];
      len = xdata[i][1] - x;

      if (len > 0) {
         scanline = i&1;
         dest = destcore + x;

         a = ma + fda*x;
         b = mb + fdb*x;
         c = mc + fdc*x;

         u_step_data = c * fda - a * fdc;
         v_step_data = c * fdb - b * fdc;

         ptmap_set_lighting(idata[i][0], idata[i][1], dest);
         ptmap_do_perspective_lit_run_implicit(dest, len, a, b, c);
      }
      destcore += row;
      ma += tmap_data[6];
      mb += tmap_data[7];
      mc += tmap_data[8];
   }
   END_PROF;
}

#define IS_NEGATIVE(a,b,c)  (((c) < 0) ^ (((a) < 0) || ((b) < 0)))
#define NEG_PAIR(a,c)    (((c) < 0) ^ ((a) < 0))

extern int stat_num_spans_clamped;
extern int stat_num_spans_drawn;
extern int stat_num_polys_clipped_away;
int dest_row;
bool asm_outer;

void real_render_poly_float(int y0, int y1)
{  PROF
#ifndef USE_ASM_OUTER_LOOP
   int x,len, i;
   float a,b,c;
   uchar *dest;
#endif
   float ma,mb,mc;
   int row;
   uchar *destcore;

#ifdef DBG_ON
   if (y0 < y_min || y0 >= y_max || y1 < y_min || y1 > y_max) {
      mprintf("Invalid real render: %d-%d in %d-%d\n", y0,y1, y_min, y_max);
      END_PROF;
      return;
   }
#endif

   if (y0 >= y1) return;

   ma = tmap_data[0] + tmap_data[6] * y0;
   mb = tmap_data[1] + tmap_data[7] * y0;
   mc = tmap_data[2] + tmap_data[8] * y0;

   dest_row = row = grd_bm.row;
   destcore = grd_bm.bits + y0 * row;

   stat_num_spans_drawn += (y1 - y0);

#ifdef USE_ASM_OUTER_LOOP
   {
      double abc[3];
      abc[0] = ma;
      abc[1] = mb;
      abc[2] = mc;
      pt_asm_outer_loop(abc, destcore, &xdata[y0][0], y1-y0);
   }
#else
   for (i=y0; i < y1; ++i) {
      x   = xdata[i][0];
      len = xdata[i][1] - x;

      if (len > 0) {
         float end_a, end_b, end_c;
#ifdef DBG_ON
         float orig_a, orig_b, orig_c;
         float old_u_step, old_v_step;
#endif

         dest = destcore + x;

         a = ma + fda*x;
         b = mb + fdb*x;
         c = mc + fdc*x;

         u_step_data = c * fda - a * fdc;
         v_step_data = c * fdb - b * fdc;

         if (len > 1) {
            end_a = a + (len-1) * fda;
            end_b = b + (len-1) * fdb;
            end_c = c + (len-1) * fdc;
         }

         pixel_count[length_mapping[len]] += len;

#if 1
         {
            while (len--) {
               fix u = a/c + fix_make(2,0), v = b/c + fix_make(2,0);
               a += fda;
               b += fdb;
               c += fdc;
               *dest++ = pt_tmap_ptr[256*(v >> 16) + (u >> 16)]; 
            }
         }
#else
         ptmap_do_perspective_lit_run_implicit(dest, len, a, b, c);
#endif
      }
      destcore += row;
      ma += tmap_data[6];
      mb += tmap_data[7];
      mc += tmap_data[8];
   }
#endif

   END_PROF;
}

void do_perspective_poly(grs_bitmap *bm, int n, r3s_phandle *vp)
{  PROF
   int len;
   int i,j;

   ptmap_setup(bm);

   reset_scan_buffer();

   j = n-1;
   for (i=0; i < n; ++i) {
      scan_convert(vp[i], vp[j]);
      j = i;
   }

   // 0-height poly
   if (y_min >= y_max) {
      END_PROF;
      return;
   }

   if (poly_lit) {
      for (i=y_min; i < y_max; ++i) {
         len = xdata[i][1] - xdata[i][0];
         if (len > 0) {
            idata[i][1] = (idata[i][1] - idata[i][0]) / len;
            if (idata[i][1] < 0) ++idata[i][1];
         }
      }
   }

   fda = tmap_data[3];
   fdb = tmap_data[4];
   fdc = tmap_data[5];

   gda = tmap_data[3]*8;
   gdb = tmap_data[4]*8;
   gdc = tmap_data[5]*8;

   if (poly_lit)
      real_render_poly_lit_float(y_min, y_max);
   else
      real_render_poly_float(y_min, y_max);

   END_PROF;
}

/*
 *   compute_duv_tri
 *
 * computes triangle gradients for affine mapping:
 *
 *  [ tmap_data[0] = u(0,0)  ]
 *  [ tmap_data[1] = v(0,0)  ]
 *    tmap_data[3] = du/dx
 *    tmap_data[4] = dv/dx
 *    tmap_data[6] = du/dy
 *    tmap_data[7] = dv/dy
 */

//dr/dx = ((r1-r2)(y0-y2)-(r0-r2)(y1-y2))/((x1-x2)(y0-y2)-(x0-x2)(y1-y2))

void compute_duv_tri(r3s_phandle *vp)
{
   grs_point *p0 = &vp[0]->grp;
   grs_point *p1 = &vp[1]->grp;
   grs_point *p2 = &vp[2]->grp;

   double dx02 = (p0->sx - p2->sx) / 65536.0;
   double dx12 = (p1->sx - p2->sx) / 65536.0;
   double dy02 = (p0->sy - p2->sy) / 65536.0;
   double dy12 = (p1->sy - p2->sy) / 65536.0;

   double grad_div = 1 / (dx12 * dy02 - dx02 * dy12);

   tmap_data[3] = ((p1->u-p2->u)*dy02 - (p0->u-p2->u)*dy12) * grad_div;
   tmap_data[4] = ((p1->v-p2->v)*dy02 - (p0->v-p2->v)*dy12) * grad_div;

   tmap_data_fix[3] = fast_float_to_fix(tmap_data[3]);
   tmap_data_fix[4] = fast_float_to_fix(tmap_data[4]);
}

void compute_duv_tri_full(r3s_phandle *vp)
{
   grs_point *p0 = &vp[0]->grp;
   grs_point *p1 = &vp[1]->grp;
   grs_point *p2 = &vp[2]->grp;

   double dx02 = (p0->sx - p2->sx) / 65536.0;
   double dx12 = (p1->sx - p2->sx) / 65536.0;
   double dy02 = (p0->sy - p2->sy) / 65536.0;
   double dy12 = (p1->sy - p2->sy) / 65536.0;

   double grad_div = 1 / (dx12 * dy02 - dx02 * dy12);

   tmap_data[3] = ((p1->u-p2->u)*dy02 - (p0->u-p2->u)*dy12) * grad_div;
   tmap_data[4] = ((p1->v-p2->v)*dy02 - (p0->v-p2->v)*dy12) * grad_div;

   tmap_data[6] = ((p0->u-p2->u)*dx12 - (p1->u-p2->u)*dx02) * grad_div;
   tmap_data[7] = ((p0->v-p2->v)*dx12 - (p1->v-p2->v)*dx02) * grad_div;

   tmap_data_fix[3] = fast_float_to_fix(tmap_data[3]);
   tmap_data_fix[4] = fast_float_to_fix(tmap_data[4]);

   tmap_data_fix[6] = fast_float_to_fix(tmap_data[6]);
   tmap_data_fix[7] = fast_float_to_fix(tmap_data[7]);
#if 0
   // p0->u = tmap_data[0] + tmap_data[3]*p0->sx + tmap_data[6]*p0->sy

   // ideally we might compute this for all 3 points, and take the average

   tmap_data[0] = p0->u - tmap_data[3]*p0->sx/65536 - tmap_data[6]*p0->sy/65536;
   tmap_data[1] = p0->v - tmap_data[4]*p0->sx/65536 - tmap_data[7]*p0->sy/65536;
#endif
}

void do_linear_tri(grs_bitmap *bm, r3s_phandle *vp)
{  PROF
   uchar *destcore;
   int i, row;
   fix dudx, dvdx;

   ptmap_setup(bm);

   reset_scan_buffer();

   compute_duv_tri_full(vp);

   scan_convert_uv(vp[0], vp[2]);
   scan_convert_uv(vp[1], vp[0]);
   scan_convert_uv(vp[2], vp[1]);

   // 0-height poly
   if (y_min >= y_max) {
      END_PROF;
      return;
   }

   if (poly_lit) {
      for (i=y_min; i < y_max; ++i) {
         int len = xdata[i][1] - xdata[i][0];
         if (len > 0) {
            idata[i][1] = (idata[i][1] - idata[i][0]) / len;
            if (idata[i][1] < 0) ++idata[i][1];
         }
      }
   }

   row = grd_bm.row;
   destcore = grd_bm.bits + y_min*row;

   stat_num_spans_drawn += (y_max - y_min);

   dudx = tmap_data_fix[3];
   dvdx = tmap_data_fix[4];

   if (poly_lit) {
      for (i=y_min; i < y_max; ++i) {
         int x;
         int len;
         x = xdata[i][0];
         len = xdata[i][1] - x;
   
         if (len > 0) {
            ptmap_do_lit_run(destcore+x, len,
                     uvdata[i][0], uvdata[i][1], dudx, dvdx,
                     idata[i][0], idata[i][1]);
         }
         destcore += row;
      }
   } else {
      for (i=y_min; i < y_max; ++i) {
         int x;
         int len;
         x = xdata[i][0];
         len = xdata[i][1] - x;
   
         if (len > 0) {
            ptmap_do_run(destcore+x, len,
                     uvdata[i][0], uvdata[i][1], dudx, dvdx);
         }
         destcore += row;
      }
   }

   END_PROF;
}

///////////////////////////////////////////////////////////////

//  span clipping

typedef struct span_item
{
   ushort start_x;  // starting location
   uchar  len;      // length in pixels
   uchar  delta_y;  // vertical delta from last span
} SpanItem;

typedef struct render_poly_info
{
   grs_bitmap *bm;
   uchar *bits;
   double tm_dat[9];
   int y;
   int count;
   SpanItem *span_info;
   struct render_poly_info *next;
} RenderPolyInfo;

RenderPolyInfo *rpi_head;
RenderPolyInfo **rpi_tail=&rpi_head;

void render_rpi(RenderPolyInfo *rpi)
{  PROF
   int y,len, x, dy, skip_i;
   int row;
   uchar *dest, *destcore;
   float a,b,c, ma,mb,mc;
   SpanItem *si, *end;

   memcpy(tmap_data, rpi->tm_dat, sizeof(tmap_data));

   fda = tmap_data[3];
   fdb = tmap_data[4];
   fdc = tmap_data[5];

   gda = tmap_data[3]*8;
   gdb = tmap_data[4]*8;
   gdc = tmap_data[5]*8;

   pt_tmap_ptr  = rpi->bits;
   pt_tmap_mask = (rpi->bm->h-1) * 256 + (rpi->bm->w-1);
   
   ptmap_setup(rpi->bm);

   y = rpi->y;
   si = rpi->span_info;
   end = si + rpi->count;

   row = grd_bm.row;
   destcore = grd_bm.bits + y * row;

   ma = tmap_data[0] + tmap_data[6] * y;
   mb = tmap_data[1] + tmap_data[7] * y;
   mc = tmap_data[2] + tmap_data[8] * y;

   skip_i = 0;

   while (si < end) {
      len = si->len;
      if (len == 0) {
         // if we get a 0 length thing,
         // that means we should skip vertically
         // by more than our normally allowed limit (255)
         // by using this item solely for skipping
         ++si;
         dy = si->start_x;
         goto skip_y;
      }

      x = si->start_x;

      // if length == 255, then we've encoded
      // the real length in the next one
      if (len == 255) {
         ++si;
         len = si->start_x;
      }
      dy = si->delta_y;
         
      dest = destcore + x;


      if (!skip_i) {
         int mylen = xdata[y][1] - xdata[y][0];
         idata[y][1] = fix_mul((idata[y][1] - idata[y][0]) >> 4, reciprocal_table_24[mylen] >> 4);
         if (idata[y][1] < 0) ++idata[y][1];
         //if (idata[y][1] != 0) mprintf("%d\n", idata[y][1]);
         scanline = y & 1;
      }

      if (x == xdata[y][0])
         ptmap_set_lighting(idata[y][0], idata[y][1], dest);
      else
         ptmap_set_lighting(idata[y][0] + idata[y][1]*(x - xdata[y][0]), idata[y][1], dest);

      a = ma + fda*x;
      b = mb + fdb*x;
      c = mc + fdc*x;

      u_step_data = c * fda - a * fdc;
      v_step_data = c * fdb - b * fdc;

      ptmap_do_perspective_lit_run_implicit(dest, len, a, b, c);

      if (!dy)
         skip_i = 1;
      else if (dy == 1) {
         destcore += row;
         ma += tmap_data[6];
         mb += tmap_data[7];
         mc += tmap_data[8];
         skip_i = 0;
      } else {
        skip_y:
         destcore += row*dy;
         ma += tmap_data[6]*dy;
         mb += tmap_data[7]*dy;
         mc += tmap_data[8]*dy;
         skip_i = 0;
      }
      y += dy;
      ++si;
   }
   END_PROF;
}

void render_rpi_unlit(RenderPolyInfo *rpi)
{  PROF
   int y, row;
   uchar *destcore;
#ifdef RPI_UNLIT_ASM
   double mabc[3];
#else
   float a,b,c, ma,mb,mc;
   uchar *dest;
   int i,x,dy,len;
#endif
   SpanItem *si, *end;

   memcpy(tmap_data, rpi->tm_dat, sizeof(tmap_data));

   fda = tmap_data[3];
   fdb = tmap_data[4];
   fdc = tmap_data[5];

   gda = tmap_data[3]*8;
   gdb = tmap_data[4]*8;
   gdc = tmap_data[5]*8;

   pt_tmap_ptr  = rpi->bits;
   pt_tmap_mask = (rpi->bm->h-1) * 256 + (rpi->bm->w-1);
   
   ptmap_setup(rpi->bm);

   y = rpi->y;
   si = rpi->span_info;
   end = si + rpi->count;

   row = grd_bm.row;
   destcore = grd_bm.bits + y * row;

#ifdef RPI_UNLIT_ASM
   dest_row = grd_bm.row;
   mabc[0] = tmap_data[0] + tmap_data[6]*y;
   mabc[1] = tmap_data[1] + tmap_data[7]*y;
   mabc[2] = tmap_data[2] + tmap_data[8]*y;
   pt_render_rpi_unlit_asm(si, mabc, destcore, end);
#else
   ma = tmap_data[0] + tmap_data[6] * y;
   mb = tmap_data[1] + tmap_data[7] * y;
   mc = tmap_data[2] + tmap_data[8] * y;

   while (si < end) {
      len = si->len;
      if (len == 0) {
         // if we get a 0 length thing,
         // that means we should skip vertically
         // by more than our normally allowed limit (255)
         // by using this item solely for skipping
         ++si;
         dy = si->start_x;
         goto skip_y;
      }

      x = si->start_x;

      // if length == 255, then we've encoded
      // the real length in the next one
      if (len == 255) {
         ++si;
         len = si->start_x;
      }
      dy = si->delta_y;
         
      dest = destcore + x;

      c = mc + fdc*x;
      a = ma + fda*x;
      b = mb + fdb*x;

      u_step_data = c * fda - a * fdc;
      v_step_data = c * fdb - b * fdc;

      ptmap_do_perspective_lit_run_implicit(dest, len, a, b, c);

      if (dy == 1) {
         destcore += row;
         ma += tmap_data[6];
         mb += tmap_data[7];
         mc += tmap_data[8];
      } else if (dy) {
        skip_y:
         destcore += row*dy;
         ma += tmap_data[6]*dy;
         mb += tmap_data[7]*dy;
         mc += tmap_data[8]*dy;
      }
      y += dy;
      ++si;
   }
#endif
   END_PROF;
}

void render_rpi_linear(RenderPolyInfo *rpi)
{  PROF
   int y,len, x, dy, skip_i;
   int row;
   uchar *dest, *destcore;
   fix dudx,dvdx, u_value, v_value, istart;
   SpanItem *si, *end;

   memcpy(tmap_data, rpi->tm_dat, sizeof(tmap_data));

   dudx = fast_float_to_fix(tmap_data[3]);
   dvdx = fast_float_to_fix(tmap_data[4]);

   pt_tmap_ptr  = rpi->bits;
   pt_tmap_mask = (rpi->bm->h-1) * 256 + (rpi->bm->w-1);
   
   ptmap_setup(rpi->bm);

   y = rpi->y;
   si = rpi->span_info;
   end = si + rpi->count;

   row = grd_bm.row;
   destcore = grd_bm.bits + y * row;

   skip_i = 0;

   while (si < end) {
      len = si->len;
      if (len == 0) {
         // if we get a 0 length thing,
         // that means we should skip vertically
         // by more than our normally allowed limit (255)
         // by using this item solely for skipping
         ++si;
         dy = si->start_x;
         goto skip_y;
      }

      x = si->start_x;

      // if length == 255, then we've encoded
      // the real length in the next one
      if (len == 255) {
         ++si;
         len = si->start_x;
      }
      dy = si->delta_y;
         
      dest = destcore + x;

      if (!skip_i) {
         int mylen = xdata[y][1] - xdata[y][0];
         idata[y][1] = fix_mul((idata[y][1] - idata[y][0]) >> 4, reciprocal_table_24[mylen] >> 4);
         if (idata[y][1] < 0) ++idata[y][1];
      }

      if (x == xdata[y][0])
         istart = idata[y][0];
      else
         istart = idata[y][0] + idata[y][1]*(x - xdata[y][0]);

      if (x == xdata[y][0]) {
         u_value = uvdata[y][0];
         v_value = uvdata[y][1];
      } else {
         int delta = x - xdata[y][0];
         u_value = uvdata[y][0] + delta * dudx;
         v_value = uvdata[y][1] + delta * dvdx;
      }

      ptmap_do_lit_run(dest, len, u_value, v_value,
          dudx, dvdx, istart, idata[y][1]);

      if (!dy)
         skip_i = 1;
      else if (dy == 1) {
         destcore += row;
         skip_i = 0;
      } else {
        skip_y:
         destcore += row*dy;
         skip_i = 0;
      }
      y += dy;
      ++si;
   }
   END_PROF;
}

void render_rpi_linear_unlit(RenderPolyInfo *rpi)
{  PROF
   int y,len, x, dy;
   int row;
   uchar *dest, *destcore;
   fix dudx,dvdx, u_value, v_value;
   SpanItem *si, *end;

   memcpy(tmap_data, rpi->tm_dat, sizeof(tmap_data));

   dudx = fast_float_to_fix(tmap_data[3]);
   dvdx = fast_float_to_fix(tmap_data[4]);

   pt_tmap_ptr  = rpi->bits;
   pt_tmap_mask = (rpi->bm->h-1) * 256 + (rpi->bm->w-1);
   
   ptmap_setup(rpi->bm);

   y = rpi->y;
   si = rpi->span_info;
   end = si + rpi->count;

   row = grd_bm.row;
   destcore = grd_bm.bits + y * row;

   while (si < end) {
      len = si->len;
      if (len == 0) {
         // if we get a 0 length thing,
         // that means we should skip vertically
         // by more than our normally allowed limit (255)
         // by using this item solely for skipping
         ++si;
         dy = si->start_x;
         goto skip_y;
      }

      x = si->start_x;

      // if length == 255, then we've encoded
      // the real length in the next one
      if (len == 255) {
         ++si;
         len = si->start_x;
      }
      dy = si->delta_y;
         
      dest = destcore + x;

      if (x == xdata[y][0]) {
         u_value = uvdata[y][0];
         v_value = uvdata[y][1];
      } else {
         int delta = x - xdata[y][0];
         u_value = uvdata[y][0] + delta * dudx;
         v_value = uvdata[y][1] + delta * dvdx;
      }

      ptmap_do_run(dest, len, u_value, v_value, dudx, dvdx);

      if (dy == 1) {
         destcore += row;
      } else if (dy) {
        skip_y:
         destcore += row*dy;
      }
      y += dy;
      ++si;
   }
   END_PROF;
}

void post_render_polys(void)
{  PROF
   RenderPolyInfo *rpi = rpi_head, *next;
   while (rpi) {
      render_rpi_unlit(rpi);
      next = rpi->next;
      Free(rpi->span_info);
      Free(rpi);
      rpi = next;
   }
   rpi_head = 0;
   rpi_tail = &rpi_head;
   END_PROF;
}

#define SLIST_BUFFER_SIZE  8192

SpanItem slist_buffer[SLIST_BUFFER_SIZE];
int start_y;
int last_y;
SpanItem *slist;
SpanItem *snext;
int slist_max;
int slist_count;

static void grow(void)
{
   // check if this is the very first run, which is a bit special
   if (slist_count == 0) {
      slist_max = SLIST_BUFFER_SIZE;
      slist = slist_buffer;
   } else {
      void *old = slist;
      slist_max *= 2;
      // Damn you realloc!
      slist = Malloc(sizeof(SpanItem) * slist_max);
      memcpy(slist, old, sizeof(SpanItem) * slist_count);
      if (old != slist_buffer)
         Free(old);
   }
   snext = slist + slist_count;
}

static void *malloc_slist(void)
{
   SpanItem *s = Malloc(sizeof(SpanItem) * slist_count);
   memcpy(s, slist, sizeof(SpanItem) * slist_count);
   return s;
}

static void free_slist(SpanItem *s)
{
   if (s != slist_buffer)
      Free(s);
}

extern int stat_num_drawn_pixels, stat_num_clipped_pixels;
extern int stat_num_transp_pixels;

#ifdef UNCLIPPED_ASM

  #define add_unclipped_run(a,b,c)  pt_add_unclipped_run_asm(a,b,c)

#else

void add_unclipped_run(int x0, int x1, int y)
{
   int len;

#ifdef DBG_ON
   if (x0 == x1) { mprintf("x0 = x1 = %d\n", x0); return; }
#endif

#if 0
   if (slist_count == slist_max)
      grow();
#endif

   // compute delta y and patch over previous
   if (slist_count)
      snext[-1].delta_y = y - last_y;
   else
      start_y = y;

   last_y = y;

   len = x1-x0;
   stat_num_drawn_pixels += len;

   if (len > 254) {
      snext->start_x = x0;
      snext->len = 255; // len == 255 means long length in next one
      ++slist_count;
      ++snext;
#if 0
      if (slist_count == slist_max)
         grow();
#endif
      snext->start_x = len;
   } else {
      snext->start_x = x0;
      snext->len = len;
   }

   ++slist_count;
   ++snext;
}

#endif

typedef unsigned short xloc;
typedef struct foo
{
   xloc start_x;
   xloc end_x;
   struct foo *next;
} RunClipData;

#define CLIP_DATA_HEIGHT   768
#define CLIP_DATA_TOTAL    (CLIP_DATA_HEIGHT * 8)

RunClipData clip_data[CLIP_DATA_TOTAL];  // allocation pool
RunClipData *clip_alloc, *clip_alloc_end = &clip_data[CLIP_DATA_TOTAL - CLIP_DATA_HEIGHT];

RunClipData *clip[CLIP_DATA_HEIGHT];

void reset_clip(int x0, int x1, int max_y)
{  PROF
   int i;
   clip_alloc = clip_data;
   for (i=0; i < max_y; ++i) {
      clip_alloc->start_x = x0;
      clip_alloc->end_x = x1;
      clip_alloc->next = NULL;
      clip[i] = clip_alloc++;
   }
   END_PROF;
}

#ifdef CLIPPED_ASM

  #define add_clipped_run(a,b,c)     \
     pt_add_clipped_run_asm(&clip[c], a, b, c)

#else

void add_clipped_run(int x0, int x1, int y)
{  PROF
   RunClipData *z, **last;
   last = &clip[y];
   z = *last;
   if (x0 < x1)
      stat_num_clipped_pixels += x1 - x0;

   while (z) {
      if (x1 <= z->start_x) {
         END_PROF;
         return;   // ended before this run
      }

      if (x0 < z->end_x) {
         // we are visible... there are four cases:
         //   we fill this run
         //   we fit against the left side
         //   we fit against the right side
         //   we're in the middle
         if (x0 <= z->start_x) {
            // we fit against the left at least
            if (x1 >= z->end_x) {
               add_unclipped_run(z->start_x, z->end_x, y);
               // delete the run
               *last = z->next;
               z = z->next;
            } else {
               // we clipped against the left edge
               add_unclipped_run(z->start_x, x1, y);
               z->start_x = x1;
               END_PROF;
               return;
            }
         } else {
            if (x1 >= z->end_x) {
               // we clipped against the right edge
               add_unclipped_run(x0, z->end_x, y);
               z->end_x = x0;
               last = &z->next;
               z = z->next;
            } else {
               // we added in the middle
               add_unclipped_run(x0, x1, y);
               clip_alloc->next = z->next;
               clip_alloc->end_x = z->end_x;
               clip_alloc->start_x = x1;

               z->next = clip_alloc++;
               z->end_x = x0;
               END_PROF;
               return;
            }
         }
      } else {
         last = &z->next;
         z = z->next;
      }
   }
   END_PROF;
}

#endif

void clipped_run(int x0, int x1, int y)
{  PROF
   RunClipData *z, **last;
   int n = stat_num_drawn_pixels;

   last = &clip[y];
   z = *last;
   while (z) {
      if (x1 <= z->start_x) {
         goto done;
      }
      if (x0 < z->end_x) {
         // we are visible... there are four cases:
         //   we fill this run
         //   we fit against the left side
         //   we fit against the right side
         //   we're in the middle
         if (x0 <= z->start_x) {
            // we fit against the left at least
            if (x1 >= z->end_x) {
               add_unclipped_run(z->start_x, z->end_x, y);
            } else {
               // we clipped against the left edge
               add_unclipped_run(z->start_x, x1, y);
               goto done;
            }
         } else {
            if (x1 >= z->end_x) {
               // we clipped against the right edge
               add_unclipped_run(x0, z->end_x, y);
            } else {
               // we added in the middle
               add_unclipped_run(x0, x1, y);
               goto done;
            }
         }
      }
      z = z->next;
   }
  done:
   stat_num_transp_pixels += (stat_num_drawn_pixels - n);
   stat_num_drawn_pixels = n;   
   END_PROF;
}

void fake_render_perspective(grs_bitmap *b, int n, r3s_phandle *vp)
{  PROF
   RenderPolyInfo *rpi;
   bool opaque;
   int i,j;

   // no more memory for clipping, so punt
   if (clip_alloc > clip_alloc_end) {
      Warning(("fake_render_perspective: scene too complex for spanclip\n"));
      return;
   }

   reset_scan_buffer();

   j = n-1;
   for (i=0; i < n; ++i) {
      scan_convert(vp[i], vp[j]);
      j = i;
   }

   // 0-height poly
   if (y_min >= y_max)
      return;

   if (y_min < 0) {
      Warning(("Polygon off top of screen.\n"));
      return;
   }

   if (y_max >= MAX_HEIGHT) {
      Warning(("Polygon off bottom of max-sized screen.\n"));
      return;
   }

   // now clip it against the span tables
   // and convert it to spans

   opaque = TRUE;
   if (b->type == BMT_TLUC8) opaque = FALSE;
   else if (b->flags & BMF_TRANS) opaque = FALSE;

   slist = 0;
   slist_max = slist_count = 0;
   grow();

   if (opaque) {
      for (i=y_min; i < y_max; ++i)
         if (xdata[i][0] < xdata[i][1])
            add_clipped_run(xdata[i][0], xdata[i][1], i);
   } else {
      for (i=y_min; i < y_max; ++i)
         if (xdata[i][0] < xdata[i][1])
            clipped_run(xdata[i][0], xdata[i][1], i);
   }

   if (!slist_count) { ++stat_num_polys_clipped_away; return; }
   
   snext[-1].delta_y = 0;

   // now allocate the drawing structure for it
   rpi = Malloc(sizeof(RenderPolyInfo));
   rpi->bm = b;
   rpi->bits = b->bits;
   memcpy(rpi->tm_dat, tmap_data, sizeof(rpi->tm_dat));
   rpi->y = start_y;
   rpi->count = slist_count;
   rpi->span_info = slist;

   // if we're not transparent or translucent,
   // we can render it right now!

   if (opaque) {
      render_rpi_unlit(rpi);
      free_slist(rpi->span_info);
      Free(rpi);
   } else {
      // add to head
      if (slist == slist_buffer)
         rpi->span_info = malloc_slist();
      rpi->next = rpi_head;
      rpi_head = rpi;
   }
   END_PROF;
}

void fake_render_linear_tri(grs_bitmap *b, r3s_phandle *vp)
{  PROF
   RenderPolyInfo *rpi;
   bool opaque;
   int i;

   // no more memory for clipping, so punt
   if (clip_alloc > clip_alloc_end) {
      Warning(("fake_render_perspective: scene too complex for spanclip\n"));
      return;
   }

   reset_scan_buffer();

   compute_duv_tri_full(vp);

   scan_convert_uv(vp[0], vp[2]);
   scan_convert_uv(vp[1], vp[0]);
   scan_convert_uv(vp[2], vp[1]);

   // 0-height poly
   if (y_min >= y_max)
      return;

#ifdef DBG_ON
   if (y_min < 0) {
      Warning(("Polygon off top of screen.\n"));
      return;
   }

   if (y_max >= MAX_HEIGHT) {
      Warning(("Polygon off bottom of max-sized screen.\n"));
      return;
   }
#endif

   // now clip it against the span tables
   // and convert it to spans

   opaque = TRUE;
   if (b->type == BMT_TLUC8) opaque = FALSE;
   else if (b->flags & BMF_TRANS) opaque = FALSE;

   // at the moment, we can't handle non-opaque
   if (!opaque)
      return;

   slist = 0;
   slist_max = slist_count = 0;
   grow();

   if (opaque) {
      for (i=y_min; i < y_max; ++i)
         if (xdata[i][0] < xdata[i][1])
            add_clipped_run(xdata[i][0], xdata[i][1], i);
   } else {
      for (i=y_min; i < y_max; ++i)
         if (xdata[i][0] < xdata[i][1])
            clipped_run(xdata[i][0], xdata[i][1], i);
   }

   // quick out if no spans
   if (!slist_count) return;
   
   snext[-1].delta_y = 0;

   // now allocate the drawing structure for it
   rpi = Malloc(sizeof(RenderPolyInfo));
   rpi->bm = b;
   rpi->bits = b->bits;
   memcpy(rpi->tm_dat, tmap_data, sizeof(rpi->tm_dat));
   rpi->y = start_y;
   rpi->count = slist_count;
   rpi->span_info = slist;

   // if we're not transparent or translucent,
   // we can render it right now!

   if (opaque) {
      if (poly_lit)
         render_rpi_linear(rpi);
      else
         render_rpi_linear_unlit(rpi);
      free_slist(rpi->span_info);
      Free(rpi);
   } else {
      // add to head
      // we need to mark it as linear not perspective!
      if (slist == slist_buffer)
         rpi->span_info = malloc_slist();
      rpi->next = rpi_head;
      rpi_head = rpi;
   }
   END_PROF;
}

bool portal_clip = TRUE;
extern bool use_non_per;

// my clipper, which handles octagon clipping
extern int clip2d_clip_polygon(int n, ClipData *c);

bool write_combine;

// render polygon of n vertices using texture info in tmdata
// and polygon in poly

void render_poly_perspective(grs_bitmap *b, int n, r3s_phandle *vp, bool lit)
{  PROF
   extern int pt_preload;
   extern double u_offset, v_offset;

   poly_lit = lit;

   pt_preload = write_combine;

   pt_tmap_ptr  = b->bits;
   pt_tmap_mask = (b->h-1) * 256 + (b->w-1);

   * (int *) &u_offset = fix_make(2, 0);
   * (int *) &v_offset = fix_make(2, 0);

   if (span_clip)
      fake_render_perspective(b, n, vp);
   else
      do_perspective_poly(b, n, vp);
   END_PROF;
}

// While the previous routine assumes that the given texture has an
// unrendered 2-texel border, this one does not.
void render_poly_perspective_uv(grs_bitmap *b, int n, r3s_phandle *vp,
                                fix u, fix v, bool lit)
{  PROF
   extern int pt_preload;
   extern double u_offset, v_offset;

   poly_lit = lit;

   pt_preload = write_combine;

   pt_tmap_ptr  = b->bits;
   pt_tmap_mask = (b->h-1) * 256 + (b->w-1);

   * (int *) &u_offset = u;
   * (int *) &v_offset = v;

   if (span_clip)
      fake_render_perspective(b, n, vp);
   else
      do_perspective_poly(b, n, vp);
   END_PROF;
}

// must have valid (u,v) values!

void render_poly_affine_core(grs_bitmap *b, int n, r3s_phandle *vp)
{
   r3s_phandle tri[3];
   int i;

   // trifan it

   tri[0] = vp[0];
   for (i=2; i < n; ++i) {
      tri[1] = vp[i-1];
      tri[2] = vp[i];
      if (span_clip) {
         fake_render_linear_tri(b, tri);
      } else
         do_linear_tri(b, tri);
   }
}

void render_poly_affine(grs_bitmap *b, int n, r3s_phandle *vp, bool lit)
{  PROF
   poly_lit = lit;

   pt_tmap_ptr  = b->bits;
   pt_tmap_mask = (b->h-1) * 256 + (b->w-1);

   render_poly_affine_core(b, n, vp);
   END_PROF;
}

void render_poly_persp_affine(grs_bitmap *b, int n, r3s_phandle *vp, bool lit)
{  PROF
   int i;

   // convert a perspective polygon to affine
   for (i=0; i < n; ++i) {
      double sx = vp[i]->grp.sx / 65536.0;
      double sy = vp[i]->grp.sy / 65536.0;
      double ic = 1/(tmap_data[2] + tmap_data[5]*sx + tmap_data[8]*sy);

      vp[i]->grp.u = (tmap_data[0]+tmap_data[3]*sx + tmap_data[6]*sy)*ic/65536
           + 2.0;
      vp[i]->grp.v = (tmap_data[1]+tmap_data[4]*sx + tmap_data[7]*sy)*ic/65536
           + 2.0;
   }

   fdc = 0;
   gdc = 0;

   render_poly_affine(b, n, vp, lit);
   END_PROF;
}
