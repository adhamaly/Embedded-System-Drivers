/*
 * Bluetooth.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */

#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

void Bluetooth_Init(uint16 baudRate);
void Bluetooth_Send(uint8 data);
void Bluetooth_Read(uint8 *ptr);
#endif /* BLUETOOTH_H_ */
