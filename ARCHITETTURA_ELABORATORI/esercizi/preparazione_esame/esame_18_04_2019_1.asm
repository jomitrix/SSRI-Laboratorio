	.orig	x4000

;***************************************** MAIN

	lea	r0, stringa
	jsr	MAIUSC
stoqui	brnzp	stoqui

; VARIABILI
stringa	.stringz	"La sigla USA significa United States of AmericaZz"

;***************************************** END MAIN

;***************************************** SUBPROGRAM

MAIUSC
	; backup registri
	st	r1, saver1
	st	r2, saver2
	st	r3, saver3
	st	r4, saver4
	st	r5, saver5
	st	r6, saver6
	
	ld	r2, min1
	ld	r3, min2
	ld	r4, maius
	and	r5, r5, #0	; count = 0

ciclo	ldr	r1, r0, #0	; carico i-esima
	brz	fine		; se 0 finita stringa

	add	r6, r1, r2	; controllo se > 97
	brn	next
	add	r6, r1, r3	; controllo se < 122
	brp	next
	
	;qui minuscola
	add	r1, r1, r4	; converto
	str	r1, r0, #0	; sostituisco
	add	r5, r5, #1	; count++

next	add	r0, r0, #1	; i++
	brnzp	ciclo

fine
	add	r0, r5, #0

	; backup registri
	ld	r1, saver1
	ld	r2, saver2
	ld	r3, saver3
	ld	r4, saver4
	ld	r5, saver5
	ld	r6, saver6
	ret

; VARIABILI
saver1	.blkw	1
saver2	.blkw	1
saver3	.blkw	1
saver4	.blkw	1
saver5	.blkw	1
saver6	.blkw	1
min1	.fill	-97
min2	.fill	-122
maius	.fill	-32

;***************************************** END SUBPROGRAM

	.end