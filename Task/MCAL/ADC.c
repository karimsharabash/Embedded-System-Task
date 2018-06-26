/*
 * ADC.c
 *
 *  Created on: 24/6/2018
 *      Author: Karim Sharabash
 *
 *      The implementations of the ADC APIs .
 */
#include "ADC.h"

void (*ADC_INT_FUN_PTR)(void);

void ADC_Init()
{
	/*
	 * this API to enable the ADC
	 * enable ADC interrupt and auto triggering
	 *  adjust the prescaler (128 division factor )
	 */

	ADCSRA=(1<<ADEN)|(1<<ADATE)| (1<<ADIE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);

	SFIOR =(1<<ADTS0)|(1<<ADTS2); // select timer 1 compare match B as a auto triggering source

	TCCR1B=(1<<CS10)|(1<<CS12) ; // enable timer 1 with prescaler 1024
    TCCR1A=(1<<COM1B0);          //CTC Mode , Toggle OC1B on compare match
    TCNT1=0;                     // clear timer 1 counter register
    OCR1B=23437;                 // to make the ADC triggered every 3 s

	ADMUX=1;		        //  select ADC channel
	ADMUX|=(1<<REFS0);        // AVCC=5VA  (default if u didn't choose 2.56 v)

}


ISR(ADC_vect)
{
 ADC_INT_FUN_PTR();  //call the function that will be passed via this pointer

 TIFR|=(1<<OCF1B);  //clear the output compare match flag because it will not be auto-cleared
 TCNT1=0;           // clear timer 1 counter register
}
