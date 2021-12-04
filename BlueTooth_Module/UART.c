/*
 * UART.c

 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */
#include "STD.h"
#include "memmap.h"
#include "utils.h"
#include "DIO.h"
#include "UART.h"



void UART_INIT(uint16 baud){
	/* Set baud rate */
	UBRRH = (uint8)(baud>>8);
	UBRRL = (uint8)baud;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: set select register  , 2stop bit,8data */
	UCSRC = (1<<URSEL)|(3<<UCSZ0);
}
void UART_TRANSMIT(uint8 data){
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) );
	/* Put data into buffer, sends the data */
	UDR = data;
}
void UART_RECEIVE(uint8 * ptr_data){
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) );
	/* Get and return received data from buffer */
	*ptr_data =  UDR;
}
void UART_TRANSMIT_STRING(uint8 *string)
{
	while(*string)
	{
		UART_TRANSMIT(*string++);
	}
}


