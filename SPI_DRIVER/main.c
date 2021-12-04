/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */
#include "STD.h"
#include "DIO.h"
#include "spi.h"

int main(void){
	DIO_SetPinDirection(PA,Pin0,OUT);

	SPI_MasterInit();
   //SPI_SlaveInit();
	while(1){
		SPR_MasterTransmit(15);
	//	uint8 rec = SPI_SlaveReceive();
		//if(rec == 15){
			//DIO_WritePin(PA,Pin0,HIGH);
		//}

	}
	return 0;
}


