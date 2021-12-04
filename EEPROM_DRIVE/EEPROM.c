/*
 * EEPROM.c
 *
 *  Created on: ??ş/??ş/????
 *      Author: adham
 */

#include "STD.h"
#include "memmap.h"
#include "I2C.h"
#include "Master.h"
#include "EEPROM.h"

void Init_Epprom(uint8 divisionVactor){
Master_Init(10); /*check the scl frequency*/
}
void Epprom_Write(uint8 Ep_address,uint8 Word_address,uint8 data){
	uint8 status;
	status = Master_Start(Ep_address);
	if(status == 1){
		status = Master_Write(Word_address);
		if(status ==1){
		status =Master_Write(data);
			if(status == 2){
				Master_Stop();
			}

		}

	}
}
void Epprom_Read(uint8 Ep_address,uint8 Word_address,uint8* ptr){
	uint8 status;
		status = Master_Start(Ep_address);
		if(status == 1){
			status = Master_Write(Word_address);
			if(status == 1){
				status = Master_RepeatedStart(0b10100001);
					if(status == 1){
						Master_Read_Nack(ptr);
					}
			}
		}

}

