/*
 * spi.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */

#ifndef SPI_H_
#define SPI_H_
/*SPSR REGISTER BITS..*/
#define SPSR_SPI2X 0
#define SPSR_WCOL 6
#define SPSR_SPIF 7

/*SPI PINS CONFIG*/
#define MOSI 5
#define MISO 6
#define SCK 7
#define SS 4

typedef enum{
	SPR0 =0,
	SPR1,
	CPHA,
	CPOL,
	MSTR,
	DORD,
	SPE,
	SPIE
}SPCR_R;

void SPI_MasterInit(void);
uint8 SPI_MasterTransfer(uint8 );
void SPR_MasterTransmit(uint8);
uint8 SPI_MasterReceive(void);
void SPI_SlaveInit(void);
uint8 SPI_SlaveTransfer(uint8);
void SPI_SlaveTransmit(uint8);
uint8 SPI_SlaveReceive(void);





#endif /* SPI_H_ */
