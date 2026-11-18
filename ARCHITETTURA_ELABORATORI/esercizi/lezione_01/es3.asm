	.orig	x4000

;************************************************************* MAIN

; carico gli indirizzi nei registri
	lea	r1, xn1
	lea	r2, xn2
	jsr	subpr

; concludo
stoqui	brnzp	stoqui


; variabili e costanti del main

n1	.fill	5
n2	.fill	7
xn1	.fill	n1
xn2	.fill	n2

;************************************************************* END MAIN


;************************************************************* SUBPROGRAM

; imposto r0 a 0
subpr	and	r0, r0, #0	; R0 = 0
; carico con l'indirizzo l'indirizzo dei valori
	ldr	r1, r1, 0	; R1 = *R1
	ldr	r2, r2, 0	; R2 = *R2
; carico con l'indirizzo i valori
	ldr 	r1, r1, 0	; R1 = *R1
	ldr	r2, r2, 0	; R2 = *R2

; sottrazione per il confronto
	not	r2, r2		; R2 = complemento a 1
	add	r2, r2, #1	; R2 = complemento a 2 (R2 = -R2)
	add	r2, r1, r2	; R2 = R1 - R2

; check condizione
	brz	zero		; if zero
	brp	pos		; if pos
				; else

; num1 < num2
	add	r0, r0, -1	; R0 = R0 + (-1)
	brnzp	fine
; num1 = num2
zero	add	r0, r0, 0	; R0 = R0 + (0)
	brnzp	fine
	ret
; num1 > num2
pos	add	r0, r0, 1	; R0 = R0 + (1)
; fine check condizione

fine	ret			; ritorno al main

;************************************************************* END SUBPROGRAM

	.end