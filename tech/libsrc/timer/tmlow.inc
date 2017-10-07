;
; $Source: r:/prj/lib/src/timer/rcs/tmlow.inc $
; $Revision: 1.2 $
; $Author
; $Date: 1994/10/17 17:44:08 $
;
; Definitions for format of low memory buffer.
;
; This file is part of the timer library.
;
; $Log: tmlow.inc $
; Revision 1.2  1994/10/17  17:44:08  lmfeeney
; use memory formerly used for tmd_ticks to store eax, not
; optimal, but easiest
; 
; Revision 1.1  1993/05/20  15:50:18  kaboom
; Initial revision
; 

TML_RECLIST_SIZE        equ 10h

TML_OLD_REAL_HANDLER    equ 0
TML_DENOM               equ 4           ;current timer denominator
TML_NEW_DENOM           equ 8           ;new timer denominator
TML_CUR_REC             equ 12          ;current process record
TML_GLOBAL_SIZE         equ 16
TML_RECLIST_START       equ TML_GLOBAL_SIZE
TML_RECLIST_END         equ TML_RECLIST_START+TMR_SIZE*TML_RECLIST_SIZE
TML_RECLIST_LAST        equ TML_RECLIST_END-TMR_SIZE
TML_LOWBUF_SIZE         equ TML_RECLIST_END
