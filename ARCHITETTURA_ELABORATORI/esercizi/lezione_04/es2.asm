.orig	x4000

;************************************************************* MAIN

	lea	r0, inizs
	lea	r1, fines
	add	r1, r1, #-2
	jsr	CONTA_DOPPIE

; CONCLUDO
stoqui	brnzp	stoqui


; VARIABILI E COSTANTI
inizs	.stringz	"nel mezzo del cammin di nostra vita mi ritrovai per una selva oscura che' la diritta via era smarrita."
fines	.fill		0

;************************************************************* END MAIN


;************************************************************* SUBPROGRAM

CONTA_DOPPIE
; backup registri
	st	r2, saver2	; i-esima lettera
	st	r3, saver3	; i+1 esima lettera
	st	r4, saver4	; contatore

	not	r1, r1
	add	r1, r1, #1	; inverto per confronto
	and	r4, r4, #0	; azzerro contatore

ciclo
	add	r2, r0, r1	; controllo se sfora la fine stringa
	brzp	fine

	ldr	r2, r0, #0	; carico i-esima
	ldr	r3, r0, #1	; carico i+1-esima

	not	r3, r3
	add	r3, r3, #1	; inverto per confronto
	add	r3, r2, r3	; confronto
	brnp	noteq		; se non uguale vado avanti
	
	add	r4, r4, #1	; contatore doppie + 1
	add	r0, r0, #1	; salto la doppia

noteq	add	r0, r0, #1	; i++
	brnzp	ciclo

; chiusura subpr
fine
	add	r0, r4, #0	; passo il contatore in r0
; restore registri
	ld	r2, saver2
	ld	r3, saver3
	ld	r4, saver4

	ret

; VARIABILI E COSTANTI
saver1	.blkw	1
saver2	.blkw	1
saver3	.blkw	1
saver4	.blkw	1

;************************************************************* END SUBPROGRAM

	.end