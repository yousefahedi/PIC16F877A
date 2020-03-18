/*
 *	LCD_CFG_PIC.h
 *
 *  Created on: Feb 22, 2020
 *      Author: Yousef Ahed
 */
 
#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/*Defining ports and pins connected to LCD*/

/*RS Pin*/
#define RS_Port GPIO_PortE
#define RS_Pin	PIN2

/*Read/Write Enable pin*/
//#define R/W_Port  
//#define R/W_PIn

/*LCD enable pin*/
#define E_Port GPIO_PortE
#define E_Pin  PIN1

/*Data Port connected to LCD*/
#define Data_Port GPIO_PortD






#endif