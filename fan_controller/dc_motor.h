/*
 * dc_motor.h
 *
 *  Created on: Feb 20, 2022
 *      Author: pc
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define stop 0
#define CW 1
#define ACW 2
#define Motor_Port PORTB_ID
#define IN1 PIN0_ID
#define IN2 PIN1_ID
#define EN1 PIN3_ID

typedef uint8 DcMotor_State;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State state,uint8 speed);



#endif /* DC_MOTOR_H_ */
