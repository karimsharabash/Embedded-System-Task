/*
 * UART.c
 *
 *  Created on: 24/6/2014
 *      Author: Karim Sharabash
 */

#include "UART.h"

void Uart_init(uint32 BaudRate)
	{

		uint16 BRvalue=0;
		UCSRB=(1<<RXEN)|(1<<TXEN); // enable reciever and transmitter

		//Set data frame format: asynchronous mode,no parity, 1 stop bit, 8 bit size
		UCSRC=(1<<URSEL)|(0<<UMSEL)|(0<<UPM1)|(0<<UPM0)|(0<<USBS)|(0<<UCSZ2)|(1<<UCSZ1)|(1<<UCSZ0);

		BRvalue=((F_CPU/(16UL*BaudRate))-1); // to calculate the value of the baud rate reg
		UBRRL=BRvalue; 			//low byte
	    UBRRH=(BRvalue>>8); 	//high byte
	}

void UART_send_Data( uint8 byte)
 {
	while(!(UCSRA &(1<<UDRE))); // while shift register flag != 1 (not empty))
	UDR=byte;
 }


 char  UART_recieve_Data(void)
 {
	while((UCSRA & (1<<RXC)) ==0); //check for the recieve flag . this flag cleared automatic after taking the byte from the buffer

		return UDR ;


 }


