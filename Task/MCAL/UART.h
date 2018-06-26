/*
 * UART.h
 *
 *  Created on: 24/6/2014
 *      Author: Karim Sharabash
 *
 *    Header file for the UART driver for atmega32 has the declaration  of the driver APIs
 *    which are :
 *     INIT : to adjust the UART setting
 *     Send_Data : to send one byte
 *     receive_Data : to receive one byte
 *
 */

#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include "../Service/data_types.h"
void Uart_init(uint32 BaudRate);
void UART_send_Data( uint8 byte);
char UART_receive_Data(void);

#endif /* UART_H_ */
