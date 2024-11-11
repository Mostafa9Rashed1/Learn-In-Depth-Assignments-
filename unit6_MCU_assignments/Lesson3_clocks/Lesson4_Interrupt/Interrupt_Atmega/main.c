/*
 * Interrupt test atmega 32
 * 
 * Created: 11/11/2024 7:00:03 PM
 *  Author: Mostafa Rashed kamel
 */ 
#define F_CPU 8000000ul
#include <xc.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

ISR(INT0_vect)
{
	PORTD |=(1<<5);
	_delay_ms(1000);
		
}

ISR(INT1_vect)
{
	PORTD |=(1<<6);
	_delay_ms(1000);
	
}

ISR(INT2_vect)
{
	PORTD |=(1<<7);
	_delay_ms(1000);
}

int main(void)
{
	// set Pins 5,6,7 in Porr D as output
	DDRD |= (1<<5) | (1<<6) | (1<<7);
	
	/* Int0 any change*
	   Int 1 /rising edge*/
	   
	MCUCR |= (1<<0);
	MCUCR &= ~(1<<1);
	MCUCR |= (1<<2);
	MCUCR |= (1<<3);
	
	// Int 2 falling edge
	MCUCSR &= ~(1<6);
	
	// Set general inrerrupt control register 
	GICR |= (1<<5) | (1<<6) | (1<<7);
	
	sei();   // enable SREG [global interrupt enable]
    while(1)
    {
		//reset leds 5, 6, 7
		PORTD &=~((1<<5) | (1<<6) | (1<<7));
		_delay_ms(1000);
    }
}