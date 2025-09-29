/**************************************************************************
 * Module : Buzzer

 * Author's Name : Amr Medhat  Mohamed      embedded diploma 60

 * File Name : buzzer.h
 *
 * Description : 	Header  file of Buzzer driver
 **************************************************************************/
/********************************************************************************

                          INCLUDES
 *********************************************************************************/
#include "gpio.h"
/*
 * To call this header file and it's components once
 */
#ifndef BUZZER_H_
#define BUZZER_H_
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define PORT_BUZZER_ID PORTD_ID // Configure Port used for the buzzer
#define PIN_BUZZER_ID PIN4_ID// Configure special pin  used for the buzzer output
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void Buzzer_inint(void); // Initialize Buzzer
void Buzzer_On(void); // Turn On Buzzer state
void Buzzer_Off(void); // Turn Off Buzzer state

#endif /* BUZZER_H_ */
