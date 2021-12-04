/*
 * Master.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */
#include "STD.h"
#include "Master.h"
#include "memmap.h"
#include "utils.h"
#include "DIO.h"
#include "I2C.h"


void Master_Init(uint8 divisionFactor){
/*no prescalar ..*/
	TWBR = divisionFactor;
}
uint8 Master_Start(uint8 S_address){
	uint8 status_Code ;
	/*this operation must initialized by master to start communication with slave (send start bit)*/
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN); /*must clear TWINT flag to start new operation*/
	while(GET_BIT(TWCR,TWINT) == 0); /*wait until start condition (start bit) transmitted*/
	 status_Code = TWSR & 0xF8; /*TWSR updated by control circuit after one cycle when flag rasied ..*/
	if(status_Code != START){
	return ERROR;
	}
	TWDR = S_address;  /*write SLA+W/R  used to enter needed Master mode.. in this situation enter MT mode , so load SLA+W into TWDR*/
		TWCR =  (1<<TWINT) | (1<<TWEN);/*must clear TWINT flag to start new operation*/
		while(GET_BIT(TWCR,TWINT) == 0);
		status_Code = TWSR & 0xF8 ;
		if(status_Code == MT_SLA_ACK){
			return ACK_REC;
		}
		else if(status_Code == MT_SLA_NACK){
			return NACK_REC;
		}
		else {
			return ACK_ERROR;
		}

}

uint8 Master_WriteDataPacket(uint8 data){
	uint8 status_Code ;
	/*writing data to TWDR must be before clear TWINT ..*/
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);  /*must clear TWINT flag to start new operation*/
	while(GET_BIT(TWCR,TWINT) ==0);
	status_Code = TWSR  & 0xF8 ;      /*TWSR updated by control circuit after one cycle when flag rasied ..*/
	if(status_Code == MT_DATA_ACK){
		return ACK_REC;
	}
	else if(status_Code == MT_DATA_NACK){
		return NACK_REC;
	}
	else {
		return ACK_ERROR;
	}
}
void Master_Stop(){
	/*this operation must initialized by master to stop communication with slave (send stop bit)*/
	TWCR = (1<<TWEN) |(1<<TWSTO) | (1<<TWINT);
	while(GET_BIT(TWCR,TWINT) ==0 );

}
uint8 Master_RepeatedStart(uint8 S_address){
	uint8 status_Code ;
		/*this operation must initialized by master to re-start communication with slave (send repeat start bit)*/
		TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN); /*must clear TWINT flag to start new operation*/
		while(GET_BIT(TWCR,TWINT) == 0); /*wait until repeat start condition (repeat start bit) transmitted*/
		 status_Code = TWSR & 0xF8; /*TWSR updated by control circuit after one cycle when flag raised ..*/
		if(status_Code != REP_START){
		return 0;
		}
		/*this operation to enter master receiver mode*/
		TWDR = S_address;  /*Write SLA+R in TWI data register */
		TWCR =  (1<<TWINT) | (1<<TWEN);/*must clear TWINT flag to start new operation*/
		while(GET_BIT(TWCR,TWINT) == 0);
		/*flag raised ..*/
		status_Code = TWSR & 0xF8 ;
		if(status_Code == SLAVE_ADDRESS_ACK){
			return 1;
		}
		else if(status_Code == SLAVE_ADDRESS_NACK){
			return 2;
		}
		else {
			return 3;
		}
}
/*Thoose functions used when I2C become in Master receiver mode to read data with and without ack ....*/
/*master receive data and send ack  , this form will be repeated until last byte sent */
void Master_Read_Ack(uint8* ptTwdr)
{
    TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA); /*receivce data and sent ack manualy by software
                                           to continue communication (to automatically send ack from master to slave)*/
    while(!(TWCR&(1<<TWINT)));    /* Wait until TWI finish its current job */
    *ptTwdr =  TWDR;            /* Return received data */
}
/* master receive data from slave and send Not ACK to slave to end communication , then master send stop bit or repeated start bit  */
void Master_Read_Nack(uint8* ptTwdr)        /* I2C read nack function */
{
    TWCR=(1<<TWEN)|(1<<TWINT);    /* Enable TWI and clear interrupt flag */
    while(!(TWCR&(1<<TWINT)));    /* Wait until TWI finish its current job */
    *ptTwdr  = TWDR;        /* Return received data */
}
