.orig	x4000

;************************************************************* MAIN

	lea	r0, array
	jsr	subpr

; CONCLUDO
stoqui	brnzp	stoqui


; VARIABILI E COSTANTI
array	.fill	x0003
	.fill	x0045
	.fill	x8068
	.fill	x0014
	.fill	x0000

;************************************************************* END MAIN


;************************************************************* SUBPROGRAM

subpr
	; backup registri
	st	r1, saver1
	st	r2, saver2
	st	r3, saver3

	and	r2, r2, #0	; azzerro il contenuto della variabile somma

ciclo
	ldr	r1, r0, #0	; carico il contenuto dell'i-esima posizione
	add	r1, r1, #0	; controllo se il valore i-esimo è 0
	brz	fine		; se A[i] == 0, esco

	and	r1, r1, r1	; controllo se il numero è positivo 
	brzp	somma

; converto numero in complemento a 2
	ld	r3, rimsign
	and	r1, r1, r3	; rimuovo il segno
	not	r1, r1		; faccio il complemento a 1
	add	r1, r1, #1	; porto il numero in complemento a 2		

somma
	add	r2, r2, r1	; SOMMA += A[i]

	add	r0, r0, #1	; i++;
	brnzp	ciclo		; torno nel loop

; chiusura subpr
fine
	add	r0, r2, #0	; sposto in r0 ka sommatoria
	; recupero registri
	ld	r1, saver1
	ld	r2, saver2
	ld	r3, saver3

	ret

; VARIABILI E COSTANTI
binmask	.fill	x8000
rimsign	.fill	x7FFF

saver1	.blkw	1
saver2	.blkw	1
saver3	.blkw	1


;************************************************************* END SUBPROGRAM

	.end