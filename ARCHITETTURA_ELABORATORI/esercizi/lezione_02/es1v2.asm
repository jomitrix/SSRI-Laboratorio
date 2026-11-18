	.orig	x4000

;************************************************************* MAIN

	lea	r0, array
	lea	r1, arrend
	ld	r2, n
	jsr	subpr

; CONCLUDO
stoqui	brnzp	stoqui


; VARIABILI E COSTANTI
array	.fill	5
	.fill	3
	.fill	0
	.fill	-5
arrend	.fill	1

n	.fill	-5


;************************************************************* END MAIN


;************************************************************* SUBPROGRAM

subpr
	st	r3, saver3	; salvo il contenuto di r2
	st	r4, saver4	; salvo il contenuto di r3

	and	r4, r4, #0	; azzerro l'indice
	add	r4, r4, #1	; indice risposta parte da 1

	not	r2, r2		
	add	r2, r2, #1	; inverto il numero N per il confronto

	not	r1, r1		; inverto indirizzo per controllo fuori OutOfBound

ciclo	
	add	r3, r0, r1	; controllo fine
	brz	nonpres
	ldr	r3, r0, #0	; carico da indirizzo elemento i-esimo
	add	r3, r3, r2	; confronto i numeri
	brz	fine		; se uguali finisco

	add	r0, r0, x1	; mi sposto alla posizione successiva
	add	r4, r4, #1	; aggiungo 1 all'index
	brnzp	ciclo

nonpres	and	r4, r4, #0
fine	
	add	r0, r4, #0	; carico l'indice come risposta	
	ld	r3, saver3	; recupero il contenuto di r2
	ld	r4, saver4	; recupero il contenuto di r3
	ret			; ritorno al main

; VARIABILI E COSTANTI
saver3	.blkw	1
saver4	.blkw	1
index	.blkw	1

;************************************************************* END SUBPROGRAM

	.end