/**************************************************************************
 * Module : Buzzer

 * Author's Name : Amr Medhat  Mohamed      embedded diploma 60

 * File Name : buzzer.c

 * Description : Source file of Buzzer driver
 **************************************************************************/
/***************************************************************************
                          INCLUDES
 ***************************************************************************/
#include "buzzer.h"
#include "gpio.h"
/**************************************************************************
                             FUNCTIONS DEFINATION
 ***************************************************************************/
/*
 * This Function Used for setting type of the pin connected to buzzer to be output
 */
void Buzzer_inint(void){
	GPIO_setupPinDirection(PORT_BUZZER_ID,PIN_BUZZER_ID,PIN_OUTPUT); // Output Pin

}
/*
 * This Function Used for setting the pin to give logic high  --> Turn on Buzzer
 */
void Buzzer_On(void){
	GPIO_writePin(PORT_BUZZER_ID,PIN_BUZZER_ID, LOGIC_HIGH);//Turn on Buzzer
}
/*
 * This Function Used for setting the pin to give logic low  --> Turn off Buzzer
 */
void Buzzer_Off(void){
	GPIO_writePin(PORT_BUZZER_ID,PIN_BUZZER_ID, LOGIC_LOW); // Turn off Buzzer
}
