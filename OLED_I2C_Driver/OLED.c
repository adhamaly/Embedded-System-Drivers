/*
 * OLED.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */

#include "STD.h"
#include "DIO.h"
#include "I2C.h"
#include "Master.h"
#include "OLED.h"


uint8 OledLineNum, OledCursorPos;
void OLED_Init(void){
	Master_Init(10);

	OLED_SendCMD(SSD1306_DISPLAYOFF);
	OLED_SendCMD(SSD1306_SETDISPLAYCLOCKDIV);
	OLED_SendCMD(0x80);
	OLED_SendCMD(SSD1306_SETMULTIPLEX);                  // 0xA8
	OLED_SendCMD(0x3F);
	OLED_SendCMD(SSD1306_SETDISPLAYOFFSET);              // 0xD3
	OLED_SendCMD(0x0);                                   // no offset
	OLED_SendCMD(SSD1306_SETSTARTLINE | 0x0);        // line #0
	OLED_SendCMD(SSD1306_CHARGEPUMP);                    // 0x8D
	OLED_SendCMD(0x14);  // using internal VCC
	OLED_SendCMD(SSD1306_MEMORYMODE);                    // 0x20
	OLED_SendCMD(0x00);          // 0x00 horizontal addressing
	OLED_SendCMD(SSD1306_SEGREMAP | 0x1); // rotate screen 180
	OLED_SendCMD(SSD1306_COMSCANDEC); // rotate screen 180
	OLED_SendCMD(SSD1306_SETCOMPINS);                    // 0xDA
	OLED_SendCMD(0x12);
	OLED_SendCMD(SSD1306_SETCONTRAST);                   // 0x81
	OLED_SendCMD(0xCF);
	OLED_SendCMD(SSD1306_SETPRECHARGE);                  // 0xd9
	OLED_SendCMD(0xF1);
	OLED_SendCMD(SSD1306_SETVCOMDETECT);                 // 0xDB
	OLED_SendCMD(0x40);
	OLED_SendCMD(SSD1306_DISPLAYALLON_RESUME);           // 0xA4
	OLED_SendCMD(SSD1306_NORMALDISPLAY);                 // 0xA6
	OLED_SendCMD(SSD1306_DISPLAYON);

	OLED_Clear();  /* Clear the complete LCD during init */

}
void OLED_Clear()
{
	 uint8 i;
	 OLED_SendCMD(SSD1306_SET_COLUMN_ADDR);
	 OLED_SendCMD(0);
	 OLED_SendCMD(127);

	 OLED_SendCMD(SSD1306_SET_PAGE_ADDR);
	 OLED_SendCMD(0);
	 OLED_SendCMD(7);


	 Master_Start(SSD1306_ADDRESS);
     Master_WriteDataPacket(CONTROL_BYTE_DATA_CONTINUE);
	 for (i=0; i<1024; i++)      // Write Zeros to clear the display
	 {
		 Master_WriteDataPacket(0);
	 }

	 OLED_SendCMD(SSD1306_SET_COLUMN_ADDR);
	 OLED_SendCMD(0);
	 OLED_SendCMD(127);

	 OLED_SendCMD(SSD1306_SET_PAGE_ADDR);
	 OLED_SendCMD(0);
	 OLED_SendCMD(7);

	 Master_Start(SSD1306_ADDRESS);
	 Master_WriteDataPacket(CONTROL_BYTE_DATA_CONTINUE);
}
void OLED_SendCMD(uint8 cmd){
	uint8 status;
	status  = Master_Start(SSD1306_ADDRESS);
    if(status == ACK_REC ){
    	status = Master_WriteDataPacket(CONTROL_BYTE_COMMAND);
    	if(status == ACK_REC){
    			    Master_WriteDataPacket(cmd);
    				Master_Stop();


    		}
    	}
}
void OLED_PrintChar(uint8 data){
	uint8 status;
		status  = Master_Start(SSD1306_ADDRESS);
	    if(status == ACK_REC ){
	    	status = Master_WriteDataPacket(CONTROL_BYTE_DATA);
	    	if(status == ACK_REC){
	    			status = Master_WriteDataPacket(data);
	    				Master_Stop();


	    		}
	    	}
}
void OLED_PrintString(uint8 *ptr){
	while(*ptr){
		OLED_PrintChar(*ptr++);
	}
}
void OLED_PrintBitMap(uint8 *ptr){

	uint8 status,i;
	status = Master_Start(SSD1306_ADDRESS);
	if(status == ACK_REC){
		status = Master_WriteDataPacket(CONTROL_BYTE_DATA_CONTINUE);
		if(status == ACK_REC){
		for(i = 0;i<1024;i++){
			Master_WriteDataPacket(ptr[i]);
		}

	}
}

}
void OLED_GoToLine(uint8 lineNumber)
{
    if(lineNumber<8)
    {   /* If the line number is within range
         then move it to specified line and keep track*/
        OledLineNum = lineNumber;
        OLED_SetCursor(OledLineNum,0);
    }
}







 /* description  :This function moves the Cursor to beginning of the next line.
 If the cursor is on last line and NextLine command is issued then
 it will move the cursor to first line.
 */
