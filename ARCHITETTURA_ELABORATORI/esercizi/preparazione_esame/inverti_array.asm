.orig x4000

;************************************************** MAIN
	
	lea	r0, arr
	lea	r1, endarr
	jsr	INVERTI
stoqui	brnzp	stoqui


; VARIABILI MAIN
arr	.fill	1
	.fill	2
	.fill 	3
	.fill	4
	.fill	6
	.fill	7
	.fill	8
endarr	.fill	9

;************************************************** END MAIN

;************************************************** SUBPROGRAM

INVERTI
	;backup registri
	st	r2, savr2
	st	r2, savr2

ciclo
	not	r2, r1
	add	r2, r2, #1
	add	r2, r0, r2
	brzp	fine

	ldr	r2, r0, #0	; carico posizione i-esima
	ldr	r3, r1, #0	; carico posizione lenght-i
	str	r2, r1, #0	; sposto l'elemento i-esimo in lenght-i
	str	r3, r0, #0	; sposto l'elemento lenght-i in i-esimo 

	add	r0, r0, #1	; i++
	add	r1, r1, #-1	; lenght-i
	brnzp	ciclo

fine	

;restore registri
	ld	r2, savr2
	ld	r3, savr3

	ret


; VARIABILI SUBPROGRAM
savr2	.blkw	1
savr3	.blkw	1

;************************************************** END SUBPROGRAM

	.end