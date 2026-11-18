	.orig	x4000

;************************************************************* MAIN

	ld	r0, n1
	jsr	subpr
	ld	r0, n2
	jsr	subpr
	ld	r0, n3
	jsr	subpr
	ld	r0, n4
	jsr	subpr

; CONCLUDO
stoqui	brnzp	stoqui


; VARIABILI E COSTANTI
n1	.fill	x800D
n2	.fill	x000D
n3	.fill	x0000
n4	.fill	x8000

;************************************************************* END MAIN


;************************************************************* SUBPROGRAM

subpr

; backup registro
	st	r1, saver1

; check bit del segno
	and	r0, r0, r0		; controllo se il numero è positivo
	brzp	fine			; se il CC è zero/positivo allora il numero è positivo

; numero negativo
	ld 	r1, rimsign		; carico la rimsign in quanto le costanti imm5 sono solo da 5 bit
	and	r0, r0, r1		; rimuovo il bit del segno
	not	r0, r0			; faccio il complemento a 1 del numero
	add	r0, r0, #1		; aggiungo 1 e trovo il numero in complemento a 2

; chiusura subpr
fine
	ld	r1, saver1		; restore registro
	ret

; VARIABILI E COSTANTI
rimsign	.fill	x7FFF

saver1	.blkw	1


;************************************************************* END SUBPROGRAM

	.end