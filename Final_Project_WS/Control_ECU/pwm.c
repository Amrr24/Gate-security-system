/**************************************************************************
 * Module : PWM

 * Author's Name : Amr Medhat Mohamed      embedded diploma 60

 * File Name : pwm.c

 * Description : 	Source  file of PWM (for ATMEGA16 MC ) driver
 **************************************************************************/
/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

                          INCLUDES
 -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

#include "pwm.h" // H.file that have the function prototypes

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--_-_-_-__-_

                             FUNCTIONS DEFINATION
 -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--_-_-_-__-_-_*/

void  PWM_Timer0_Start(uint8 duty_cycle){
	TCNT0 = 0 ; // Set Timer Initial Value to 0
	GPIO_setupPinDirection(PWM_PORT_ID, PWM_PIN_ID, PIN_OUTPUT); // Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC
	OCR0 = duty_cycle ;   //Set Compare value

	TCCR0 = (1<<COM01)|(1<<CS01)|(1<<WGM00)|(1<<WGM01);
	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */


}
