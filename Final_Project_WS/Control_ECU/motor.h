/**************************************************************************
 * Module : Motor

 * Author's Name : Amr Medhat  Mohamed      embedded diploma 60

 * File Name : motor.h
 *
 * Description : 	Header  file of Motor driver
 **************************************************************************/
/*
 * To call this header file and it's components once
 */
#ifndef MOTOR_H_
#define MOTOR_H_
/********************************************************************************
                          INCLUDES
 *********************************************************************************/
#include "gpio.h" // for calling functions that set the pin direction and it's value
/*
 * Enum of type DcMotor_State that has three choices that can be implemented
 has : Rot_CW : Rotate the motor in clockwise direction
  Rot_A_CW : Rotate the motor in anti-clockwise direction
  Stop : To stop the Motor
 */
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define MOTOR_CONTROL_PORT_ID PORTB_ID
#define MOTOR_CONTROL_PIN1_ID PIN4_ID
#define MOTOR_CONTROL_PIN2_ID PIN5_ID
typedef enum {
	Rot_CW, Rot_A_CW , Stop
}DcMotor_State;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void DcMotor_Init(void);


void Dc_Motor_Rotate(DcMotor_State state );

#endif /* MOTOR_H_ */
