/*
 * TempSensor.h
 *
 *  Created on: 25/6/2018
 *      Author: Karim Sharabash
 *
 *    this is a header file for Temperature sensor (LM35) which represent every 1 degree celsius by 10 mv
 *    the atmega32 has 10 bit ADC
 *    and i will use the 5 v (AVCC) reference
 *    so the resolution in the ADC reading = (5000/1024) mv
 */

#ifndef HAL_TEMPSENSOR_H_
#define HAL_TEMPSENSOR_H_
#include "../MCAL/ADC.h"
#include "../Service/data_types.h"

void TempSensor_Init(void);

uint16 TempSensor_Read(void);
void Convert_Int_to_String(uint16 integer , sint8 *string);
void Temp_callback_fun(void (*fun_ptr)(void));


#endif /* HAL_TEMPSENSOR_H_ */
