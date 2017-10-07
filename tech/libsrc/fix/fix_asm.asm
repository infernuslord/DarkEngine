; $RCSFile$
; $Author: TOML $
; $Date: 1996/10/25 10:47:04 $
;
; fixed point multiply and divide functions.
;
; each number is a 32-bit value split into 16 integer bits (top is sign) and
; 16 fractional bits.
;
; $Log: fix_asm.asm $
; Revision 1.12  1996/10/25  10:47:04  TOML
; msvc, part 3
; 
; Revision 1.11  1996/10/16  16:08:27  TOML
; msvc port, part 2
;
; Revision 1.10  1994/08/18  18:10:09  jaemz
; Added sloppy table sqrt
;
; Revision 1.9  1993/06/02  15:22:03  matt
; Changed assembly version of fix_sincos to work with new tables.
;
; Revision 1.8  1993/04/09  15:38:25  matt
; Fixed bug in long_sqrt - didn't clear highword of result
;
; Revision 1.7  1993/03/29  13:53:20  matt
; Changed fix_sincos (asm version) to not use bp (uses si instead)
;
; Revision 1.6  1993/03/17  12:47:11  matt
; Added fix_sincos callable from assembly that returns in 2 regs.
;
; Revision 1.5  1993/02/17  15:22:22  matt
; Added quad_sqrt routine
;
; Revision 1.4  1993/02/15  12:15:13  dfan
; fix24 sqrt
;
; Revision 1.3  1993/01/28  12:28:36  dfan
; square root function made faster
;
; Revision 1.2  1993/01/27  16:46:56  dfan
; sqrt functions
;
; Revision 1.1  1993/01/27  15:44:57  dfan
; Initial revision
;
; Revision 1.3  1992/09/16  19:30:20  unknown
; This file is now obsolete for WATCOM C programs.  The fixed-point math
; routines are being inlined in fix.h.
;
; Revision 1.2  1992/08/24  17:26:48  kaboom
; Added RCS keywords at top of file.
;


.386
include thunks.inc
assume cs:_TEXT, ds:_DATA

DGROUP group _DATA
_DATA segment dword public USE32 'DATA'

; byteguess is in array of the best guess for the square root of that byte

byteguess db 1 dup (1)		       ; not 0 because we can't divide by it
	db 2 dup (1)
	db 4 dup (2)
	db 6 dup (3)
	db 8 dup (4)
	db 10 dup (5)
	db 12 dup (6)
	db 14 dup (7)
	db 16 dup (8)
	db 18 dup (9)
	db 20 dup (10)
	db 22 dup (11)
	db 24 dup (12)
	db 26 dup (13)
	db 28 dup (14)
	db 30 dup (15)
	db 15 dup (15)		       ; not 16 because we only have 4 bits

_DATA ends

_TEXT segment dword public USE32 'CODE'

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	public	fix_sincos
	externdef	_sintab:word

sin_table equ _sintab
cos_table equ (sin_table + 64*2)

;asm-callable fix_sincos
;takes fixang in bx, returns sin in eax, cos in ebx
;this code based on the C&D routine sincos
;trashes ax,bx,cx,dx,si
fix_sincos:
	mov	cx,bx
	xor	ch,ch	;cx=byte fraction

 	mov	bl,bh
	movzx	ebx,bl	;clear high 3 bytes

	mov	si,sin_table[ebx*2]
	mov	ax,sin_table+2[ebx*2]
 	sub	ax,si
	imul	cx
	mov	al,ah
	mov	ah,dl
	add	ax,si
	push	ax	;save sin

	mov	si,cos_table[ebx*2]
	mov	ax,cos_table+2[ebx*2]
	sub	ax,si
	imul	cx
	mov	bl,ah
	mov	bh,dl
	add	bx,si

	pop	ax	;restore sin

	movsx	eax,ax	;set high word
	movsx	ebx,bx	;set high word

	sal	eax,2
	sal	ebx,2	;fill 16 bits

	ret


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; ushort long_sqrt (long x)
; eax = x
; x must be positive or we return 0
; returns the closest number to the answer

