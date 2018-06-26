/*
 * SerialMonitor.h
 *
 *  Created on: 25/6/2018
 *      Author: Karim Sharabash
 *
 *    this is a header file for the serial monitor which is my lap top ,which i will connect the microcontroller to it
 *    using USBTTL by UART communication protocol using baudrate 9600
 */

#ifndef HAL_SERIALMONITOR_H_
#define HAL_SERIALMONITOR_H_

#define SM_Baudrate 9600
#include "../MCAL/UART.h"
#include "../Service/data_types.h"

void SerialMonitor_Init(void);
void Send_To_SerialMonitor_String(sint8 *message);

#endif /* HAL_SERIALMONITOR_H_ */
