	.orig x4000

;************************************************** MAIN
	
	lea	r0, A
	jsr	SOMMATORIA_NEG
stoqui	brnzp	stoqui


; VARIABILI MAIN
A	.fill	1
	.fill	7
	.fill	-3
	.fill	-12
	.fill	30
	.fill	-4
	.fill	2
	.fill	20
	.fill	-3
	.fill	9
	.fill	0

;************************************************** END MAIN

;************************************************** SUBPROGRAM

SOMMATORIA_NEG
	; backup registri
	st	r3, savr3
	; azzerramenti
	and	r2, r2, #0	; azzerro il contatore
	and	r3, r3, #0	; azzerro somma

ciclo
	ldr	r1, r0, #0	; carico valore i-esimo
	brz	fine		; se a[i] == 0 (tappo)
	brp	next		; se negativo faccio la somma e conto

; qui negativo
	add	r2, r2, #1	; contatore++
	add	r3, r3, r1	; somma += a[i] (negativo)
	
next	add	r0, r0, #1	; i++
	brnzp ciclo

fine
	add	r0, r3,	#0	; posiziono la somma
	add	r1, r2, #0	; posiziono il contatore
	; check underflow
	and	r2, r2, #0	; azzerro il check
	not	r0, r0
	add	r0, r0, #1	; valore assoluto della somma
	brzp	nounder		; se il valore assoluto non da underflow
	add	r2, r2, #1	; imposto a 1 il flag di underflow
nounder
	; restore registri
	ld	r3, savr3
	ret


; VARIABILI SUBPROGRAM
savr3	.blkw	1

;************************************************** END SUBPROGRAM

	.end