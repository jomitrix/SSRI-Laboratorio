	.orig	x4000

;************************************************************* MAIN

	ld	r1, n1
	ld	r2, n2
	jsr	subpr

	ld	r1, n3
	ld	r2, n4
	jsr	subpr

	ld	r1, n5
	ld	r2, n6
	jsr	subpr

; concludo
stoqui	brnzp	stoqui


; variabili e costanti del main

n1	.fill	7
n2	.fill	5
n3	.fill	3
n4	.fill	3
n5	.fill	1
n6	.fill	4

;************************************************************* END MAIN


;************************************************************* SUBPROGRAM

; imposto r0 a 0
subpr	and	r0, r0, #0	; R0 = 0

; sottrazione per il confronto
	not	r2, r2		; R2 = complemento a 1
	add	r2, r2, #1	; R2 = complemento a 2 (R2 = -R2)
	add	r2, r1, r2	; R2 = R1 - R2

; check condizione
	brz	zero		; if zero
	brp	pos		; if pos
				; else

; num1 < num2
	add	r0, r0, -1	; R0 = R0 + (-1)
	brnzp	fine
; num1 = num2
zero	add	r0, r0, 0	; R0 = R0 + (0)
	brnzp	fine
	ret
; num1 > num2
pos	add	r0, r0, 1	; R0 = R0 + (1)
; fine check condizione

fine	ret			; ritorno al main

;************************************************************* END SUBPROGRAM

	.end