_FUNCDEF long_sqrt, 1
	mov	esi, eax	       ; save argument
	mov	ebx, offset byteguess  ; so we can xlat
	mov	edx, eax
	ror	edx, 16		       ; get high 16 bits of arg in dx
	mov	edi, edx	       ; save off high word

; we find the highest byte of the argument that is non-zero,
; look up a good first guess for that byte,
; and shift it the appropriate amount (cl)

test_A:
	or	dh, dh		       ; check high 8 bits of eax
	js	return_zero	       ; arg is negative!
	jz	test_B
	mov	al, dh		       ; prepare for xlat
	mov	cl, 12
	jmp	found_bits

test_B:
	or	dl, dl		       ; check next 8 bits of eax
	jz	test_C
	mov	al, dl		       ; prepare for xlat
	mov	cl, 8
	jmp	found_bits

test_C:
	or	ah, ah		       ; check next 8 bits of eax
	jz	test_D
	mov	al, ah		       ; prepare for xlat
	mov	cl, 4
	jmp	found_bits

test_D:			       	       ; deal with low 8 bits of eax
	or	al, al		       ; avoid divide by 0
	jz	return_zero
	sub	cl, cl

; now we generate the good initial guess

found_bits:
	xlat
	movzx	ebx, al
	shl	ebx, cl		       ; bx now has the first guess

; experience has shown that we almost always go through the loop
; just about three times.  to avoid compares and jumps, we iterate
; three times without even thinking about it, and then start checking
; if our answer is correct.

newton_loop:
rept 2
	mov	eax, esi	       ; arg in dx:ax
	div	bx		       ; 16 bit divide
	add	bx, ax
	rcr	bx, 1		       ; bx <- (bx+ax)/2
	mov	edx, edi
endm

; starting with the third iteration, we start actually checking

newton_loop2:
	mov	eax, esi
	div	bx
	cmp	ax, bx
	je	bx_is_correct	       ; if bx = ax, we win
	mov	cx, bx		       ; save old bx for comparing
	add	bx, ax
	rcr	bx, 1		       ; bx <- (bx+ax)/2
	cmp	ax, bx		       ; compare old ax with average
	je	bx_is_close
	cmp	cx, bx		       ; compare old bx with average
	je	bx_is_close
	mov	edx, edi
	jmp	newton_loop2

; now we must find which is closer to x, bx^2 or (bx+1)^2
; x = bx*(bx+1)+r = bx^2 + bx + r
;   which is closer to bx^2 than to bx^2 + 2bx + 1
;   only if r = 0!  luckily we have r in dx from the divide

bx_is_close:
	or	dx,dx
	jz	bx_is_correct
	inc	ebx

bx_is_correct:
	mov	eax, ebx
	ret

return_zero:
	sub	eax, eax	       ; return 0
	ret

; fix fix_sqrt (fix x)
; eax = x
_FUNCDEF fix_sqrt, 1
	call	long_sqrt_
	movzx	eax, ax
	shl	eax, 8
	ret

; Beware, bro', this ONLY does the table lookup
; we could make it a bit more modular, perhaps
; by combining this with long_sqrt since its the same
_FUNCDEF fix_sloppy_sqrt, 1
	mov	esi, eax	       ; save argument
	mov	ebx, offset byteguess  ; so we can xlat
	mov	edx, eax
	ror	edx, 16		       ; get high 16 bits of arg in dx
	mov	edi, edx	       ; save off high word

; we find the highest byte of the argument that is non-zero,
; look up a good first guess for that byte,
; and shift it the appropriate amount (cl)

s_test_A:
	or	dh, dh		       ; check high 8 bits of eax
	js	return_zero	       ; arg is negative!
	jz	s_test_B
	mov	al, dh		       ; prepare for xlat
	mov	cl, 12
	jmp	s_found_bits

s_test_B:
	or	dl, dl		       ; check next 8 bits of eax
	jz	s_test_C
	mov	al, dl		       ; prepare for xlat
	mov	cl, 8
	jmp	s_found_bits

