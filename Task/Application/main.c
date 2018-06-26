/*
 * main.c
 *
 *  Created on: 24/6/2018
 *      Author: Karim Sharbash
 */

#include "../HAL/Led.h"
#include "../HAL/Switchs.h"
#include "../Service/data_types.h"
#include "../HAL/TempSensor.h"
#include "../HAL/SerialMonitor.h"

volatile uint8 Pressed =0; //flag for the switch
volatile uint8 new_reading=0; // flag for the temperature sensor readings
volatile uint16 Temparture=0; //to carry the value of the temperature in celsius

void System_Init(void); //function that has all the devices initialization
void Switch_Task(void); //the function that will toggle the led and raise the switch flag (Pressed)
void Temperature_Task(void); // the function that will happen every 3 s , to take a new reading from the adc
void Switch_function(void); // the function that will happen when the switch flag(pressed) is raised


int main (void )
{
	sint8 Temp_String[4]; //string to hold the temperature as a characters (ASCII rep ) not as a integers

	System_Init();

	Switch_callback_fun(Switch_Task); //pass the switch task to external interrupt ISR so it can call it in the MCAL layer
    Temp_callback_fun(Temperature_Task); //pass the Temperature task to ADC interrupt ISR so it can call it in the MCAL layer
	sei(); //enable global interrupts
	while(1)
	{
		if(Pressed==1) //if the switch flag is raised
		{

         Switch_function(); //send message to the serial monitor and check the led state and send it to the serial monitor
        	Pressed=0;      //clear the flag
		}

		if(new_reading==1) // if there is a new reading from the ADC
		{
			Convert_Int_to_String(Temparture,Temp_String); //convert the reading into a string
			Send_To_SerialMonitor_String(Temp_String);  //send it to the serial monitor
			Send_To_SerialMonitor_String(" c \n");
			new_reading=0;   //clear the new reading flag

		}

	}
	return 0;
}

void Switch_Task(void)
{
	Pressed =1;  //raise the flag
	Led_toggle();

}

void Temperature_Task(void)
{
 new_reading=1;  //raise the flag
 Temparture=TempSensor_Read();

}

void System_Init(void)
{
	TempSensor_Init();
	Switch_Init();
	Led_Init();
	SerialMonitor_Init();
}

void Switch_function(void)
{
	Send_To_SerialMonitor_String("pressed\n");


		if(Led_ON_or_OFF())
		{
			Send_To_SerialMonitor_String("ON\n");
		}
		else
		{
			Send_To_SerialMonitor_String("OFF\n");
		}


}
