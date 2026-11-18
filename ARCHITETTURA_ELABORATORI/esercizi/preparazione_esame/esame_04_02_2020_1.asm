	.orig	x4000
;**************************************************** MAIN
;**************************************************** END MAIN

	lea	r0, a0
	lea	r1, a1
	lea	r2, a2
	jsr	SOMMA_ARRAY
stoqui	brnzp	stoqui


;VARIABILI MAIN
a0	.fill	32760
	.fill	7
	.fill	-32760
	.fill	8
	.fill	0	;tappo

a1	.fill	8
	.fill	17
	.fill	-9
	.fill	-9
	.fill	0	;tappo

a2	.fill	0
	.fill	0
	.fill	0
	.fill	0

;**************************************************** SUBPROGRAM

SOMMA_ARRAY
	; backup reg
	st	r3, savr3
	st	r4, savr4
	st	r5, savr5
	st	r6, savr6
	st	r7, savr7

	and	r6, r6, #0;
	and	r7, r7, #0;
ciclo
	ldr	r3, r0, #0	; carico i-esima (A0)
	brp	chkpos1
	add	r6, r6, #-1
chkpos1	add	r6, r6, #1

	ldr	r4, r1, #0	; carico i-esima (A1)
	brz	fine
	brp	chkpos2
	add	r6, r6, #-1
chkpos2	add	r6, r6, #1

	add	r5, r3, r4	; R5 = A0(i) + A1(i)
	str	r5, r2, #0	; salvo in A2(i) la somma contenuta in R5

	add	r6, r6, #0
	brz	next
	brp	chkover

; controllo under
	add	r5, r5, #0
	brn	next
	add	r7, r7, #1
	brnzp	next
; controllo over
chkover	add	r5, r5, #0
	brp	next
	add	r7, r7, #1

next	add	r0, r0, #1	; i++
	add	r1, r1, #1	; i++
	add	r2, r2, #1	; i++
	
	
	brnzp	ciclo
	
fine
	add	r0, r7, #0
	; restore reg
	ld	r3, savr3
	ld	r4, savr4
	ld	r5, savr5
	ld	r6, savr6
	ld	r7, savr7
	ret


;VARIABILI SUBPR
savr3	.blkw	1
savr4	.blkw	1
savr5	.blkw	1
savr6	.blkw	1
savr7	.blkw	1


;**************************************************** END SUBPROGRAM
	
	.end