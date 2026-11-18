.orig	x4000

;************************************************************* MAIN

	lea	r0, array
	lea	r1, endarr
	jsr	subpr

; CONCLUDO
stoqui	brnzp	stoqui


; VARIABILI E COSTANTI
array	.fill	112
	.fill	-27
	.fill	-1232
	.fill	450
	.fill	15
endarr	.fill	120

;************************************************************* END MAIN


;************************************************************* SUBPROGRAM

subpr
; backup registri
	st	r2, saver2
	st	r3, saver3
	st	r4, saver4
	st	r5, saver5
	
	and	r4, r4, #0	; azzerro contatore pari
	and	r5, r5, #0	; azzerro contatore dispari

	not	r1, r1		; inverto indirizzo e
	add	r1, r1, #1	; aggiungo 1 per il confronto

ciclo
	add	r3, r0, r1	; controllo se OutOfBound 
	brp	fine		; se OutOfBound quindi esco

	ldr	r2, r0, #0	; carico il contenuto dell'i-esima posizione

; controllo pari/dispari
	and 	r3, r2, #1	; controllo contenuto della posizione 2^0
	brz	pari

; qui dispari
	add	r5, r5, #1	; incremento contatore dispari
	brnzp	iter

; qui pari
pari	add	r4, r4, #1	; incremento contatore pari

iter	add	r0, r0, #1	; i++;
	brnzp	ciclo		; torno nel loop


; chiusura subpr
fine
	add	r0, r4, #0	; metto in r0 il contatore pari
	add	r1, r5, #0	; metto in r1 il contatore dispari
; restore registri
	ld	r2, saver2
	ld	r3, saver3
	ld	r4, saver4
	ld 	r5, saver5

	ret

; VARIABILI E COSTANTI
saver2	.blkw	1
saver3	.blkw	1
saver4	.blkw	1
saver5	.blkw	1

;************************************************************* END SUBPROGRAM

	.end