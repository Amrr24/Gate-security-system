/**************************************************************************
 * Module : PWM

 * Author's Name : Amr Medhat  Mohamed      embedded diploma 60

 * File Name : pwm.h

 * Description : 	Header  file of PWM (for ATMEGA16 MC ) driver
 **************************************************************************/
#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h> // Library that is needed in the c file of this driver for defining avr registers
#include "gpio.h" // For calling functions that set the pin direction and it's value
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define PWM_PORT_ID PORTB_ID
#define PWM_PIN_ID  PIN3_ID
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 This function used for initializing Timer0 to calculate the proper duty cycle using PWM protocol
 */
void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* PWM_H_ */