void  OLED_GoToNextLine()
{
    /*Increment the current line number.
     In case it exceeds the limit, rool it back to first line */
    OledLineNum++;
    OledLineNum = OledLineNum&0x07;
    OLED_SetCursor(OledLineNum,0); /* Finally move it to next line */
}







/***************************************************************************************************
 void OLED_SetCursor(char v_lineNumber_u8,char v_charNumber_u8)
 ****************************************************************************************************
 * I/P Arguments: char row,char col
 row -> line number(line1=1, line2=2),
 For 2line LCD the I/P argument should be either 1 or 2.
 col -> char number.
 For 16-char LCD the I/P argument should be between 0-15.
 * Return value    : none
 * description  :This function moves the Cursor to specified position
 Note:If the Input(Line/Char number) are out of range
 then no action will be taken
 ****************************************************************************************************/
void OLED_SetCursor(uint8 lineNumber,uint8 cursorPosition)
{
    /* Move the Cursor to specified position only if it is in range */
    if((lineNumber <= 0) && (cursorPosition <= 127))
    {
        OledLineNum=lineNumber;   /* Save the specified line number */
        OledCursorPos=cursorPosition; /* Save the specified cursor position */

        OLED_SendCMD(SSD1306_SET_COLUMN_ADDR);
        OLED_SendCMD(cursorPosition);
        OLED_SendCMD(127);

        OLED_SendCMD(SSD1306_SET_PAGE_ADDR);
        OLED_SendCMD(lineNumber);
        OLED_SendCMD(7);

        Master_Start(SSD1306_ADDRESS);
        Master_WriteDataPacket(CONTROL_BYTE_DATA_CONTINUE);
    }
}

void OLED_PrintNumber(uint8 v_numericSystem, uint16 v_number_u32, uint8 v_numOfDigitsToDisplay){

    uint8 i=0,a[10];

    if( C_BINARY_U8 == v_numericSystem)
    {
        while(v_numOfDigitsToDisplay!=0)
        {
            /* Start Extracting the bits from the specified bit positions.
             Get the Acsii values of the bits and display */
            i = util_GetBitStatus(v_number_u32,(v_numOfDigitsToDisplay-1));
            OLED_PrintChar(util_Dec2Ascii(i));
            v_numOfDigitsToDisplay--;
        }
    }
    else if(v_number_u32==0)
    {
        /* If the number is zero then update the array with the same for displaying */
        for(i=0;((i < v_numOfDigitsToDisplay) && (i<C_MaxDigitsToDisplay_U8));i++)
        	OLED_PrintChar('0');
    }
    else
    {
        for(i=0;i<v_numOfDigitsToDisplay;i++)
        {
            /* Continue extracting the digits from right side
             till the Specified v_numOfDigitsToDisplay_u8 */
            if(v_number_u32!=0)
            {
                /* Extract the digits from the number till it becomes zero.
                 First get the remainder and divide the number by TypeOfNum(10-Dec, 16-Hex) each time.
                 example for Decimal number:
                 If v_number_u32 = 123 then extracted remainder will be 3 and number will be 12.
                 The process continues till it becomes zero or max digits reached*/
                a[i]=util_GetMod32(v_number_u32,v_numericSystem);
                v_number_u32=v_number_u32/v_numericSystem;
            }
            else if( (v_numOfDigitsToDisplay == C_DisplayDefaultDigits_U8) ||
                    (v_numOfDigitsToDisplay > C_MaxDigitsToDisplay_U8))
            {
                /* Stop the iteration if the Max number of digits are reached or
                 the user expects exact(Default) digits in the number to be displayed */
                break;
            }
            else
            {
                /* In case user expects more digits to be displayed than the actual digits in number,
                 then update the remaining digits with zero.
                 Ex: v_num_u32 is 123 and user wants five digits then 00123 has to be displayed */
                a[i]=0;
            }
        }

        while(i!=0)
        {
            /* Finally get the ascii values of the digits and display*/
        	OLED_PrintChar(util_Hex2Ascii(a[i-1]));
            i--;
        }
    }
}















