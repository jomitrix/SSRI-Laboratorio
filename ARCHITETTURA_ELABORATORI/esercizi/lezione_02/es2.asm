	.orig	x4000

;************************************************************* MAIN

	lea	r0, array
	lea	r1, endarr
	jsr	subpr

; CONCLUDO
stoqui	brnzp	stoqui


; VARIABILI E COSTANTI
array	.fill	2
	.fill	5
	.fill	9
	.fill	12
endarr	.fill	34

;************************************************************* END MAIN


;************************************************************* SUBPROGRAM

subpr

; backup registri
	st	r2, saver2
	st	r3, saver3

ciclo

; inverto l'indirizzo del registro
	not	r2, r1
	add	r2, r2, #1
; controllo se l'indirizzo è lo stesso in caso di array dispari, o se sfora pari
	add	r2, r0, r2
	brzp	fine
	
	ldr	r2, r0, #0	; prelevo elemento i-esimo array
	ldr	r3, r1, #0	; prelevo elemento lenght-i array
	str	r2, r1, #0	; salvo l'elemento i-esimo in posizione lenght-i
	str	r3, r0, #0	; salvo l'elemento lengh-i in posizione i-esima

	add	r0, r0, #1	; i++
	add	r1, r1, #-1	; lenght-++i
	
	brnzp	ciclo


fine
; restore registri
	ld	r2, saver2
	ld	r3, saver3
	
; torno al main
	ret

; VARIABILI E COSTANTI
saver2	.blkw	1
saver3	.blkw	1

;************************************************************* END SUBPROGRAM

	.end