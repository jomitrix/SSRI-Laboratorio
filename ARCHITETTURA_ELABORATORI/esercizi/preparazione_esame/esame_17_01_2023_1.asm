	.orig	x4000

;**************************************************** MAIN

	lea	r0, a
	ld	r1, n1
	ld	r2, n2
	jsr	INTERVALLI_ASS
stoqui	brnzp	stoqui


;VARIABILI
n1	.fill	5
n2	.fill	10
a	.fill	1
	.fill	7
	.fill	-3
	.fill	-12
	.fill 	30
	.fill	-4
	.fill	2
	.fill	20
	.fill	-3
	.fill	9
	.fill	0

;**************************************************** END MAIN

;**************************************************** SUBPROGRAM

INTERVALLI_ASS
	; backup registri
	st	r3, saver3
	st	r4, saver4
	st	r5, saver5
	st	r6, saver6
	st	r7, saver7


	add	r3, r0, #0	; R3 = ind -> A[0]
	
	not	r5, r1
	add	r5, r5, #1	; R5 = -N1 (pronto per confronto)
	not	r6, r2
	add	r6, r6, #1	; R6 = -N2 (pronto per confronto)
	
	and	r0, r0, #0	; R0 = x < N1
	and	r1, r1, #0	; R1 = N1 <= x <= N2
	and	r2, r2, #0	; R2 = x > N2

ciclo
	ldr	r4, r3, #0	; carico A[i]
	brz	fine		; 0 == tappo
	brp	checks
	
; qui negativo, faccio valore assoluto
	not	r4, r4
	add 	r4, r4, #1

; controllo caso 1
checks	add	r7, r4, r5
	brz	caso2
	brp	chkcas2

; qui caso 1
	add	r0, r0, #1
	brnzp	next
; controllo caso 2
chkcas2	add	r7, r4, r6
	brp	caso3
; qui caso 2
caso2	add	r1, r1, #1
	brnzp	next
; qui caso 3
caso3	add	r2, r2, #1

next	add	r3, r3, #1	; i++
	brnzp	ciclo

fine

	; restore registri
	ld	r3, saver3
	ld	r4, saver4
	ld	r5, saver5
	ld	r6, saver6
	ld	r7, saver7
	ret


; VARIABILI
saver3	.blkw	1
saver4	.blkw	1
saver5	.blkw	1
saver6	.blkw	1
saver7	.blkw	1



;**************************************************** END SUBPROGRAM

	.end