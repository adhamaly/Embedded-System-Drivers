/*
 * KEYPAD.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */

#include"STD.h"
#include <util/delay.h>
#include"DIO.h"
#include"KEYPAD.h"
#include"KEYPAD_CFG.h"

 uint8 keyValues[4][4] =
{
  {0x01,0x02,0x03,0b01000001},
  {0x04,0x05,0x06,0b01000010},
  {0x07,0x08,0x09,0b01000011},
  {0b00101010,0,0b00100011,0b01000100}
 };

uint8 KEYPAD_GetKey(void){

		uint8 key = 0 ;
		uint8 i,j;
		for(i = 0;i<4;i++){
			DIO_WritePin(PORT,i,LOW);
			  for(j = 4;j<8;j++){
				  if(DIO_ReadPin(PORT,j) == LOW){
					  key = keyValues[i-0][j-4];
					  while(DIO_ReadPin(PORT,j) ==0);
					  _delay_ms(10);

				  }
				  }
				DIO_WritePin(PORT,i,HIGH);
			  }
			  return key;


		// EASY WAY....
	/*

	 uint8 Key ;

		DIO_WritePort(PORT,0b11111110);
			if(DIO_ReadPin(PORT,C0) == LOW){
			Key  =KEY_1;
		}
		else if (DIO_ReadPin(PORT,C1)==LOW){
			Key = KEY_2;
		}
		else if (DIO_ReadPin(PORT,C2)==LOW){
				Key = KEY_3;
			}
		else if (DIO_ReadPin(PORT,C3)==LOW){
				Key = KEY_A;
			}

	DIO_WritePort(PORT,0b11111101);
	if(DIO_ReadPin(PORT,C0) == LOW){
		Key  =KEY_4;
	}
	else if (DIO_ReadPin(PORT,C1)==LOW){
		Key = KEY_5;
	}
	else if (DIO_ReadPin(PORT,C2)==LOW){
			Key = KEY_6;
		}
	else if (DIO_ReadPin(PORT,C3)==LOW){
			Key = KEY_B;
		}


	DIO_WritePort(PORT,0b11111011);
		if(DIO_ReadPin(PORT,C0) == LOW){
			Key  =KEY_7;
		}
		else if (DIO_ReadPin(PORT,C1)==LOW){
			Key = KEY_8;
		}
		else if (DIO_ReadPin(PORT,C2)==LOW){
				Key = KEY_9;
			}
		else if (DIO_ReadPin(PORT,C3)==LOW){
				Key = KEY_C;
			}



		DIO_WritePort(PORT,0b11110111);
					if(DIO_ReadPin(PORT,C0) == LOW){
					Key  =KEY_str;
				}
				else if (DIO_ReadPin(PORT,C1)==LOW){
					Key = KEY_0;
				}
				else if (DIO_ReadPin(PORT,C2)==LOW){
						Key = KEY_hash;
					}
				else if (DIO_ReadPin(PORT,C3)==LOW){
						Key = KEY_D;
					}

	return Key;
	*/
}

// complete function implementation....
