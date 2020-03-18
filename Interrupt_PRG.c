/*
 * File:   Interrupt_PRG.h
 * Author: Yousef Ahed 
 *
 * Created on March 4, 2020
 */
 
 
 #include "STD_TYPES.h"
 #include "Interrupt_REG.h"
 #include "Interrupt_INT.h"
 #include "Interrupt_CFG.h"
 #include "BIT_MATH.h"
 
 
 void Interrupt_vidInit(void)
 {
     INTCON_Register=0;
	/*Enable global interrupt*/
	SET_BIT(INTCON_Register, 7);
	
	/*Enable peripheral interrupt*/
	SET_BIT(INTCON_Register, 6);
	
    // RB0_Int ==  ENA
	SET_BIT(INTCON_Register,4);

	
    // TMR1_Int == ENA
	SET_BIT(PIE1_Register,0);
//	#endif
 }
 
 void Interrupt_vidTMR1ClearFlag(void)
 {
	CLR_BIT(PIR1_Register, 0);
 }