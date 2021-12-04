/*
 * EEPROM.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */

#ifndef EEPROM_H_
#define EEPROM_H_


void Init_Epprom(uint8 divisionVactor);
void Epprom_Write(uint8 Ep_address,uint8 Word_address,uint8 data);
void Epprom_Read(uint8 Ep_address,uint8 Word_address,uint8* ptr);


#endif /* EEPROM_H_ */
