/*
 * $Source: x:/prj/tech/dossrc/dpmi/RCS/dpmi.h $
 * $Revision: 1.14 $
 * $Author: TOML $
 * $Date: 1996/11/05 16:44:57 $
 *
 * Watcom C/386 inline dpmi routines.
 */

#ifndef __DPMI_H
#define __DPMI_H
#include <i86.h>

/* dpmi memory block descriptor. */
typedef struct {
   union {
      long h;        /* memory block handle */
      short d;       /* block descriptor */
   };
   void *p;          /* pointer to memory */
} dpmis_block;

/* dpmi host information descriptor. */
typedef struct {
   char ver_maj;     /* major version nubmer */
   char ver_min;     /* minor version */
   ushort flags;     /* host status; DPMIF_XXX */
   char cpu;         /* processor type (2-5) */
   char pic_mbase;   /* pic master base int */
   char pic_sbase;   /* pic slave base int */
   char pad;         /* pad to 8 bytes */
} dpmis_info;

/* dpmi memory information descriptor. */
typedef struct {
   long max_free;    /* largest available free block in bytes */
   long max_unlock;  /* maximum unlocked page allocation in pages */
   long max_lock;    /* maximum locked page allocation in pages */
   long lin_adr;     /* linear address space size in pages */
   long pg_unlock;   /* total number of unlocked pages */
   long pg_free;     /* total number of free pages */
   long pg_phys;     /* total number of physical pages */
   long lin_free;    /* free linear address space in pages */
   long swap_size;   /* size of paging file/partition in pages */
   long pad[3];
} dpmis_mem;

/* format of real mode register structure for DPMI calls. */
typedef struct {
   long edi;
   long esi;
   long ebp;
   long pad1;
   long ebx;
   long edx;
   long ecx;
   long eax;
   ushort flags;
   ushort es;
   ushort ds;
   ushort fs;
   ushort gs;
   ushort ip;
   ushort cs;
   ushort sp;
   ushort ss;
   ushort pad2;    // pads to mult of 4 size
} dpmis_reg;

/* all DPMI calls exit with the carry set if there is an error.  if
   there is an error, an extended error code is sometimes returned in
   ax.  here are the definitions for the extended error codes that may
   be returned by the DPMI calls defined in this file. */
#define DPMIE_UNSUP_FUNC      8001h    /* unsupported function */
#define DPMIE_INVL_STATE      8002h    /* invalid state */
#define DPMIE_SYS_INTEG       8003h    /* system integrity */
#define DPMIE_DEADLOCK        8004h    /* deadlock */
#define DPMIE_REQ_CANCEL      8005h    /* request cancelled */
#define DPMIE_RES_UNAVAUL     8010h    /* resource unavailable */
#define DPMIE_DESC_UNAVAIL    8011h    /* descriptor unavailable */
#define DPMIE_LIN_UNAVAIL     8012h    /* linear address unavailable */
#define DPMIE_PHYS_UNAVAIL    8013h    /* physical memory unavailable */
#define DPMIE_BACK_UNAVAIL    8014h    /* backing store unavailable */
#define DPMIE_CALL_UNAVAIL    8015h    /* callback unavailable */
#define DPMIE_HAND_UNAVAIL    8016h    /* handle unavailable */
#define DPMIE_LOCK_COUNT      8017h    /* lock count exceeded */
#define DPMIE_RES_OWNED       8018h    /* resource owned exclusively */
#define DPMIE_RES_SHARE       8019h    /* resource owned shared */
#define DPMIE_INVL_VALUE      8021h    /* invalid value */
#define DPMIE_INVL_SELECTOR   8022h    /* invalid selector */
#define DPMIE_INVL_HANDLE     8023h    /* invalid handle */
#define DPMIE_INVL_CALL       8024h    /* invalid callback */
#define DPMIE_INVL_LINADR     8025h    /* invalid linear address */
#define DPMIE_INVL_REQ        8026h    /* request not supported */

/* meaning of the flags field of the dpmis_info structure. */
#define DPMIF_BITNESS 1  /* 0=16-bit; 1=32-bit */
#define DPMIF_REAL    2  /* 0=virtual 86 mode used for interrupts */
                         /* 1=real mode used for interrupts */
#define DPMIF_VM      4  /* 0=no virtual memory; 1=virtual memory */

