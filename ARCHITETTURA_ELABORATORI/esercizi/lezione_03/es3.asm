.orig	x4000

;************************************************************* MAIN

	lea	r0, array
	ld	r1, bits
	jsr	subpr

; CONCLUDO
stoqui	brnzp	stoqui


; VARIABILI E COSTANTI
array	.fill	b0000111100001111
	.fill	b0011001100110011
	.fill	b1100110011001100
	.fill	0

bits	.fill	b1111000011110000

;************************************************************* END MAIN


;************************************************************* SUBPROGRAM

subpr
	st	r2, saver2	; backup registro
	not	r1, r1		; NOT B (Teorema De Morgan)

ciclo
	ldr	r2, r0, #0	; carico il contenuto dell'i-esima posizione
	brz	fine		; controllo se il valore i-esimo è 0. Se 0 esco

; effettuo la somma logica
	not	r2, r2;		; NOT A (Teorema de Morgan)
	and	r2, r2, r1	; NOT A  AND  NOT B  =  NOR (Teorema de Morgan)
	not	r2, r2		; NOT NOR = OR (Teorema de Morgan)
	str	r2, r0, #0	; aggiorno l'elemento i-esimo

	add	r0, r0, #1	; i++;
	brnzp	ciclo		; torno nel ciclo

; chiusura subpr
fine
	ld	r2, saver2	; restore registro

	ret

; VARIABILI E COSTANTI
saver2	.blkw	1

;************************************************************* END SUBPROGRAM

	.end