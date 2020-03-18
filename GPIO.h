/*
 * File:   GPIO.h
 * Author: Yousef Ahed 
 *
 * Created on February 18, 2020, 6:57 PM
 */


#ifndef _GPIO_H
#define _GPIO_H 
/*Port Direction*/
#define GPIO_Input  	 1
#define GPIO_Output 	 0
#define GPIO_Input_Port  0xFF
#define GPIO_Output_Port 0x00

/*GPIO Values*/
#define GPIO_HIGH      1
#define GPIO_Low       0
#define GPIO_PORT_HIGH 0xFF
#define GPIO_PORT_LOW  0x00

 
/*GPIO Ports*/
#define GPIO_PortA 0
#define GPIO_PortB 1
#define GPIO_PortC 2
#define GPIO_PortD 3
#define GPIO_PortE 4

/*Port A A/D Pins*/
#define PortA_Digital 0
#define PortA_Analog  1

/*Port E A/D Pins*/
#define PortE_Digital 0
#define PortE_Analog  1



/*******GPIO PINS******/
#define PIN0 0 
#define PIN1 1  
#define PIN2 2  
#define PIN3 3  
#define PIN4 4  
#define PIN5 5
#define PIN6 6
#define PIN7 7

/***********/

#define PULL_UP_BIT 7

/***********/

/******************************************GPIO Functions********************************/

/*Functions ON Pin Level*/
void GPIO_vidSetPinDirection(u8 u8PortNo, u8 u8PinNo, u8 u8Direction);
void GPIO_vidSetPinValue(u8 u8PortNo, u8 u8PinNo, u8 u8PinVal);
u8 GPIO_u8GetPinValue(u8 u8PortNo, u8 u8PinNo);
void GPIO_vidPullUp(void);
void GPIO_vidPortAMode(u8 u8Mode);
void GPIO_vidPortEMode(u8 u8Mode);
/*Functions on Port Level*/
void GPIO_vidSetPortDirection(u8 u8PortNo, u8 u8PortDirection);
void GPIO_vidSetPortValue(u8 u8PortNo, u8 u8PortVal);


  
  
  
 
#endif