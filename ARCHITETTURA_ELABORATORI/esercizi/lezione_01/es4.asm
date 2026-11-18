	.orig	x4000

;************************************************************* MAIN

; carico gli indirizzi nei registri
	ld	r1, n1
	ld	r2, n2
	jsr	subpr

	ld	r1, n3
	ld	r2, n4
	jsr	subpr

; concludo
stoqui	brnzp	stoqui


; variabili e costanti del main

n1	.fill	32000
n2	.fill	32000
n3	.fill	-29000
n4	.fill	-29000

;************************************************************* END MAIN


;************************************************************* SUBPROGRAM

; imposto r0 a 0
subpr	and	r0, r0, #0

; check valori
	add	r1, r1, #0		; controllo se il primo positivo o negativo
	brn	neg			; se primo registro negativo

;  caso primo registro positivo
	add	r2, r2, #0		; controllo se il secondo negativo
	brn	ok			; se negativo ok
	add	r1, r1, r2		; sennò sommo e controllo
	brn	over			; se risultato negativo c'è overflow
	brzp	fine

;  caso primo registro negativo
neg	add	r2, r2, #0		; controllo se il secondo positivo
	brzp	ok			; se positivo ok
	add	r1, r1, r2		; sennò sommo e controllo
	brzp	under			; se risultato positivo c'è underflow
	brn	fine

; imposto registro 0
over	add	r0, r0, #1		; imposto r0 a 1 se overflow
	brnzp	fine
under	add	r0, r0, #-1		; imposto r0 a -1 se underflow
	brnzp 	fine

; nel caso in cui non ho sommato sommo
ok	add	r1, r1, r2
	

fine	ret				; ritorno al main

;************************************************************* END SUBPROGRAM

	.end