/* meaning of access rights word for descriptors. */
#define DPMIA_ACCESSED    0x0001  /* 1=selector has been loaded */
#define DPMIA_DATA_WRITE  0x0002  /* 1=data seg is writable */
#define DPMIA_CODE_READ   0x0002  /* 1=code seg is readable */
#define DPMIA_EXP_DOWN    0x0004  /* 1=data seg expands down */
#define DPMIA_CONFORM     0x0004  /* 1=code seg is conforming---dpmi */
                                  /* does not allow conforming segs */
#define DPMIA_CODE        0x0008  /* 0=seg is data; 1=seg is code */
#define DPMIA_APPLICAT    0x0010  /* 0=system seg; 1=app seg---dpmi */
                                  /* does not allow system segs */
#define DPMIA_DPL_MASK    0x0060  /* privilege level of seg */
#define DPMIA_DPL_SHIFT   5       /* starts at bit 5 */
#define DPMIA_PRESENT     0x0080  /* 0=absent; 1=present */
#define DPMIA_HLIM_MASK   0x0f00  /* bits 16-19 of limit */
#define DPMIA_HLIM_SHIFT  0       /* high limit starts at bit 16 */
#define DPMIA_AVAIL       0x1000  /* available for system use */
                                  /* bit 11 must be 0 */
#define DPMIA_32BIT       0x4000  /* 0=16-bit; 1=32-bit */
#define DPMIA_GRAN        0x8000  /* 0=byte; 1=page */

/* extract real mode segment or offset from a linear address.  this
   depends on an indentity mapping for the first megabyte. */
#define dpmi_real_seg(p) ((ushort)(((ulong)p)>>4))
#define dpmi_real_off(p) ((ushort)(((ulong)p)&0xf))

/* convert a real mode pointer to a linear address. */
#define dpmi_r2p(p) ((((ulong)p&0xffff0000)>>12)+((ulong)p&0xffff))

/* convert a linear address to a real mode __far pointer.  this only
   works for bottom megabyte. */
#define dpmi_p2r(p) ((((ulong)p&0xffff0)<<12)|((ulong)p&0xf))

/* make a real mode __far pointer from a segment and an offset. */
#define dpmi_real_fp(seg,off) ((((ulong)seg)<<16)|((ulong)off)

/* convert __far pointer to near.  returns linear address of pointer. */
#define dpmi_f2n(p) (p!=0 ? dpmi_get_base(FP_SEG(p))+FP_OFF(p) : NULL)

/* allocates n ldt descriptors.  returns selector for first one or
   0xffff if there is an error. */
ushort dpmi_alloc_desc(int n);
#pragma aux dpmi_alloc_desc=\
   "xor eax,eax" \
   "int 31h" \
   "jnc dad_ok" \
   "sbb eax,eax" \
"dad_ok:" \
   "and eax,00000ffffh" \
   parm [cx] \
   modify exact [eax];

/* frees a previously allocated ldt descriptor.  blocks of descriptors
   must be freed one at a time.  returns 0 if all went well, otherwise
   return dpmi error code. */
int dpmi_free_desc(ushort sel);
#pragma aux dpmi_free_desc=\
   "xor eax,eax" \
   /* clear any segment registers that have selector of descriptor */ \
   /* to be freed.  dpmi 1.0 specifies that the host must do this, */ \
   /* but dos4gw does it in the gp fault handler, which may have be */ \
   /* replaced.  so we do it here. */ \
   "mov cx,ds" \
   "cmp cx,bx" \
   "jne ds_ok" \
   "mov ds,ax" \
"ds_ok:" \
   "mov cx,es" \
   "cmp cx,bx" \
   "jne es_ok" \
   "mov es,ax" \
"es_ok:" \
   "mov cx,fs" \
   "cmp cx,bx" \
   "jne fs_ok" \
   "mov fs,ax" \
"fs_ok:" \
   "mov cx,gs" \
   "cmp cx,bx" \
   "jne gs_ok" \
   "mov gs,ax" \
"gs_ok:" \
   "mov al,1" \
   "int 31h" \
   "jc dfd_err" \
   "xor eax,eax" \
"dfd_err:" \
   parm [bx] \
   modify exact [eax ecx];

/* converts a real mode segment into a descriptor usable by protected
   mode code.  the descriptor returned will have a limit of 64k and
   cannot be modified or freed.  returns a selector for the new
   descriptor or 0xffff if there is an error. */
