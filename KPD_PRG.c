/*
 *	KPD_PRG.c
 *
 *  Created on: Feb 22, 2020
 *      Author: Yousef Ahed
 */

#include <xc.h>
#include "STD_TYPES.h"
#include "GPIO.h"
#include "KPD_CFG.h"
#include "KPD_INT.h"
#define  _XTAL_FREQ 8000000



u8 KPD_u8GetPressedButton(void)
{
	u8 u8columns, u8rows, u8return_value = 0;

	u8 keypad_map[4][3] =
		{
			{'-','0','+'},
			{'7','8','9'},
			{'4', '5','6'},
			{'1', '2' ,'3'}
		};


	GPIO_vidSetPortValue(KPD_Output_Port, GPIO_PORT_HIGH);

    for(u8rows = row_start; u8rows < row_end; u8rows++)
	{
		GPIO_vidSetPinValue(KPD_Output_Port, u8rows, GPIO_Low);

		for(u8columns = col_start; u8columns < col_end; u8columns++)
		{
			if(GPIO_u8GetPinValue(KPD_Input_Port, u8columns) == GPIO_Low)
			{
				u8return_value = keypad_map[u8rows][u8columns];

				while(GPIO_u8GetPinValue(KPD_Input_Port, u8rows) == GPIO_Low);
                
                __delay_ms(50);
			}
		}
		GPIO_vidSetPinValue(KPD_Output_Port, u8rows, GPIO_HIGH);
	}

	return u8return_value;
}

void KPD_vidInit(void)
{
    /*Set Input Pins*/
    GPIO_vidSetPinDirection(GPIO_PortD, PIN0, GPIO_Output);
    
    GPIO_vidSetPinDirection(GPIO_PortD, PIN1, GPIO_Output);
    
    GPIO_vidSetPinDirection(GPIO_PortD, PIN2, GPIO_Output);
   
    GPIO_vidSetPinDirection(GPIO_PortD, PIN3, GPIO_Output);
    
    GPIO_vidSetPinDirection(GPIO_PortB, PIN0, GPIO_Input);

    GPIO_vidSetPinDirection(GPIO_PortB, PIN1, GPIO_Input);

    GPIO_vidSetPinDirection(GPIO_PortB, PIN2, GPIO_Input);
    
    GPIO_vidPullUp();

    
}