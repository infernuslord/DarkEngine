;
; $Source: r:/prj/lib/src/timer/rcs/tmhnd.inc $
; $Revision: 1.2 $
; $Author: kaboom $
; $Date: 1994/02/02 11:46:29 $
;
; Declarations for timer interrupt handlers.
;
; This file is part of the timer library.
;
; $Log: tmhnd.inc $
; Revision 1.2  1994/02/02  11:46:29  kaboom
; Added declaration for tmd_prot_handler_size.
; 
; Revision 1.1  1993/05/20  15:50:06  kaboom
; Initial revision
; 

externdef _tmd_prot_handler_size:dword
externdef tm_prot_handler_:near
externdef tph_chain_:near
