;
; $Source: r:/prj/lib/src/timer/rcs/tmdecl.inc $
; $Revision: 1.2 $
; $Author
; $Date: 1994/10/17 17:45:42 $
;
; External declarations for timer functions.
;
; This file is part of the timer library.
;
; $Log: tmdecl.inc $
; Revision 1.2  1994/10/17  17:45:42  lmfeeney
; removed old functions added new ones
; 
; Revision 1.1  1993/05/20  15:49:44  kaboom
; Initial revision
; 

externdef tm_init_libt_:near
externdef tm_close_libt_:near
externdef tm_set_rate_:near
externdef TF_tm_add_process_:near
externdef tm_remove_process_:near
externdef tm_activate_process_:near
externdef tm_deactivate_process_:near
externdef tm_find_fastest_:near
externdef tm_set_process_denom_:near
externdef tm_set_process_freq_:near
externdef tm_set_process_period_:near

