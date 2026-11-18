.orig	x4000

;************************************************************* MAIN

	lea	r0, string
	jsr	subpr

; CONCLUDO
stoqui	brnzp	stoqui


; VARIABILI E COSTANTI
string	.stringz	"Buon Lunedi 7 febbraio 2011"

;************************************************************* END MAIN


;************************************************************* SUBPROGRAM

subpr
; backup registri
	st	r1, saver1
	st	r2, saver2
	st	r3, saver3
	st	r4, saver4
	st	r5, saver5
	st	r6, saver6

; carico variabili utili
	ld	r2, inizmin	; carico il valore decimale del primo minuscolo
	ld 	r3, finmin	; carico il valore decimale dell'ultimo minuscolo
	ld	r4, convch	; valore di conversione min -> maiusc
	and 	r6, r6, #0	; azzerro il contatore

ciclo
	ldr	r1, r0, #0	; carico il contenuto dell'i-esima posizione
	brz	fine		; controllo se il valore i-esimo è NULL. Se NULL esco

; controllo zona minuscola
	add	r5, r1, r2	; controllo se è maggiore dell'inizio delle minuscole
	brn	nonmin		; se negativo sicuro non carattere minuscolo
	add 	r5, r1, r3	; controllo se è minore della fine delle maiuscole
	brp	nonmin		; se positivo è fuori dalla zona caratteri minuscoli

; conversione
	add	r1, r1,	r4	; converto carattere in maiuscolo
	str	r1, r0, #0	; aggiorno nell'array
	add	r6, r6, #1	; aumento contatore

nonmin	add	r0, r0, #1	; i++;
	brnzp	ciclo		; torno nel loop

; chiusura subpr
fine
	add	r0, r6, #0	; metto in r0 il contatore
; restore registri
	ld	r1, saver1
	ld	r2, saver2
	ld	r3, saver3
	ld	r4, saver4
	ld	r5, saver5
	ld	r6, saver6

	ret

; VARIABILI E COSTANTI
inizmin	.fill	-97
finmin	.fill	-122
convch	.fill	-32
saver1	.blkw	1
saver2	.blkw	1
saver3	.blkw	1
saver4	.blkw	1
saver5	.blkw	1
saver6	.blkw	1

;************************************************************* END SUBPROGRAM

	.end