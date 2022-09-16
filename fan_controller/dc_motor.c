/*
 * dc_motor.c
 *
 *  Created on: Feb 20, 2022
 *      Author: Omar Abdel Moniem
 */


#include "dc_motor.h"
#include "gpio.h"
#include "pwm.h"


void DcMotor_Init(void){
	GPIO_setupPinDirection(Motor_Port,IN1,PIN_OUTPUT);
	GPIO_setupPinDirection(Motor_Port,IN2,PIN_OUTPUT);

	GPIO_writePin(Motor_Port,IN1,LOGIC_LOW);
	GPIO_writePin(Motor_Port,IN2,LOGIC_LOW);
}


void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	// setting direction
	switch(state){
	case stop:
		GPIO_writePin(Motor_Port,IN1,LOGIC_LOW);
		GPIO_writePin(Motor_Port,IN2,LOGIC_LOW);
		break;
	case CW:
		GPIO_writePin(Motor_Port,IN1,LOGIC_LOW);
		GPIO_writePin(Motor_Port,IN2,LOGIC_HIGH);
		break;
	case ACW:
		GPIO_writePin(Motor_Port,IN1,LOGIC_HIGH);
		GPIO_writePin(Motor_Port,IN2,LOGIC_LOW);
		break;
	default:
		GPIO_writePin(Motor_Port,IN1,LOGIC_LOW);
		GPIO_writePin(Motor_Port,IN2,LOGIC_LOW);
		break;
	}

	// setting speed
	if((speed >= 0) && (speed <= 100)){
		PWM_Timer0_Start(speed);
	}

}

