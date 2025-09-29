/**************************************************************************
 * Module : Motor

 * Author's Name : Amr Medhat  Mohamed      embedded diploma 60

 * File Name : motor.c

 * Description : Source file of Motor driver
 **************************************************************************/
/* **************************************************************************

                          INCLUDES
  ***************************************************************************/
/*Including header files needed for this driver */
#include "motor.h" // for using the function prototypes from the header file
#include "gpio.h" // for calling functions that set the pin direction and it's value

#include "std_types.h"
/* **************************************************************************

                              GLOBAL VARIABLES
 ***************************************************************************/

uint8 duty_cycle ; // defining variable of 1 byte size to store the duty cycle will be calculated to the pwm driver to generate

/**************************************************************************

                             FUNCTIONS DEFINATION
 ***************************************************************************/
void DcMotor_Init(void){ // FUNCTION init which used to initiate the motor states
	/*PINS 4,5 in PORTB ARE CONTROL PINS OF THE MOTOR
	 *  Setting : pins 4,5 in port B as output pins
	 * start the motor in stop condition by applying zero signals to the
	   motor h bridge by making pins 4,5 in port B as output of logic low
	   which is zero .

	 */
	GPIO_setupPinDirection(MOTOR_CONTROL_PORT_ID, MOTOR_CONTROL_PIN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_CONTROL_PORT_ID, MOTOR_CONTROL_PIN2_ID, PIN_OUTPUT);
	GPIO_writePin(MOTOR_CONTROL_PORT_ID, MOTOR_CONTROL_PIN1_ID, LOGIC_LOW);
	GPIO_writePin(MOTOR_CONTROL_PORT_ID, MOTOR_CONTROL_PIN2_ID, LOGIC_LOW);
}
/* This Function 'Dc_Motor_Rotate' is responsible for controlling the direction of the motion
 and the speed of the motor depending on two data comes with calling the fuction
 which are motor state and the speed
 *Note that : state of the motor is variable which means it can be changed to three states thats
 *Note why we have made a enum of three constants .
 */
void Dc_Motor_Rotate(DcMotor_State state ){


	switch (state){
	case 0 :
		GPIO_writePin(MOTOR_CONTROL_PORT_ID, MOTOR_CONTROL_PIN2_ID, LOGIC_HIGH); // Rotate the motor clockwise direction
		break ;
	case 1 :
		GPIO_writePin(MOTOR_CONTROL_PORT_ID,MOTOR_CONTROL_PIN1_ID, LOGIC_HIGH);// Rotate the motor anti-clockwise direction
		break ;
	case 2  :
		GPIO_writePin(MOTOR_CONTROL_PORT_ID,MOTOR_CONTROL_PIN1_ID, LOGIC_LOW); // Stop the motor's motion
		GPIO_writePin(MOTOR_CONTROL_PORT_ID, MOTOR_CONTROL_PIN2_ID, LOGIC_LOW);
		break ;
	default :
		GPIO_writePin(MOTOR_CONTROL_PORT_ID, MOTOR_CONTROL_PIN1_ID, LOGIC_LOW); // Stop the motor's motion as default
		GPIO_writePin(MOTOR_CONTROL_PORT_ID, MOTOR_CONTROL_PIN2_ID, LOGIC_LOW);
		break ;
	}



}
