/*
 * File:   PWM_PRG.c
 * Author: Yousef Ahed 
 *
 * Created on February 29, 2020
 */
 
 #include "STD_TYPES.h"
 #include "PWM_INT.h"
 #include "PWM_CFG.h"
 #include "PWM_REG.h"
 #include "TIMER2_REG.h"
 #include "TIMER2_INT.h"
 #include "GPIO.h"
 
 
 void PWM1_vidInit(void)
 {

    u8 u8temp = 0;
	u16 u16DC_set;
	
	/*Enable PWM mode*/
	CCP1CON_Register |= 0x0C;
	
	/*Set RC2 as output*/
	GPIO_vidSetPinDirection(GPIO_PortC, PIN2, GPIO_Output);
	
	PR2_Register = PR2_Value;
	
	u16DC_set = DC_value;
	
	u8temp = u16DC_set & 0x01; 
	
	u8temp = u8temp << 4;
	
	CCP1CON_Register |= u8temp;
    
    u8temp = u16DC_set & 0x02; 
	
	u8temp = u8temp << 4;
	
	CCP1CON_Register |= u8temp;
	
	CCPR1L_Register = u16DC_set >> 2;

	
	//Turn Timer 2 ON
	Timer2_vidInit();
	

 }
 void PWM2_vidInit(void)
 {
     u8 u8temp = 0;
	u16 u16DC_set;
	
	/*Enable PWM mode*/
	CCP2CON_Register |= 0x0C;
	
	/*Set RC2 as output*/
	GPIO_vidSetPinDirection(GPIO_PortC, PIN1, GPIO_Output);
	
	PR2_Register = PR2_Value;
	
	u16DC_set = DC_value;
	
	u8temp = u16DC_set & 0x01; 
	
	u8temp = u8temp << 4;
	
	CCP2CON_Register |= u8temp;
    
    u8temp = u16DC_set & 0x02; 
	
	u8temp = u8temp << 4;
	
	CCP2CON_Register |= u8temp;
	
	CCPR2L_Register = u16DC_set >> 2;
 }
 
 