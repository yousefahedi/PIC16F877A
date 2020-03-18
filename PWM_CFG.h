/*
 * File:   PWM_CFG.h
 * Author: Yousef Ahed 
 *
 * Created on February 29, 2020
 */

#ifndef _PWM_CFG_H
#define _PWM_CFG_H



/*
 * PWM Freq = 5000Hz
 * PWM Period = 1/PWM_Freq
 * F_osc = 8000000
 * T_osc = 1/F_osc
 * Timer2_PS 4
 * Duty_Cycle 0.5
 * To calculate PR2 value use the following Equation
 * PWM_period={(PR2)+1}*4*T_osc*Timer2 PreScaler value
 * 
 * To calculate Duty cycle value
 * PWM_duty.cycle=(CCPR1L:CCPR1L<5:4>)*T_osc_*Timer2 Prescaler
 */
#define PR2_Value 99
#define DC_value  200












#endif
