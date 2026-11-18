.orig	x4000

;************************************************************* MAIN

	ld	r0, N1
	jsr	subpr

	ld	r0, N2
	jsr	subpr

	ld	r0, N3
	jsr	subpr
	
	ld	r0, N4
	jsr	subpr

; CONCLUDO
stoqui	brnzp	stoqui


; VARIABILI E COSTANTI
N1	.fill	10
N2	.fill	2
N3	.fill	-4
N4	.fill	1

;************************************************************* END MAIN


;************************************************************* SUBPROGRAM

subpr
	; backup registri
	st	r1, saver1	; n-2
	st	r2, saver2	; n-1
	st	r3, saver3	; contatore
	st	r4, saver4	; salvo N
	st	r5, saver5	; confronto

	and	r4, r0, r0	; controllo in ogni caso r0 e salvo N
	brnz	nonpos		; se N <= 0 allora FN = 0
	add	r0, r0, #-1	; se N =  1 allora FN = 1
	brz	casouno

; qui positivo
	and	r1, r1, #0	; R1 = 0
	add	r2, r1, #1	; R2 = 1
	add	r3, r1, #-2	; imposto contatore a -2
ciclo
	add	r5, r4, r3	; precondizione: controllo se sforo N
	brn	fine

	add	r0, r2, r1	; R0 = R2 + R1
	add 	r1, r2, #0	; R1 = R2
	add	r2, r0, #0	; R2 = R0
	
	add	r3, r3, #-1	; contatore up (già confronto)
	brnzp	ciclo

casouno	add	r0, r4, #0	; imposto R0 = 1
	brnzp	fine
nonpos
	and	r0, r0, #0	; imposto R0 = 0
	

; chiusura subpr
fine
; restore registri
	ld	r1, saver1
	ld	r2, saver2
	ld	r3, saver3
	ld	r4, saver4
	ld	r5, saver5

	ret

; VARIABILI E COSTANTI
saver1	.blkw	1
saver2	.blkw	1
saver3	.blkw	1
saver4	.blkw	1
saver5	.blkw	1

;************************************************************* END SUBPROGRAM

	.end