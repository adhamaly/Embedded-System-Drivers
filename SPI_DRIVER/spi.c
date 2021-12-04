/*
 * spi.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */
#include"STD.h"
#include "memmap.h"
#include "utils.h"
#include "DIO.h"
#include "spi.h"

/*common driver*/

void SPI_MasterInit(void){
/*
 1_configure pin direction
  [MOSI,SS,SCLK] == OUTPUT
  [MISO] == INPUT

  2_ ENALBE SPI (SPCR_SPE)
   _ENABLE MASTER (MSTR)
   all spcr in one line like uart

  CONFIGURE CLOCK [RATE = CPU/128] ,[polarity , phase]

  // make slave sleep by writing high

 **/

	DIO_SetPinDirection(PB,MOSI,OUT);
	DIO_SetPinDirection(PB,SS,OUT);
	DIO_SetPinDirection(PB,SCK,OUT);
	DIO_SetPinDirection(PB,MISO,INFREE);

	SPCR = 0b01010011;
	DIO_WritePin(PB,SS,HIGH);


}
// full duplex ..
uint8 SPI_MasterTransiever(uint8 data){

	/*
	 * 1_ write low slave select pin
	 * 2_write data in SPDR (8-bit) // clock on synch and shifting occur
	 * 3_polling until SPIF rasied ==> mean transfer compelete
	 * 4_write high slave select pin
	 * 5_read data from SPDR then return it
	 *
	 *
	 * */
}
//  simplex
void SPR_MasterTransmit(uint8 data){
	/*
	 * 1_write LOW on ss
	 * 2_write data to transmit on SPDR
	 * 3_polling for SPIF
	 * 4_ read (SPDR) to clear flag "unused data"
	 * 5_sleep slave by write high on ss
	 *
	 *
	 * */
	uint8 d = 0;
	DIO_WritePin(PB,SS,LOW);
	SPDR = data;
	while(GET_BIT(SPSR,SPSR_SPIF) == 0);
	d = SPDR;
	DIO_WritePin(PB,SS,HIGH);

}

// simplex
uint8 SPI_MasterReceive(void){
/*
 * write on pin ss low (slave writing)
 * writing dummy data on SPDR (CLOCK GENERATED)
 * wait until SPIF flag raised
 * sleep slave byw write high on ss
 * read SPDR
 * */

	return SPDR;
}

void SPI_SlaveInit(void){
/*
 1_configure pin direction
  [MOSI,SS,SCLK] == input
  [MISO] == output

  2_ ENALBE SPI (SPCR_SPE)
    **/


	DIO_SetPinDirection(PB,MOSI,INFREE);
	DIO_SetPinDirection(PB,SS,INFREE);
	DIO_SetPinDirection(PB,SCK,INFREE);
	DIO_SetPinDirection(PB,MISO,OUT);

SET_BIT(SPCR,SPE);
}
uint8 SPI_SlaveTransfer(uint8 data){


}
// slavereceive & slave tarnsmit
uint8 SPI_SlaveReceive(void){
	/* writing dummy data on SPDR (CLOCK GENERATED)
	 * wait until SPIF flag raised
	 * read SPDR
	 * */
uint8 d  = 0;
	SPDR = 0xff;
	while(GET_BIT(SPSR,SPSR_SPIF) == 0);
	d = SPDR;
	return d;




}





