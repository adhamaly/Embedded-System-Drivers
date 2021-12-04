/*
 * OLED.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */

#ifndef OLED_H_
#define OLED_H_

/* macros commands */
#define SSD1306_SETCONTRAST   0x81
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON 0xA5
#define SSD1306_NORMALDISPLAY 0xA6
#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_DISPLAYON 0xAF
#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETCOMPINS 0xDA
#define SSD1306_SETVCOMDETECT 0xDB
#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETPRECHARGE 0xD9
#define SSD1306_SETMULTIPLEX 0xA8
#define SSD1306_SETSTARTLINE 0x40
#define SSD1306_COMSCANDEC 0xC8
#define SSD1306_SEGREMAP 0xA0
#define SSD1306_CHARGEPUMP 0x8D
#define SSD1306_MEMORYMODE 0x20
#define SSD1306_SET_COLUMN_ADDR	 0x21
#define SSD1306_SET_PAGE_ADDR	0x22
#define SSD1306_SET_CONTRAST_CONTROL	0x81

/*macros to find the mod of a number
 ****************************************************************************************************/
#define util_GetMod8(dividend,divisor)  (uint8) (dividend - (divisor * (uint8) (dividend/divisor)))
#define util_GetMod16(dividend,divisor) (uint16)(dividend - (divisor * (uint16)(dividend/divisor)))
#define util_GetMod32(dividend,divisor) (uint32)(dividend - (divisor * (uint32)(dividend/divisor)))
/***************************************************************************************************/

/***************************************************************************************************
 Macros for Dec2Ascii,Hec2Ascii and Acsii2Hex conversion
 *****************************************************************************************************/
#define util_Dec2Ascii(Dec)     ((Dec)+0x30)
#define util_Ascii2Dec(Asc)     ((Asc)-0x30)
#define util_Hex2Ascii(Hex)           (((Hex)>0x09) ? ((Hex) + 0x37): ((Hex) + 0x30))
#define util_Ascii2Hex(Asc)           (((Asc)>0x39) ? ((Asc) - 0x37): ((Asc) - 0x30))
#define util_GetBitStatus(x,bit)      (((x)&(util_GetBitMask(bit)))!=0u)
#define util_GetBitMask(bit)          (1<<(bit))


#define C_BINARY_U8           2u
#define C_DECIMAL_U8         10u
#define C_HEX_U8             16u

#define C_SINT8_MAX   0x7F
#define C_SINT8_MIN  -128

#define C_UINT8_MAX   0xFFu
#define C_UINT8_MIN   0x00u

#define C_SINT16_MAX  32767
#define C_SINT16_MIN -32768

#define C_UINT16_MAX  0xFFFFu
#define C_UINT16_MIN  0x00u

#define C_SINT32_MAX  2147483647
#define C_SINT32_MIN -2147483648

#define C_UINT32_MAX  0xFFFFFFFFu
#define C_UINT32_MIN  0x00u


#define C_DefaultDigits     10

#define C_OledFirstLine_U8 0x00u
#define C_OledLastLine_U8  0x07u

#define C_FirstLineAddress_U8 0xB8
#define C_LastLineAddress_U8  0xBF

#define C_DisplayDefaultDigits_U8            0xffu // Will display the exact digits in the number
#define C_MaxDigitsToDisplay_U8              10u   // Max decimal/hexadecimal digits to be displayed
#define C_NumOfBinDigitsToDisplay_U8         16u   // Max bits of a binary number to be displayed
#define C_MaxDigitsToDisplayUsingPrintf_U8   C_DisplayDefaultDigits_U8 /* Max dec/hexadecimal digits to be displayed using printf */

#define C_MaxBarGraphs_U8     5

/* macros I2C (slave address - control byte) */
#define SSD1306_ADDRESS		0x3C
#define CONTROL_BYTE_COMMAND 0x00
#define CONTROL_BYTE_DATA		0xC0
#define CONTROL_BYTE_DATA_CONTINUE 0x40



void OLED_Init(void);
void OLED_Clear(void);
void OLED_SendCMD(uint8 cmd);
void OLED_PrintChar(uint8 data);
void OLED_PrintString(uint8 *ptr);
void OLED_PrintBitMap(uint8 *ptr);
void OLED_PrintNumber(uint8 v_numericSystem, uint16 v_number_u32, uint8 v_numOfDigitsToDisplay_u8);
void OLED_PrintFloatNumber(double v_floatNum_f32);
void OLED_GoToLine(uint8 );
void OLED_GoToNextLine(void);
void OLED_SetCursor(uint8 lineNumber,uint8 CursorPosition);




#endif /* OLED_H_ */
