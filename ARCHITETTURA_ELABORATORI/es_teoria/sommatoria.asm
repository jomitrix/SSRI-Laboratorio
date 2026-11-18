	.orig x41F9
; programma di somma degli elementi di un array di numeri terminato da zero

	LEA	R0, ARRAY	; R0 = ^array
	AND	R2, R2, #0	; R2 = sommatoria
CICLO	LDR	R1, R0, #0	; R1 = elemento corrente array
	BRZ	FINE

; se sono arrivato qui: elemento diverso da zero (si somma)
	ADD	R2, R2, R1
	ADD	R0, R0, #1	; R0 = ^elemento successivo dell'array
	BRNZ	CICLO

; qui c'è elemento zero quindi ho finito
FINE	ST	R2, SOMMA
STOQUI	BRNZP	STOQUI

; zona variabili e costanti
SOMMA	.blkw	1
ARRAY	.fill	12
	.fill	-7
	.fill	45
	.fill	-72
	.fill	0

	.end