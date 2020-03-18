/*
 *	LCD_INT_PIC.h
 *
 *  Created on: Feb 22, 2020
 *      Author: Yousef Ahed
 */
 
#ifndef LCD_INT_H_
#define LCD_INT_H_

/*LCD functions Prototypes*/

void LCD_vidInit(void);

void LCD_vidSetAddressCounter(u8 u8Address);

void LCD_vidSendCommand(u8 u8Command);

void LCD_vidSendData(u8 u8Data);

u8 LCD_u8SendString(u8* u8String);

void LCD_vidPrintNumber(u16 number);



/*LCD Instructions*/

#define Clear_display		0x01
#define Return_home	   	    0x02
#define Entry_mode_set_Inc  0x07
#define Entry_mode_set_Dec  0x05
#define Display_Off			0x08
#define Display_On			0x0F
#define Cursor_move_right	0x14	
#define Cursor_move_left	0x10
#define Display_shift_right	0x1C
#define Display_shift_left	0x18
#define Display_2_lines		0x38
#define Display_1_line		0x30
#define Go_to_line_1		0x80
#define Go_to_line_2		0xC0
#define LCD_Init			0x19

/**********************************************/






/**********************************************/
#endif