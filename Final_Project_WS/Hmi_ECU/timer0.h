/**************************************************************************
 * Module : Timer

 * Author's Name : Amr Medhat  Mohamed      embedded diploma 60

 * File Name : timer.h
 *
 * Description : 	Header  file of Timer 0 Driver
 **************************************************************************/
/********************************************************************************

                          INCLUDES
 *********************************************************************************/
#include "std_types.h"
/*
 * To call this header file and it's components once
 */
#ifndef TIMER0_H_
#define TIMER0_H_
/***************************************************************************************
 *                                Definitions                                  *
 ***************************************************************************************/
/*
 * Eum created for the selection of the clock needed for the application
 */

typedef enum {
	NO_CLOCK , CLOCK_1,CLOCK_8,CLOCK_64,CLOCK_256,CLOCK_1024,EX_CLOCK_FALL ,EX_CLOCK_RISE
}Prescaler;
/*
 * Eum created for the selection of timer mode  needed for the application
 */
typedef enum {
	NORMAL , PWM_PH , CTC , FAT_PWM
}Mode;
/*
 * Structure created for the selection these things for the application in sequence
 1)Clock
 2)Mode
 3)TCNT0 Initial Value
 4) OCR0  Compare value (in case of CTC mode)
 */
typedef struct {
	/*1*/Prescaler clock ;
	/*2*/Mode mode ;
	/*3*/uint16 init_value ;
	/*4*/uint16 comp_value ;
}Timer0_config;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void Timer0_init(const Timer0_config *ptr);
void Timer0_SetcallBack(void(*a_ptr)(void));
void Time0_deinit(void);

#endif /* TIMER0_H_ */
