	.orig x4000

;************************************************** MAIN
	
	lea	r0, arr
	lea	r1, endarr
	ld	r2, num
	jsr	CONTA_SE
stoqui	brnzp	stoqui


; VARIABILI MAIN
arr	.fill	-56	
	.fill	15
	.fill 	-9
	.fill	-15
	.fill	0
	.fill	15
	.fill	-15
	.fill	27
endarr	.fill	15
num	.fill	15

;************************************************** END MAIN

;************************************************** SUBPROGRAM

CONTA_SE
	; backup reg
	st	r3, svr3
	st	r4, svr4
	st	r5, svr5
	st	r6, svr6
	st	r7, svr7

	; azzerro contatori
	and	r6, r6, #0	
	and	r7, r7, #0
	; confronti	
	not	r1, r1		
	add	r1, r1, #1	; R1 fine array
	not 	r3, r2
	add	r3, r3, #1	; R3 normale R2 opposto
	
ciclo	add	r4, r0, r1
	brp	fine
	
	ldr	r4, r0, #0	; carico i-esimo

; confronto normale
	add	r5, r4, r3
	brnp	opposto
	add	r6, r6, #1	; incremento contatore norm
	brnzp	next

; confronto opposto
opposto	add	r5, r4, r2
	brnp	next
	add	r7, r7, #1	; incremento contatore opp

next	add	r0, r0, #1	; i++
	brnzp	ciclo

fine	
	add	r0, r6, #0	; R0 contatore normali
	add	r1, r7, #0	; R1 contatore opposti
	; restore reg
	ld	r3, svr3
	ld	r4, svr4
	ld	r5, svr5
	ld	r6, svr6
	ld	r7, svr7

	ret


; VARIABILI SUBPROGRAM
svr3	.blkw	1
svr4	.blkw	1
svr5	.blkw	1
svr6	.blkw	1
svr7	.blkw	1

;************************************************** END SUBPROGRAM

	.end