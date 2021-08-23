/*
 * UART.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */

#ifndef UART_H_
#define UART_H_

typedef enum{
	MPCM = 0,
	U2X,
	PE,
	DOR,
	FE,
	UDRE,
	TXC,
	RXC
}UCSRA_R;

typedef enum{
		TXB8 = 0,
		RXB8,
		UCSZ2,
		TXEN,
		RXEN,
		UDRIE,
		TXCIE,
		RXCIE

}UCSRB_R;

typedef enum{
	UCPOL  = 0,
	UCSZ0,
	UCSZ1,
	USBS,
	UPM0,
	UPM1,
	UMSEL,
	URSEL

}UCSRA_C;

void UART_INIT(uint16);
void UART_TRANSMIT(uint8 data);
void UART_TRANSMIT_STRING(uint8* string);
uint8 UART_RECEIVE(void);



#endif /* UART_H_ */
