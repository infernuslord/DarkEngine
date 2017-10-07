; $Header: r:/t2repos/thief2/src/demo.cmd,v 1.1 1998/02/20 17:35:29 mahk Exp $

; stuff for dark demo
; load the mission 
eval demo_mission load_file %s
; no inv bar
control_inv_bar -1   
; use d3d
d3d 
; go to metagame mode
metagame  


