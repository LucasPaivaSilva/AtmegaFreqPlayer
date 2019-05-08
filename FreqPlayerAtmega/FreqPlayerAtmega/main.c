/*
 * FreqPlayerAtmega.c
 *
 * Created: 5/7/2019 6:33:27 PM
 * Author : Lucas
 */ 

int k=0;
#include <avr/io.h>
#include <math.h>
#include <avr/interrupt.h>
#include "def_principais.h"

void delay_ms( int ms )
{
	for (int i = 0; i < ms; i++)
	{
		_delay_ms(1);
	}
}

ISR(TIMER1_COMPA_vect)
{
	cpl_bit(PORTB, PB0);
}

void beep(int freq, int length)
{
	OCR1A = round(((16000000/freq)-1024)/2048);
	sei();
	delay_ms(length);
	cli();
	clr_bit(PORTB, PB0);
}

int main(void)
{
	DDRB = 0xFF;		
	PORTB = 0xFF;
	
	TCNT1 = 0;									 
	OCR1A = 15624;								 
	TCCR1B = (1<<CS10) | (1<<CS12) | (1<<WGM12); 
	TIMSK1 = (1<<OCIE1A);						 
	
	sei();
    while (1) 
    {
		
		beep(1, 1000);
		_delay_ms(1000);
		beep(2, 1000);
		_delay_ms(1000);
		beep(3, 1000);
		_delay_ms(1000);
		beep(4, 1000);
		_delay_ms(1000);
		beep(5, 1000);
		_delay_ms(1000);
		beep(6, 1000);
		_delay_ms(1000);
		beep(7, 1000);
		_delay_ms(1000);
		beep(8, 1000);
		_delay_ms(1000);
		beep(9, 1000);
		_delay_ms(1000);
		beep(10, 1000);
		_delay_ms(1000);
		
	}
}

