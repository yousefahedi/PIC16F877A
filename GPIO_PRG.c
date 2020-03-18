/*
 * File:   GPIO_PRG.c
 * Author: Yousef Ahed 
 *
 * Created on February 18, 2020, 7:58 PM
 */
#include <pic16f877a.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO.h"
#include "GPIO_REG.h"

/*********************************Functions on Pin Level****************************/ 
void GPIO_vidSetPinDirection(u8 u8PortNo, u8 u8PinNo, u8 u8Direction)
{
	if ( u8Direction == GPIO_Input )
	{
		/* Check on the Required PORT Number */
		switch (u8PortNo)
		{
			case GPIO_PortA: SET_BIT(GPIO_TRISA_Register, u8PinNo); break;
			case GPIO_PortB: SET_BIT(GPIO_TRISB_Register, u8PinNo); break;
			case GPIO_PortC: SET_BIT(GPIO_TRISC_Register, u8PinNo); break;
			case GPIO_PortD: SET_BIT(GPIO_TRISD_Register, u8PinNo); break;
			case GPIO_PortE: SET_BIT(GPIO_TRISE_Register, u8PinNo); break;
			
		}
	}
	else if ( u8Direction == GPIO_Output )
	{
		/* Check on the Required PORT Number */
		switch (u8PortNo)
		{
			case GPIO_PortA: CLR_BIT(GPIO_TRISA_Register, u8PinNo); break;
			case GPIO_PortB: CLR_BIT(GPIO_TRISB_Register, u8PinNo); break;
			case GPIO_PortC: CLR_BIT(GPIO_TRISC_Register, u8PinNo); break;
			case GPIO_PortD: CLR_BIT(GPIO_TRISD_Register, u8PinNo); break;
			case GPIO_PortE: CLR_BIT(GPIO_TRISE_Register, u8PinNo); break;		
		}
	}
	else
	{
		/* Do nothing, Wrong Direction Required */
	}

}
void GPIO_vidSetPinValue(u8 u8PortNo, u8 u8PinNo, u8 u8PinVal)
{
	if (u8PinVal == GPIO_Low)
	{
		/* Check on the Required PORT Number */
		switch (u8PortNo)
		{
			case GPIO_PortA: CLR_BIT(GPIO_PortA_Register,u8PinNo); break;
			case GPIO_PortB: CLR_BIT(GPIO_PortB_Register,u8PinNo); break;
			case GPIO_PortC: CLR_BIT(GPIO_PortC_Register,u8PinNo); break;
			case GPIO_PortD: CLR_BIT(GPIO_PortD_Register,u8PinNo); break;
			case GPIO_PortE: CLR_BIT(GPIO_PortE_Register,u8PinNo); break;
		}
	}
	else if (u8PinVal == GPIO_HIGH)
	{
		/* Check on the Required PORT Number */
		switch (u8PortNo)
		{
			case GPIO_PortA: SET_BIT(GPIO_PortA_Register,u8PinNo); break;
			case GPIO_PortB: SET_BIT(GPIO_PortB_Register,u8PinNo); break;
			case GPIO_PortC: SET_BIT(GPIO_PortC_Register,u8PinNo); break;
			case GPIO_PortD: SET_BIT(GPIO_PortD_Register,u8PinNo); break;
			case GPIO_PortE: SET_BIT(GPIO_PortE_Register,u8PinNo); break;
		}
	}
	else
	{
		/* Do nothing, Wrong value to set */
	}
}
u8 GPIO_u8GetPinValue(u8 u8PortNo, u8 u8PinNo)
{
	u8 u8PinValReturn;
	
	switch(u8PortNo)
	{
		case GPIO_PortA: u8PinValReturn = GET_BIT(GPIO_PortA_Register, u8PinNo); break;
		case GPIO_PortB: u8PinValReturn = GET_BIT(GPIO_PortB_Register, u8PinNo); break;
		case GPIO_PortC: u8PinValReturn = GET_BIT(GPIO_PortC_Register, u8PinNo); break;
		case GPIO_PortD: u8PinValReturn = GET_BIT(GPIO_PortD_Register, u8PinNo); break;
		case GPIO_PortE: u8PinValReturn = GET_BIT(GPIO_PortE_Register, u8PinNo); break;
		
	}
	
	return u8PinValReturn;
}
void GPIO_vidPullUp(void)
{ /*Activates internal pull up on port B*/
//    CLR_BIT(GPIO_OPTION_Register, PULL_UP_BIT);
    OPTION_REG=0;
}
void GPIO_vidPortAMode(u8 u8Mode)
{
    switch(u8Mode)
    {
        case PortA_Digital:  GPIO_ADCON1_Register = 0x0F; break;
        case PortA_Analog :  GPIO_ADCON1_Register = 0x00; break;
    }
}

