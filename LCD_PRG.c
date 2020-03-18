/*
 *	LCD_PRG_PIC.c
 *
 *  Created on: Feb 22, 2020
 *      Author: Yousef Ahed
 */
#include <xc.h>
#include "STD_TYPES.h" 
#include "BIT_MATH.h"
#include "GPIO.h"
#include "LCD_INT.h"
#include "LCD_CFG.h"
#define  _XTAL_FREQ 8000000



// RS pin selects register --> IR:0, DR:1   
// R/W pin --> Write:0, Read:1 
// E pin --> Starts data read/write 
 


void LCD_vidInit(void)
{
    GPIO_vidPortEMode(PortE_Digital);

    /*Setting data port direction*/
	GPIO_vidSetPortDirection(Data_Port, GPIO_Output_Port);

    /*Setting Control pins direction*/
    GPIO_vidSetPortDirection(E_Port, GPIO_Output);
    
    /*Pulling down enable pin*/
	GPIO_vidSetPinValue(E_Port, E_Pin, GPIO_Low);
	
	/*Setting RS pin to 0 to select IR*/
	GPIO_vidSetPinValue(RS_Port, RS_Pin, GPIO_Low);	

    __delay_ms(20);
    
	/*Pulling up enable button*/
	GPIO_vidSetPinValue(E_Port, E_Pin, GPIO_HIGH);
	
	/*Starting initialization sequence per data sheet*/
	
	/*Starting transmission*/
//	GPIO_vidSetPinValue(E_Port, E_Pin, GPIO_Low);
	
	LCD_vidSendCommand(LCD_Init);
	
	__delay_ms(50);
	
	LCD_vidSendCommand(LCD_Init);
	
	__delay_ms(1);
	
	LCD_vidSendCommand(LCD_Init);
	
	LCD_vidSendCommand(Display_Off);
	
	LCD_vidSendCommand(Clear_display);
	
	LCD_vidSendCommand(Display_2_lines);
	
	LCD_vidSendCommand(Go_to_line_1);
    
	/*End of initialization sequence*/
}

void LCD_vidSetAddressCounter(u8 u8Address)
{
	LCD_vidSendCommand(u8Address);
}

void LCD_vidSendCommand(u8 u8Command)
{
    /*Setting enable pin to start writing*/
	GPIO_vidSetPinValue(E_Port, E_Pin, GPIO_HIGH);
    
    /*Writing the command to data port*/
	GPIO_vidSetPortValue(Data_Port, u8Command);
    
    /*Selecting IR register*/
	GPIO_vidSetPinValue(RS_Port, RS_Pin, GPIO_Low);
    
     __delay_ms(3);
    
    GPIO_vidSetPinValue(E_Port, E_Pin, GPIO_Low);
    
    __delay_ms(3);
	
    /*Setting enable pin to start writing*/
	GPIO_vidSetPinValue(E_Port, E_Pin, GPIO_HIGH);
	
	
	

	
}

void LCD_vidSendData(u8 u8Data)
{
    /*Setting enable pin to start writing*/
	GPIO_vidSetPinValue(E_Port, E_Pin, GPIO_HIGH);
    
    /*Writing the command to data port*/
	GPIO_vidSetPortValue(Data_Port, u8Data);
    
    /*Selecting IR register*/
	GPIO_vidSetPinValue(RS_Port, RS_Pin, GPIO_HIGH);
    
     __delay_ms(3);
    
    GPIO_vidSetPinValue(E_Port, E_Pin, GPIO_Low);
    
    __delay_ms(3);
	
    /*Setting enable pin to start writing*/
	GPIO_vidSetPinValue(E_Port, E_Pin, GPIO_HIGH);
}

u8 LCD_u8SendString(u8* u8String)
{
	u8 i = 0;

	while(u8String[i] != 0)
	{
		LCD_vidSendData(u8String[i]);
		i++;
	}
	return i;
	
}
void LCD_vidPrintNumber(u16 number)
{
	u8 digit;

	if(number >= 1000)
	{
		digit = number / 1000;

		LCD_vidSendData(digit + 48);

		number = number - digit * 1000;

		digit = number / 100;

		LCD_vidSendData(digit + 48);

		number = number - digit * 100;

		digit = number / 10;

		number = number - digit * 10;

		LCD_vidSendData(digit + 48);

		LCD_vidSendData(number + 48);

	}
	else if(number >= 100)
	{
		digit = number / 100;

		LCD_vidSendData(digit + 48);

		number = number - digit * 100;

		digit = number / 10;

		number = number - digit * 10;

		LCD_vidSendData(digit + 48);

		LCD_vidSendData(number + 48);
	}
	else if(number >= 10)
	{
		digit = number / 10;

		number = number - digit * 10;

		LCD_vidSendData(digit + 48);

		LCD_vidSendData(number + 48);
	}
	else if(number >= 0)
	{
        LCD_vidSendData('0');
		LCD_vidSendData(number + 48);
	}
}
