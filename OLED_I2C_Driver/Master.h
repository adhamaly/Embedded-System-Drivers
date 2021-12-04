/*
 * Master.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */

#ifndef MASTER_H_
#define MASTER_H_

/*status code of TWSR*/
#define START 0x08
#define REP_START 0x10
#define MT_SLA_ACK 0x18
#define MT_SLA_NACK 0x20
#define MT_DATA_ACK 0x28
#define MT_DATA_NACK 0x30
#define SLAVE_ADDRESS_ACK 0x40
#define SLAVE_ADDRESS_NACK 0x48
#define ERROR 0
#define ACK_REC 1
#define NACK_REC 2
#define ACK_ERROR 3






void Master_Init(uint8 divisionFactor); /*clock generation */
uint8 Master_Start(uint8 S_address);/*start condition transmit*/
uint8 Master_WriteDataPacket(uint8 data); /*write data byte*/
uint8 Master_RepeatedStart(uint8 S_address); /*repeat start condition for bus arbitration ..*/
void Master_Stop(); /*stop condition*/
void Master_Read_Nack(uint8* ptTwdr); /* Master I2c read nack function */
void Master_Read_Ack(uint8* ptTwdr);     /* Master I2C read ack function */
#endif /* MASTER_H_ */
