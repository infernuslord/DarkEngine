// $Header: r:/t2repos/thief2/src/portal/ptmapper.h,v 1.5 2000/01/29 13:37:32 adurant Exp $
#pragma once

extern void pt_scan_convert(fix x, int *p, fix dx, int count);
extern void pt_asm_outer_loop(double *uv, uchar *dest, int *xdata, int height);

typedef struct
{
   fix x,dx;
   fix u,v;
   fix du,dv;
   fix du2,dv2;
} uv_scan_info;

extern void pt_scan_convert_uv(uv_scan_info *p, int *xdata, fix *uvdata, int count);

extern void pt_render_rpi_unlit_asm(void *span_info, double *abc, uchar *dest, void *span_end);

extern void pt_add_unclipped_run_asm(int x0, int x1, int y);
extern void pt_add_clipped_run_asm(void *span_last, int x0, int x1, int y);
