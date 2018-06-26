/*
 * TempSensor.c
 *
 *  Created on: 25/6/2018
 *      Author: Karim Sharabash
 */

#include "TempSensor.h"

void TempSensor_Init(void)
{
	ADC_Init();  // initialize the ADC ,the timer to trigger the ADC , choose the channel , and the voltage ref
}

/*
 *
 *    the LM35 represent every 1 degree celsius by 10 mv
 *    the atmega32 has 10 bit ADC
 *    and i will use the 5 v (AVCC) reference
 *    so the resolution in the ADC reading = (5000/1024) mv
 */

uint16 TempSensor_Read(void)
{
	uint16 Temp_Reading=0;

	Temp_Reading=(ADC*(5000/1024))/10; // which will give us the reading in celsius

	return Temp_Reading;
}


/*
 * this function i will use it to convert the value of the temperature to string of ascii representation so the serial monitor
 * can understand it and display it as a integers
 */
void Convert_Int_to_String(uint16 integer , sint8 string[3])
{

	// take the unit place and add to 48 which is the value of '0' in the ascii  representation, and put it in the index 1 so the number print correctly

	string[1]=(integer%10)+48 ;
	integer/=10;
	// take the tens place and add to 48 which is the value of '0' in the ascii  representation, and put it in the index 0 so the number print correctly
	string[0]=(integer%10)+48 ;

	string[2]='\0';
}

void Temp_callback_fun(void (*fun_ptr)(void))
{
	/*
	 * to preserve the modularity of the design i used a global pointer to function to pass
	 * the function i want to be done when the ADC interrupt is triggered
	 * ADC_INT_FUN_PTR
	 */

	 ADC_INT_FUN_PTR=fun_ptr;
}
