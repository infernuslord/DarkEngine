;
; $Source: r:/prj/lib/src/timer/rcs/tmd.inc $
; $Revision: 1.2 $
; $Author
; $Date: 1994/10/17 17:34:50 $
;
; External declarations for timer global variables.
;
; This file is part of the timer library.
;
; $Log: tmd.inc $
; Revision 1.2  1994/10/17  17:34:50  lmfeeney
; tmd_ticks removed to tm_realtime
; 
; Revision 1.1  1993/05/20  15:49:36  kaboom
; Initial revision
; 

externdef _tmd_lowmem_sel:word
externdef _tmd_lowmem_start:dword       ;export <char *>
externdef _tmd_old_prot_handler:fword
externdef _tmd_installed_procs:dword
