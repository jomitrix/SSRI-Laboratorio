.orig x4000

;********************************************* MAIN

	ld	r0, char1
	jsr	TIPO_CAR
	ld	r0, char2
	jsr	TIPO_CAR
	ld	r0, char3
	jsr	TIPO_CAR
	ld	r0, char4
	jsr	TIPO_CAR
	ld	r0, char5
	jsr	TIPO_CAR
stoqui	brnzp	stoqui

; VARIABILI MAIN
char1	.fill	109
char2	.fill	36
char3	.fill	55
char4	.fill	122
char5	.fill	123

;********************************************* END MAIN

;********************************************* SUBPROGRAM

TIPO_CAR
; backup registri
	st	r1, saver1
	st	r2, saver2

	and 	r2, r2, #0	; azzerro r2

; check non valido	
	add	r0, r0, #0	; controllo se il numero è <= 0 (non valido == 5)
	brnz	none

; check controllo
	ld	r1, cont1	
	add	r1, r0, r1	; controllo se il numero è < 32
	brzp	cifra		; non controllo
	add	r0, r2, #1	; se valido imposto R2 = 1
	brnzp	fine		; e termino

cifra	;check cifra
	ld 	r1, cifra1	
	add	r1, r0, r1	; controllo se il numero è >= 48
	brn	none		; tipo non elencato
	ld 	r1, cifra2	
	add	r1, r0, r1	; controllo se il numero è <= 57
	brp	maiusc		; non cifra
	add	r0, r2, #2	; se valido imposto R2 = 2
	brnzp	fine		; e termino

maiusc	;check maiuscola
	ld	r1, maiu1
	add	r1, r0, r1	; controllo se il numero è >= 65
	brn	none		; tipo non elencato
	ld	r1, maiu2
	add	r1, r0, r1	; controllo se il numero è <= 90
	brp	minusc		; non maiuscola
	add	r0, r2, #3	; se valido imposto R2 = 3
	brnzp	fine		; e termino

minusc	;check minuscola
	ld	r1, min1	
	add	r1, r0, r1	; controllo se il numero è >= 97
	brn	none		; tipo non elencato
	ld	r1, min2	
	add	r1, r0, r1	; controllo se il numero è <= 122
	brp	none		; tipo non elencato
	add	r0, r2, #4	; se valido imposto R2 = 4
	brnzp	fine		; e termino

none	
	add	r0, r2, #5	; se il numero non è valido/tipo non elencato R2 = 5

fine
	; restore registri
	ld	r1, saver1
	ld	r2, saver2
	
	ret

; VARIABILI SUBPROGRAM
saver1	.blkw	1
saver2	.blkw	1
saver3	.blkw	1
cont1	.fill	-32
cifra1	.fill	-48
cifra2	.fill	-57
maiu1	.fill	-65
maiu2	.fill	-90
min1	.fill	-97
min2	.fill	-122

;********************************************* END SUBPROGRAM

.end