s_test_C:
	or	ah, ah		       ; check next 8 bits of eax
	jz	s_test_D
	mov	al, ah		       ; prepare for xlat
	mov	cl, 4
	jmp	s_found_bits

s_test_D:			       	       ; deal with low 8 bits of eax
	or	al, al		       ; avoid divide by 0
	jz	return_zero
	sub	cl, cl

; now we generate the good initial guess

s_found_bits:
	xlat
	movzx	ebx, al
        add     cl,8
	shl	ebx, cl		       ; bx now has the first guess
	mov     eax,ebx
	ret


; fix24 fix24_sqrt (fix24 x)
; eax = x
_FUNCDEF fix24_sqrt, 1

	call	long_sqrt_
	movzx	eax, ax
	shl	eax, 4
	ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; long quad_sqrt (quad x)	- NOT C CALLABLE!!!!
; edx:eax = x
; x must be positive or we return 0
; returns the closest number to the answer

public quad_sqrt
quad_sqrt:	or	edx,edx	;check for high word
	jnz	must_use_quad
	or	eax,eax
	jns	long_sqrt_
must_use_quad:

	mov	esi, eax	       ; save argument
	mov	edi, edx	       ; save off high word

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	mov	ebx, offset byteguess  ; so we can xlat

; we find the highest byte of the argument that is non-zero,
; look up a good first guess for that byte,
; and shift it the appropriate amount (cl)

q_test_A:
	ror	edx,16

	or	dh, dh		       ; check high 8 bits of eax
	js	return_zero	       ; arg is negative!
	jz	q_test_B
	mov	al, dh		       ; prepare for xlat
	mov	cl, 16+12
	jmp	q_found_bits

q_test_B:
	or	dl, dl		       ; check next 8 bits of eax
	jz	q_test_C
	mov	al, dl		       ; prepare for xlat
	mov	cl, 16+8
	jmp	q_found_bits

q_test_C:
	ror	edx,16

	or	dh, dh		       ; check next 8 bits of eax
	jz	q_test_D
	mov	al, ah		       ; prepare for xlat
	mov	cl, 16+4
	jmp	q_found_bits

q_test_D:			       	       ; deal with low 8 bits of eax
	mov	cl, 16

; now we generate the good initial guess

q_found_bits:
	xlat
	movzx	ebx, al
	shl	ebx, cl		       ; bx now has the first guess

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


; experience has shown that we almost always go through the loop
; just about three times.  to avoid compares and jumps, we iterate
; three times without even thinking about it, and then start checking
; if our answer is correct.

q_newton_loop:
 rept 2
	mov	edx, edi
	mov	eax, esi	       ; arg in dx:ax
	div	ebx		       ; 16 bit divide
	add	ebx, eax
	rcr	ebx, 1		       ; bx <- (bx+ax)/2
 endm

; starting with the third iteration, we start actually checking

q_newton_loop2:
	mov	eax, esi
	mov	edx, edi
	div	ebx
	cmp	eax, ebx
	je	q_bx_is_correct	       ; if bx = ax, we win
	mov	ecx, ebx		       ; save old bx for comparing
	add	ebx, eax
	rcr	ebx, 1		       ; bx <- (bx+ax)/2
	cmp	eax, ebx		       ; compare old ax with average
	je	q_bx_is_close
	cmp	ecx, ebx		       ; compare old bx with average
	je	q_bx_is_close
	jmp	q_newton_loop2

; now we must find which is closer to x, bx^2 or (bx+1)^2
; x = bx*(bx+1)+r = bx^2 + bx + r
;   which is closer to bx^2 than to bx^2 + 2bx + 1
;   only if r = 0!  luckily we have r in dx from the divide

q_bx_is_close:
	or	edx,edx
	jz	q_bx_is_correct
	inc	ebx

q_bx_is_correct:
	mov	eax, ebx
	ret

q_return_zero:
	sub	eax, eax	       ; return 0
	ret


_TEXT ends

end