ushort dpmi_seg_to_desc(ushort seg);
#pragma aux dpmi_seg_to_desc=\
   "xor eax,eax" \
   "mov al,2" \
   "int 31h" \
   "jnc dstd_ok" \
   "sbb eax,eax" \
"dstd_ok:" \
   "and eax,0ffffh" \
   parm [bx] \
   modify exact [eax];

/* returns the increment value for selector arrays. */
ushort dpmi_get_sel_inc(void);
#pragma aux dpmi_get_sel_inc=\
   "xor eax,eax" \
   "mov al,3" \
   "int 31h" \
   "and eax,0ffffh" \
   modify exact [eax];

/* returns the linear base address of the descriptor with the given
   selector or 0xffffffff if there is an error. */
ulong dpmi_get_base(ushort sel);
#pragma aux dpmi_get_base=\
   "xor eax,eax" \
   "mov al,6" \
   "int 31h" \
   "jnc dgb_ok" \
   "sbb ecx,ecx" \
   "jmp dgb_err" \
"dgb_ok:" \
   "shl ecx,10h" \
   "or cx,dx" \
"dgb_err:" \
   parm [bx] \
   modify exact [ecx edx] \
   value [ecx];

/* sets the linear base address of the descriptor with the given
   selector to the given base.  returns 0 if all is well, nonzero if
   there's an error. */
int dpmi_set_base(ushort sel,ulong base);
#pragma aux dpmi_set_base=\
   "xor eax,eax" \
   "mov al,7" \
   "mov ecx,edx" \
   "shr ecx,10h" \
   "int 31h" \
   "xor eax,eax" \
   "jnc dsb_ok" \
   "dec eax" \
"dsb_ok:" \
   parm [bx] [edx] \
   modify exact [eax ecx];

// Old watcom (9.5)  thinks lsl is r32,r32;
// New watcom (10.0) thinks lsl is r32,r16.
//
//   According to intel reference and some other dos book,
// old watcom is correct.  Kinda makes you wonder what those
// guys up in Ontario had on there mind when they redid that
// new wacky inline assembler.

// __WATCOMC__ returns the version number * 100
#if __WATCOMC__ < 1000
/* gets the limit for the descriptor with the given selector. */
ulong dpmi_get_limit(ushort sel);
#pragma aux dpmi_get_limit=\
   "lsl eax,edx" \
   parm [dx] \
   modify exact [eax];
#else
ulong dpmi_get_limit(ushort sel);
#pragma aux dpmi_get_limit=\
   "lsl eax,dx" \
   parm [dx] \
   modify exact [eax];
#endif

/* sets the limit for the descriptor with the given selector.  returns
   0 if all is well, nonzero if error.  limits greater than 1meg must
   page aligned. */
int dpmi_set_limit(ushort sel,ulong limit);
#pragma aux dpmi_set_limit=\
   "xor eax,eax" \
   "mov al,8" \
   "mov ecx,edx" \
   "shr ecx,10h" \
   "int 31h" \
   "jc dsl_err" \
   "xor eax,eax" \
"dsl_err:" \
   parm [bx] [edx] \
   modify exact [eax ecx];

/* returns the access rights from the descriptor with the specified
   selector.  returned value is bits 40-55 of the descriptor shifted
   down to bits 0-15. */
ushort dpmi_get_desc_access(ushort sel);
#pragma aux dpmi_get_desc_access=\
   "lar eax,edx" \
   "shr eax,8" \
   parm [dx] \
   modify exact [eax];

/* sets the access rights bits of the descriptor (bits 40-55) with the
   specified selector to bits 0-15 of the access argument with the
   following exceptions.  code segments must be conforming, the system/
   application bit must be set to 1 (indicating application), and the
   high bits of the segment limit are ignored.  returns 0 if all goes
   well, -1 if there is an error. */
int dpmi_set_desc_access(ushort sel,ushort access);
#pragma dpmi_set_desc_access=\
   "xor eax,eax" \
   "mov al,9" \
   "int 31h" \
   "sbb eax,eax" \
   parm [bx cx] \
   modify exact [eax];

/* creates an alias ldt descriptor for the given selector.  returns the
   selector for new descriptor or 0xffff if there's an error. */
ushort dpmi_create_alias(ushort sel);
#pragma aux dpmi_create_alias=\
   "xor eax,eax" \
   "mov al,00ah" \
   "int 31h" \
   "jnc dca_ok" \
   "sbb eax,eax" \
