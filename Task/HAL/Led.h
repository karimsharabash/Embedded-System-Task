/*
 *   Led.h
 *
 *  Created on: 24/6/2018
 *      Author: Karim Sharabash
 *
 *
 *      header file for led driver to declare the driver APIs
 *      which is connected to PORTD pin4
 *      and the led is connected to microcontroller with one side and the other side to VCC
 *      so it need 0v from the microcontroller to light
 */

#ifndef LED_H_
#define LED_H_
#include "../MCAL/DIO.h"
#include "../Service/data_types.h"
#define  Light_pin 5


void Led_Init(void);

void Led_on(void);

void Led_off(void);
void Led_toggle(void);
uint8 Led_ON_or_OFF(void);

#endif /* LED_H_ */
