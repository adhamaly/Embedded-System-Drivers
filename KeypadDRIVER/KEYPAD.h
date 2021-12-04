/*
 * KEYPAD.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

typedef enum{
	KEY_0 = 0,
	KEY_1,
	KEY_2,
	KEY_3,
	KEY_4,
	KEY_5,
	KEY_6,
	KEY_7,
	KEY_8,
	KEY_9,
	KEY_str,
	KEY_hash,
	KEY_A,
	KEY_B,
	KEY_C,
	KEY_D

} KEYPAD_t;
uint8 KEYPAD_GetKey(void);
#endif /* KEYPAD_H_ */
