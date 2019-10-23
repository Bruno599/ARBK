;
; Aufgabe1_Lauflicht_in_Assembler.asm
;
; Created: 12.10.2019 11:31:22
; Author : Bruno
;


.INCLUDE <m328pdef.inc>; Controller Konstanten (z.B. RAMEND) 
.CSEG; Hinweis an Assembler hier kommt Code 

; Replace with your application code

.ORG 0x000
rjmp START; Bei reset springe nach adresse start

.ORG INT_VECTORS_SIZE

start: ;10min

	ldi r16, high(RAMEND); RAMEND definiert in m328pdef.inc 
	out SPH, r16; Oberes Byte des Stackpointer setzen 
	ldi r16, low(RAMEND) 
	out SPL,r16; Unteres Byte des Stackpointer setzen 

	//ldi r16,0b00011100
	ldi r16,0b11100000
	out DDRD, r16
	

main: ;20 min 

	sbi PortD, 5; SBI kann direkt an der stelle den Port setzen 
	rcall delay
	cbi PortD, 5
	sbi PortD, 6
	rcall delay
	cbi PortD, 6
	sbi PortD, 7
	rcall delay
	cbi PortD, 7
	sbi PortD, 6
	rcall delay
	cbi PortD, 6

	rjmp main


delay: ;30min 

	ldi r17, 17
loop0:
	ldi r18, 252
	rcall loop1
	dec r17
	brne loop0
	ret
loop1:
	ldi r19, 250
	rcall loop2
	dec r18
	brne loop1
	ret
loop2:
	dec r19
	brne loop2
	ret
	
	



    
