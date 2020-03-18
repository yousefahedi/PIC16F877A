/*
 * File:   PWM_REG.h
 * Author: Yousef Ahed 
 *
 * Created on February 29, 2020
 */

#ifndef _PWM_REG_H
#define _PWM_REG_H



/*Compare/Capture/PWM Modules Control Registers*/

#define CCP1CON_Register *((volatile u8*) 0x17)
#define CCPR1L_Register  *((volatile u8*) 0x15)
#define CCPR1H_Register  *((volatile u8*) 0x16)
#define CCP2CON_Register *((volatile u8*) 0x1D)
#define CCPR2L_Register  *((volatile u8*) 0x1B)
#define CCPR2H_Register  *((volatile u8*) 0x1C)













#endif
