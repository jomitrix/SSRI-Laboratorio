.orig	x4000

;************************************************************* MAIN

	lea	r0, array
	jsr	GAP_ASS

; CONCLUDO
stoqui	brnzp	stoqui


; VARIABILI E COSTANTI
array	.fill	112
	.fill	-27
	.fill	-12
	.fill	45
	.fill	15
	.fill	0

;************************************************************* END MAIN


;************************************************************* SUBPROGRAM

GAP_ASS
; backup registri
	st	r1, saver1	; a[i]
	st	r2, saver2	; op con max
	st	r3, saver3	; op con min

; variabili utili

ciclo
	ldr	r1, r0, #0	; carico i-esimo array
	brz	diff
	brp	maxmin

; qui negativo
	not	r1, r1
	add	r1, r1, #1	; effettuo il modulo (valore assoluto)
	brzp	maxmin		; controllo unico caso di errore per via del complemento a 2
	add	r1, r1, #-1	; nel caso x8000 non esiste valore assoluto, quindi si prende
				; il valore assoluto di x8000 ma -1 (il massimo intero rappresentabile)

; cerco il max e il min dei valori assoluti
maxmin
	ld	r2, max
	not	r2, r2
	add	r2, r2, #1	; carico e inverto max per il confronto
	ld	r3, min
	not	r3, r3
	add	r3, r3, #1	; carico e inverto min per il confronto

	; controllo max
	add	r2, r1, r2	; controllo se max > a[i]
	brnz	nomax
	st	r1, max		; se a[i] > max allora max = a[i]
	
nomax	;controllo min
	add	r3, r1, r3	; controllo se min < a[i]
	brzp	nomin		
	st	r1, min		; se a[i] < min allora min = a[i]
	
nomin	add	r0, r0, #1	; i++
	brnzp	ciclo

; chiusura subprogram
diff
	ld	r2, max
	ld	r3, min
	not	r3, r3
	add	r3, r3, #1
 
	add	r0, r2, r3

; restore registri
	ld	r1, saver1
	ld	r2, saver2
	ld	r3, saver3
	ret

; VARIABILI E COSTANTI
max	.fill	x0000
min	.fill	x7FFF
saver1	.blkw	1
saver2	.blkw	1
saver3	.blkw	1

;************************************************************* END SUBPROGRAM

	.end