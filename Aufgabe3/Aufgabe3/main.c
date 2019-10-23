#include <avr/io.h>
#define F_CPU 16000000UL
#include	<util/delay.h>

/*
 * Aufgabe3.c
 *
 * Created: 22.10.2019 12:46:37
 * Author : bruno
 */ 

int led_1 = 0;
int led_2 = 0;

void init()
{
	DDRD |= (0 << PD2) | (0 << PD3);
	PORTD |= (1 << PD2) | (1 << PD3);
	DDRB |= (1<< PB0) | (1 << PB1);
}

int polling()
{
	while(1) //(PIND2 == 1 && PIND3 == 1)
	{
		if (~PIND & (1 << PD2))
		{
			return 0;
		}
		if (~PIND & (1 << PD3))
		{
			return 1;
		}
	}
	
}
void switch_led_1()
{
	if(led_1 == 0)
	{
		led_1 = 1;
		//PORTB |= (1 << PB0);
		led_2 = 0;
		//PORTB &= (0 << PB1);
		
	}
	else
	{
		led_1 = 0;
		//PORTB &= (0 << PB0);
	}
	
	};
	
void switch_led_2()
{
	if(led_2 == 0)
	{
		led_2 = 1;
		//PORTB |= (1 << PB1);
		led_1 = 0;
		//PORTB &= (0 << PB0);
	}
	else
	{
		led_2 = 0;
		//PORTB &= (0 << PB1);
	}
	};
	


int main(void)
{
	init();
    while (1) 
    {
		if (polling() == 0)
		{
			switch_led_1();
		}
		else
		{
			switch_led_2();
		}
		
		
		if (led_1 == 1)
		{
			PORTB |= (1 << PB0);
			_delay_ms(100);
			PORTB |= (0 << PB0);
			_delay_ms(100);
		}
		
		if (led_2 == 1)
		{
			PORTB |= (1 << PB1);
			_delay_ms(100);
			PORTB |= (0 << PB1);
			_delay_ms(100);
		}
		
    }
}


