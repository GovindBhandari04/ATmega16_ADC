/*
 * ADC.c
 *
 * Created: 8/19/2023 2:19:13 PM
 * Author : Govind
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void)
{
   sei();
   TCCR1A |= (1<<WGM10)|(1<<WGM11);
   TCCR1B |= (1<<WGM12);
   TCCR1B &= ~(1<<WGM13);
   TCCR1A |= (1<<COM1A1);
   TCCR1A &= ~(1<<COM1A0);
   TCCR1B |= (1<<CS10)|(1<<CS11);
   TCCR1B &= ~(1<<CS12);
   DDRD |= (1<<DDD5);
   
   ADCSRA |= (1<<ADEN)|(1<<ADIE)|(1<<ADATE);
   ADMUX |= 0X04;
   ADCSRA |= (1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
   ADCSRA |= (1<<ADSC);
   
    while (1) 
    {
    }
}

ISR(ADC_vect)
{
	OCR1A = ADC;
}
