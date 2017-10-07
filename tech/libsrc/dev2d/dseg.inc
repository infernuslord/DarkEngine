;
; $Source: s:/prj/tech/libsrc/dev2d/RCS/dseg.inc $
; $Revision: 1.2 $
; $Author: KEVIN $
; $Date: 1996/04/11 09:28:27 $
;
; Watcom C data segment declarations.
;

.386

assume ds:DGROUP
DGROUP group _DATA
_DATA segment dword public use32 'DATA'
_DATA ends
