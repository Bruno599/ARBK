/*
 * aufgabe3b.c
 *
 * Created: 12.11.2019 14:55:32
 * Author : bruno
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <avr/interrupt.h>
#include <util/delay.h>

volatile int led_red = 0;
volatile int led_yellow = 0;
	
void RedPressed()
{
	if (led_red == 1)
	{
		led_red = 0;
	}
	else 
	{
		led_red = 1;
	}
	led_yellow = 0;
	
}

void YellowPressed()
{
	if (led_yellow == 1)
	{
		led_yellow = 0;
	}
	else
	{
		led_yellow = 1;
	}
	led_red = 0;
	
}

int main(void)
{
	DDRB |= (1 << PB0 ) | (1 << PB1);
	PORTD |= (1 << PD2) | (1 << PD3);
	
	GICR = (1 << INT0) | (1 << INT1); //Global INterrupt Controll 
	MCUCR = (0<<ISC00) | (1 << ISC01) | (0<<ISC10) | (0<<ISC11); //Pruefe auf fallende Flanke
	sei();
	
    while (1) 
    {
		if(led_red == 1)
		{
			PORTB = (1 << PB0);
			_delay_ms(200);
			PORTB = (0 << PB0);
		}
		
		if(led_yellow == 1)
		{
			PORTB = (1 << PB1);
			_delay_ms(200);
			PORTB = (0 << PB1);
		}
		_delay_ms(200);
    }
}

ISR(INT0_vect)
{
	RedPressed();
}

ISR (INT1_vect)
{
	YellowPressed();
}