void GPIO_vidPortEMode(u8 u8Mode)
{
    switch(u8Mode)
    {
        case PortE_Digital:  GPIO_ADCON1_Register = 0x0F; break;
        case PortE_Analog :  GPIO_ADCON1_Register = 0x00; break;
    }
}

/****************************************************************************************************/

/*******************************************Functions on Port Level**********************************/
void GPIO_vidSetPortDirection(u8 u8PortNo, u8 u8PortDirection)
{
	/*Check for required port direction*/
	if(u8PortDirection == GPIO_Input)
	{	/*check for required port*/
		switch(u8PortNo)
		{
			case GPIO_PortA: GPIO_TRISA_Register = GPIO_Input_Port; break;
			case GPIO_PortB: GPIO_TRISB_Register = GPIO_Input_Port; break;
			case GPIO_PortC: GPIO_TRISC_Register = GPIO_Input_Port; break;
			case GPIO_PortD: GPIO_TRISD_Register = GPIO_Input_Port; break;
			case GPIO_PortE: GPIO_TRISE_Register = GPIO_Input_Port; break;
		}
	}	
	else if(u8PortDirection == GPIO_Output)
	{
		switch(u8PortNo)
		{
			case GPIO_PortA: GPIO_TRISA_Register = GPIO_Output_Port; break;
			case GPIO_PortB: GPIO_TRISB_Register = GPIO_Output_Port; break;
			case GPIO_PortC: GPIO_TRISC_Register = GPIO_Output_Port; break;
			case GPIO_PortD: GPIO_TRISD_Register = GPIO_Output_Port; break;
			case GPIO_PortE: GPIO_TRISE_Register = GPIO_Output_Port;break;
		}
	}
	else
	{
		switch(u8PortNo)
		{
			case GPIO_PortA: GPIO_TRISA_Register &= u8PortDirection; break;
			case GPIO_PortB: GPIO_TRISB_Register &= u8PortDirection; break;
			case GPIO_PortC: GPIO_TRISC_Register &= u8PortDirection; break;
			case GPIO_PortD: GPIO_TRISD_Register &= u8PortDirection; break;
			case GPIO_PortE: GPIO_TRISE_Register &= u8PortDirection;break;
		}
	}
}
void GPIO_vidSetPortValue(u8 u8PortNo, u8 u8PortVal)
{
	/*Check for required port value*/
	if(u8PortVal == GPIO_PORT_HIGH)
	{	/*Check for required port*/
		switch(u8PortNo)
		{
			case GPIO_PortA: GPIO_PortA_Register = GPIO_PORT_HIGH; break;
			case GPIO_PortB: GPIO_PortB_Register = GPIO_PORT_HIGH; break;
			case GPIO_PortC: GPIO_PortC_Register = GPIO_PORT_HIGH; break;
			case GPIO_PortD: GPIO_PortD_Register = GPIO_PORT_HIGH; break; 
			case GPIO_PortE: GPIO_PortE_Register = GPIO_PORT_HIGH; break;
		}
	}	
	else if(u8PortVal == GPIO_PORT_LOW)
	{
		switch(u8PortNo)
		{
			case GPIO_PortA: GPIO_PortA_Register = GPIO_PORT_LOW; break; 
			case GPIO_PortB: GPIO_PortB_Register = GPIO_PORT_LOW; break;
			case GPIO_PortC: GPIO_PortC_Register = GPIO_PORT_LOW; break;
			case GPIO_PortD: GPIO_PortD_Register = GPIO_PORT_LOW; break;
			case GPIO_PortE: GPIO_PortE_Register = GPIO_PORT_LOW; break;
		}
	}
	else
	{
		switch(u8PortNo)
		{
			case GPIO_PortA: GPIO_PortA_Register = u8PortVal; break;	 
			case GPIO_PortB: GPIO_PortB_Register = u8PortVal; break;
			case GPIO_PortC: GPIO_PortC_Register = u8PortVal; break;
			case GPIO_PortD: GPIO_PortD_Register = u8PortVal; break;
			case GPIO_PortE: GPIO_PortE_Register = u8PortVal; break; 
		}
	}
}
