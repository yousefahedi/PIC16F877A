/*
 * File:   GPIO_REG.h
 * Author: Yousef Ahed 
 *
 * Created on February 18, 2020, 6:44 PM
 */



#ifndef _GPIO_REG_H
#define _GPIO_REG_H


/*PortA Registers*/
#define GPIO_PortA_Register  *((volatile u8*)0x05)    //Read or write port value form this register PortX 
#define GPIO_TRISA_Register  *((volatile u8*)0x85)    //Sets port or pin Direction from this register TRISX
#define GPIO_ADCON1_Register *((volatile u8*)0x9F)

/*PortB Registers*/
#define GPIO_PortB_Register  *((volatile u8*)0x06)
#define GPIO_TRISB_Register  *((volatile u8*)0x86)
#define GPIO_OPTION_Register *((volatile u8*)0x81)


/*PortC Registers*/
#define GPIO_PortC_Register *((volatile u8*)0x07)
#define GPIO_TRISC_Register *((volatile u8*)0x87)

/*PortD Registers*/
#define GPIO_PortD_Register *((volatile u8*)0x08)
#define GPIO_TRISD_Register *((volatile u8*)0x88)

/*PortE Registers*/
#define GPIO_PortE_Register *((volatile u8*)0x09)
#define GPIO_TRISE_Register *((volatile u8*)0x89)


#endif