/*
 * File:   TIMER2_PRG.c
 * Author: Yousef Ahed 
 *
 * Created on February 29, 2020
 */
 
 
 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
 #include "TIMER2_INT.h"
 #include "TIMER2_REG.h"
 #include "GPIO.h"
 
 
 void Timer2_vidInit(void)
 {
	/*Select prescaler*/
	#if Prescaler == PreS_1
		CLR_BIT(T2CON_Register,0);
		CLR_BIT(T2CON_Register,1);
	
	#elif Prescaler == PreS_2
		SET_BIT(T2CON_Register,0);
		CLR_BIT(T2CON_Register,1);
	
	#elif Prescaler == PreS_16
		SET_BIT(T2CON_Register,0);
		SET_BIT(T2CON_Register,1);
	#endif
	
	/*Select Postscaler */
/*	#if Postscaler == PostS_1
		CLR_BIT(T2CON_Register,6);
		CLR_BIT(T2CON_Register,5);
		CLR_BIT(T2CON_Register,4);
		CLR_BIT(T2CON_Register,3);
	#elif Postscaler == PostS_2
		CLR_BIT(T2CON_Register,6);
		CLR_BIT(T2CON_Register,5);
		CLR_BIT(T2CON_Register,4);
		SET_BIT(T2CON_Register,3);
	#elif Postscaler == PostS_3
		CLR_BIT(T2CON_Register,6);
		CLR_BIT(T2CON_Register,5);
		SET_BIT(T2CON_Register,4);
		CLR_BIT(T2CON_Register,3);
	#elif Postscaler == PostS_16
		SET_BIT(T2CON_Register,6);
		SET_BIT(T2CON_Register,5);
		SET_BIT(T2CON_Register,4);
		SET_BIT(T2CON_Register,3);
	#endif
*/	

	/*Timer2 On*/
	SET_BIT(T2CON_Register,2);
 }
 