"dca_ok:" \
   "and eax,00000ffffh" \
   parm [bx] \
   modify exact [eax];

/* allocates specified number of paragraphs of dos memory.  places
   base selector and pointer in structure pointed to by b.  returns 0
   if all went well, otherwise dos error code is returned. */
int dpmi_alloc_dos_mem(dpmis_block *b,int pars);
#pragma aux dpmi_alloc_dos_mem=\
   "mov eax,0100h" \
   "int 31h" \
   "jc dadm_err" \
   "mov [ecx],edx" \
   "and eax,00000ffffh" \
   "shl eax,4" \
   "mov 4[ecx],eax" \
   "xor eax,eax" \
"dadm_err:" \
   parm [ecx] [ebx] \
   modify exact [eax edx];

/* frees previously allocated dos memory block.  returns 0 if all went
   well, otherwise returns dos error. */
int dpmi_free_dos_mem(dpmis_block *b);
#pragma aux dpmi_free_dos_mem=\
   "mov edx,[eax]" \
   "mov eax,0101h" \
   "int 31h" \
   "jc dfdm_err" \
   "xor eax,eax" \
"dfdm_err:" \
   parm [eax] \
   modify exact [eax edx];

/* returns a flat-mode pointer to the real mode interrupt handler for
   int n.  pointer returned can be used in protected mode. */
void *dpmi_get_real_int_ptr(uchar n);
#pragma aux dpmi_get_real_int_ptr=\
   "mov eax,0200h" \
   "int 31h" \
   "and ecx,0ffffh" \
   "shl ecx,4h" \
   "and edx,0ffffh" \
   "add ecx,edx" \
   parm [bl] \
   modify exact [eax ecx dx] \
   value [ecx];

/* returns a real-mode __far pointer to the real mode interrupt handler
   for int n.  format of pointer is 16 bit segment:16 bit offset. */
long dpmi_get_real_int_vec(uchar n);
#pragma aux dpmi_get_real_int_vec=\
   "mov eax,0200h" \
   "int 31h" \
   "shl ecx,10h" \
   "and edx,0ffffh" \
   "or ecx,edx" \
   parm [bl] \
   modify exact [eax ecx dx] \
   value [ecx];

/* sets real mode interrupt handler for int n to h. */
int dpmi_set_real_int_vec(uchar n,long h);
#pragma aux dpmi_set_real_int_vec=\
   "mov eax,0201h" \
   "mov edx,ecx" \
   "shr ecx,10h" \
   "int 31h" \
   "xor eax,eax" \
   parm [bl] [ecx]\
   modify exact [eax ecx edx];

/* returns __far pointer to exception handler for int n. */
void __far *dpmi_get_except_vec(uchar n);
#pragma aux dpmi_get_except_vec=\
   "mov eax,0202h" \
   "int 31h" \
   "jnc dgev_ok" \
   "xor ecx,ecx" \
   "xor edx,edx" \
"dgev_ok:" \
   parm [bl] \
   modify exact [eax cx edx] \
   value [cx edx];

/* sets exception vector for int n to __far pointer h.  returns 0 if all
   went well or dpmi error code. */
int dpmi_set_except_vec(uchar n,void __far *h);
#pragma aux dpmi_set_except_vec=\
   "mov eax,0203h" \
   "int 31h" \
   "jc gsev_err" \
   "xor eax,eax" \
"gsev_err:" \
   parm [bl] [cx edx] \
   modify exact [eax];

/* returns __far pointer to the protected mode interrupt handler for
   int n. */
void __far *dpmi_get_prot_int_vec(uchar n);
#pragma aux dpmi_get_prot_int_vec=\
   "mov eax,0204h" \
   "int 31h" \
   parm [bl] \
   modify exact [cx edx] \
   value [cx edx];

/* sets protected mode interrupt handler for int n to h.  returns 0 if
   all went well or dpmi error code. */
int dpmi_set_prot_int_vec(uchar n,void __far *h);
#pragma aux dpmi_set_prot_int_vec=\
   "mov eax,0205h" \
   "int 31h" \
   "jc dspv_err" \
   "xor eax,eax" \
"dspv_err:" \
   parm [bl] [cx edx] \
   modify exact [eax];

/* signals int n in real mode with registers as given by r.  returns
   result registers in r, 0 if no error, dpmi error code if error. */
