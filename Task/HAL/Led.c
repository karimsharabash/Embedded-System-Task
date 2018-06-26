/*
 * Led.c
 *
 *  Created on: 24/6/2018
 *      Author: Karim Sharabash
 */
#include "Led.h"

void Led_Init(void)
{
	Make_Pin_Op(D,Light_pin);  //to configure the pin as output
	  Set_Pin(D,Light_pin);

}
void Led_on(void)
{
    Set_Pin(D,Light_pin);     // clear the pin so the led will light up
}

void Led_off(void)
{
	Clear_Pin(D,Light_pin);   // set the pin so the led will shut down
}

void Led_toggle(void)
{
	Toggle_Pin(D,Light_pin);   //toggle the pin so th led will change its state
}

uint8 Led_ON_or_OFF(void)
{
	if(Read_Pin(D,Light_pin))  //if the pin output is high so the led is off
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

