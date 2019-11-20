/*
 * Aufgabe4.c
 *
 * Created: 19.11.2019 16:14:07
 * Author : bruno
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned int millisekunden;
volatile unsigned int sekunde;

int main(void)
{
	DDRD |= (1 << PD3 | 1 << PD4 | 1 << PD5);
	
	  // Timer 0 konfigurieren
  
	  TCCR0A = (1<<WGM01); // CTC Modus
	  TCCR0B |= (1<<CS01); // Prescaler 8 //setzt timer in betrieb 
  
	  // ((1000000/8)*0,001)-1 = 124
	  OCR0A = 124;

	  // Compare Interrupt erlauben
	  TIMSK |= (1<<OCIE0A);

	  // Global Interrupts aktivieren
	  sei();

	  while(1)
	  {
		waitUntil(5000+millisekunden);
		
		PORTD = (1 << PD4);
		
		waitFor(10000);
		
		PORTD = (0 << PD4);
		
		waitUntil(5000+millisekunden);
	  }
}

waitFor(int32_t ms)
{
	unsigned int wait = millisekunden + ms;
	while(wait >= millisekunden)
	{
		PORTD = (1 << PD3);
	}
	PORTD = (0 << PD3);
}

waitUntil(int32_t ms)
{
	while(millisekunden <= ms)
	{
		PORTD = (1 << PD5);
	}
	PORTD = (0 << PD5);
}

#ifndef TIMER0_OVF_vect

ISR (TIMER0_OVF_vect)
{
  /*
  Der Compare Interrupt Handler
  wird aufgerufen, wenn
  TCNT0 = OCR0A = 125-1
  heißt nach 1ms.
  */
  
  millisekunden++;
  if(millisekunden = 1000)
  {
	  sekunden++;
  }
  
  
  
}