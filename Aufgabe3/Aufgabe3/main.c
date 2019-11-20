/*
 * GccApplication1.c
 *
 * Created: 05.11.2019 15:19:01
 * Author : ds1818s
 */ 

#include <avr/io.h>

#define F_CPU 1000000UL

#include	<util/delay.h>



/*

 * Aufgabe3.c

 *

 * Created: 22.10.2019 12:46:37

 * Author : bruno

 */ 

int led_red = 0;
int led_yellow = 0;

void init()
{
	DDRD |= (0 << PD2) | (0 << PD3);
	PORTD |= (1 << PD2) | (1 << PD3);
	DDRB |= (1<< PB0) | (1 << PB1);
}

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



void polling()
{
		if (~PIND & (1 << PD2))
		{
			RedPressed();
		}

		if (~PIND & (1 << PD3))
		{
			YellowPressed();
		}
		
}



int main(void)

{
	init();
    while (1) 
    {
	
		polling();
		
		if (led_red == 1)
		{
			PORTB = (1 << PB0);
			_delay_ms(200);
			PORTB = (0 << PB0);
			
		}

		if (led_yellow == 1)
		{
			PORTB = (1 << PB1);
			_delay_ms(200);
			PORTB = (0 << PB1);
			
		}
		_delay_ms(200);
    }
}
