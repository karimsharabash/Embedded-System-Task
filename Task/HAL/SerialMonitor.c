/*
 * SerialMonitor.c
 *
 *  Created on: 25/6/2018
 *      Author: Karim Sharabash
 */

#include "SerialMonitor.h"

void SerialMonitor_Init(void)
{
	Uart_init(SM_Baudrate);  //initialize the uart with baudrate 9600 b/s
}
void Send_To_SerialMonitor_String(sint8 message[10])
{
	uint8 Index=0;
	while(message[Index])   //while there is another character in the string don't get out the loop
	{
		UART_send_Data(message[Index]);  // send the character foe the current index then increment the index so the next iteration send another one
		Index++;
	}
}
