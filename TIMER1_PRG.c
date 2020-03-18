/*
 * File:   TIMER1_PRG.c
 * Author: Yousef Ahed 
 *
 * Created on March 4, 2020
 */
 
 
#include "STD_TYPES.h" 
#include "BIT_MATH.h"
#include "TIMER1_REG.h"
#include "TIMER1_CFG.h"
#include "TIMER1_INT.h"


void Timer1_vidInit(void)
{
	/*Clear timer register*/
	TMR1L_Register = 0;
	TMR1H_Register = 0;
	
	/*Select internal clock source*/
	CLR_BIT(T1CON_Register,1);
	
    #if Timer1_Prescaler == PS_1
        CLR_BIT(T1CON_Register,5);
        CLR_BIT(T1CON_Register,4);
	#elif Timer1_Prescaler == PS_2
		CLR_BIT(T1CON_Register,5);
		SET_BIT(T1CON_Register,4);
	#elif Timer1_Prescaler == PS_4
		SET_BIT(T1CON_Register,5);
		CLR_BIT(T1CON_Register,4);
	#elif Timer1_Prescaler == PS_8
		SET_BIT(T1CON_Register,5);
		SET_BIT(T1CON_Register,4);
	#endif
	
	/*
	
		Event 1
	
	
	*/
	
	/*Timer1 module ON*/
	SET_BIT(T1CON_Register,0);
	
}