int dpmi_real_interrupt(uchar n,dpmis_reg *r);
#pragma aux dpmi_real_interrupt=\
   "mov eax,0300h" \
   "xor bh,bh" \
   "xor ecx,ecx" \
   "int 31h" \
   "jc dri_err" \
   "xor eax,eax" \
"dri_err:" \
   parm [bl] [edi] \
   modify exact [eax ecx];

/* get version number as well as assorted other information into info
   structure.  returns a pointer to the info structure. */
dpmis_info *dpmi_get_version(dpmis_info *info);
#pragma aux dpmi_get_version=\
   "mov eax,0400h" \
   "int 31h" \
   "mov 0[esi],ah" \
   "mov 1[esi],al" \
   "mov 2[esi],bx" \
   "mov 4[esi],cl" \
   "mov 5[esi],dh" \
   "mov 6[esi],dl" \
   parm [esi] \
   modify exact [eax ebx ecx edx];

ushort dpmi_get_capabilities(void *buf);
#pragma aux dpmi_get_capabilities=\
   "mov eax,0401h" \
   "int 31h" \
   "jnc dgc_ok" \
   "sbb ax,ax" \
"dgc_ok:" \
   parm [edi] \
   modify exact [eax ecx edx];

/* fills in a dpmi memory info structure with the current free memory
   information.  returns pointer to descriptor passed in or NULL if there
   was an error. */
dpmis_mem *dpmi_free_mem_info(dpmis_mem *m);
#pragma aux dpmi_free_mem_info=\
   "mov ax,ds" \
   "mov es,ax" \
   "mov ax,0500h" \
   "int 31h" \
   "sbb eax,eax" \
   "not eax" \
   "and eax,edi" \
   parm [edi] \
   modify exact [eax edi];

/* locks a linear region of memory from being paged by dpmi hosts that
   support virtual memory.  returns 0 if all went well, otherwise dpmi
   error code is returned. */
int dpmi_lock_lin_region(void *base,ulong n);
#pragma aux dpmi_lock_lin_region=\
   "mov eax,0600h" \
   "mov ecx,ebx" \
   "shr ebx,10h" \
   "and ecx,00000ffffh" \
   "mov edi,esi" \
   "shr esi,10h" \
   "and edi,00000ffffh" \
   "int 31h" \
   "jc dlb_err" \
   "xor eax,eax" \
"dlb_err:" \
   parm [ebx] [esi] \
   modify exact [eax ebx ecx esi edi];

/* unlocks a previously locked linear region of memory.  returns 0 if
   all went well, otherwise returns dpmi error code. */
int dpmi_unlock_lin_region(void *base,ulong n);
#pragma aux dpmi_unlock_lin_region=\
   "mov eax,0601h" \
   "mov ecx,ebx" \
   "shr ebx,10h" \
   "and ecx,00000ffffh" \
   "mov edi,esi" \
   "shr esi,10h" \
   "and edi,00000ffffh" \
   "int 31h" \
   "jc dub_err" \
   "xor eax,eax" \
"dub_err:" \
   parm [ebx] [esi] \
   modify exact [eax ebx ecx esi edi];

/* maps a physical address to a linear address.  Returns 0 if all
   went well, otherwise returns the dpmi error code. */
int dpmi_map_physical_mem(uchar *physAddr,ulong size,uchar **lineMemPtr);
#pragma aux dpmi_map_physical_mem =    \
   "mov  ebx,ecx"                      \
   "mov  esi,edi"                      \
   "shr  ebx,10h"                      \
   "shr  esi,10h"                      \
   "mov  eax,0800h"                    \
   "int  31h"                          \
   "jc   dmp_err"                      \
   "shl  ebx,10h"                      \
   "mov  bx,cx"                        \
   "mov  [edx],ebx"                    \
   "xor  eax,eax"                      \
"dmp_err:"                             \
   parm [ecx] [edi] [edx]              \
   modify exact [eax ebx ecx edi esi];

/* unmaps a linear address previously mapped to a physical address
   via function 0800h. This is a dpmi 1.0 function. */
int dpmi_unmap_linear_address(uchar *linAddr);
#pragma aux dpmi_unmap_linear_address =\
   "mov  ecx,ebx"                      \
   "shr  ebx,10h"                      \
   "mov  eax,0801h"                    \
   "int  31h"                          \
   "jc   dula_err"                     \
   "xor  eax,eax"                      \
"dula_err:"                            \
   parm [ebx]                          \
   modify exact [eax ebx ecx];

#endif /* !__DPMI_H */

