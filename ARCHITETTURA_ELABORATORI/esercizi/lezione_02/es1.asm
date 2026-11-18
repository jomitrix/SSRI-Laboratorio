	.orig	x4000

;************************************************************* MAIN

	lea	r0, array
	ld	r1, n
	jsr	subpr

; CONCLUDO
stoqui	brnzp	stoqui


; VARIABILI E COSTANTI
array	.fill	5
	.fill	3
	.fill	-5
	.fill	1
	.fill	0

n	.fill	-5


;************************************************************* END MAIN


;************************************************************* SUBPROGRAM

subpr
	st	r2, saver2	; salvo il contenuto di r2
	st	r3, saver3	; salvo il contenuto di r3

	and	r3, r3, #0	; azzerro l'indice
	add	r3, r3, #1	; indice risposta parte da 1

	not	r1, r1		
	add	r1, r1, #1	; inverto il numero N per il confronto
ciclo	
	ldr	r2, r0, #0	; carico da indirizzo elemento i-esimo
	brz	nonpres
	add	r2, r2, r1	; confronto i numeri
	brz	fine		; se uguali finisco

	add	r0, r0, x1	; mi sposto alla posizione successiva
	add	r3, r3, #1	; aggiungo 1 all'index

	brnzp	ciclo
	
nonpres	and	r3, r3, #0
fine	
	add	r0, r3, #0	; carico l'indice	
	ld	r2, saver2	; recupero il contenuto di r2
	ld	r3, saver3	; recupero il contenuto di r3
	ret			; ritorno al main

; VARIABILI E COSTANTI
saver2	.blkw	1
saver3	.blkw	1
index	.blkw	1

;************************************************************* END SUBPROGRAM

	.end