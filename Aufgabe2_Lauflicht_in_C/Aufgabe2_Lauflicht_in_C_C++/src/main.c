#include <avr/io.h>
#define F_CPU 16000000UL
#include	<util/delay.h>

void led_off(int led);
void led_on (int led);

int main (void)
{
	DDRD |= (1 << PD3 | 1 << PD4 | 1 << PD5);
	
	while(1)
	{
		//PORTB ^= (1 << PB0);
		//_delay_ms(200);
		
		int i;
		for(i = 0; i < 3; i++)
		{
			led_on(i);
			//_delay_ms(200);
			led_off(i);
		}
		
		//i = 2;
		
		for(i = 1; i > 0; i--)
		{
			led_on(i);
			//_delay_ms(200);
			led_off(i);
		}
	}
	return 0;
}

void led_on (int led)
{
	//PORTD.bit(led) = 1
	
	//PORTD ^= (1 << PD(led));
	
	if(led == 0){PORTD = (1 << PD3);}
	else if(led == 1){PORTD = (1 << PD4);}
	else if(led == 2){PORTD = (1 << PD5);}
}

void led_off(int led)
{
	//PORTD.bit(led) = 0
	
	//PORTD ^= (0 << PD(led));
	
	if(led == 2){PORTD = (0 << PD5);}
	else if(led == 1){PORTD = (0 << PD4);}
	else if(led == 0){PORTD = (0 << PD3);}
}