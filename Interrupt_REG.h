/*
 * File:   Interrupt_REG.h
 * Author: Yousef Ahed 
 *
 * Created on March 4, 2020
 */
 
 
 
 #ifndef _INTERRUPT_REG_H
 #define _INTERRUPT_REG_H
 
 
 #define INTCON_Register *((volatile u8*) 0x0B)
 #define PIE1_Register   *((volatile u8*) 0x8C)
 #define PIR1_Register   *((volatile u8*) 0x0C)
 #define PIE2_Register   *((volatile u8*) 0x8D)
 #define PIR2_Register   *((volatile u8*) 0x0D)

 
 
 
 #endif