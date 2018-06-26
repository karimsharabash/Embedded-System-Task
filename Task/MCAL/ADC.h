/*
 * ADC.h
 *
 *  Created on: 24/6/2018
 *      Author: Karim Sharabash
 *
 *      this is a header file for the ADC Driver for AVR atmega32 microcontroller .
 *
 *      it contains two APIs
 *         ADC_Init      for adjusting the setting for the ADC.
 *         ADC_Read      to choose the channel to read the analog signal from ,and choose the voltage reference to use
 *                       this microcontroller give us two options (AVCC (5v) or 2.56 v )
 *                       then start reading and don't return from the function till the reading finished .
 */

#ifndef ADC_H_
#define ADC_H_

 #include <avr/io.h>
#include "../Service/data_types.h"
#include <avr/interrupt.h>
extern void (*ADC_INT_FUN_PTR)(void);
void ADC_Init();

#endif /* MY_ADC_H_ */
