/*
 * Bluetooth.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */

#include "STD.h"
#include "UART.h"
#include"Bluetooth.h"

void Bluetooth_Send(uint8 data){
UART_TRANSMIT(data);
}
void Bluetooth_Init(uint16 baudRate){
	UART_INIT(baudRate);
}
void Bluetooth_Read(uint8 *ptr){
	UART_RECEIVE(ptr);
}
