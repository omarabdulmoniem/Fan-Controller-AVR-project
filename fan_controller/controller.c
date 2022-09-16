/*
 * controller.c
 *
 *  Created on: Feb 21, 2022
 *      Author: Omar Abdel Moniem
 */

#include "dc_motor.h"
#include "lcd.h"
#include "lm35_sensor.h"



int main(void){
	uint8 temp;
	LCD_init(); /* initialize LCD driver */
	DcMotor_Init();
	LCD_moveCursor(0,4);
	LCD_displayString("FAN is ");
	LCD_moveCursor(1,4);
	LCD_displayString("Temp =    C");


	while(1){
		temp = LM35_getTemperature();

		LCD_moveCursor(0,11);
		if(temp < 30){
			DcMotor_Rotate(stop,0);
			LCD_displayString("OFF");
			LCD_moveCursor(1,11);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
		}else if((temp >= 30) && (temp < 60)){
			DcMotor_Rotate(CW,25);
			LCD_displayString("ON ");
			LCD_moveCursor(1,11);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
		}else if((temp >= 60) && (temp < 90)){
			DcMotor_Rotate(CW,50);
			LCD_displayString("ON ");
			LCD_moveCursor(1,11);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
		}else if((temp >= 90) && (temp < 100)){
			DcMotor_Rotate(CW,75);
			LCD_displayString("ON ");
			LCD_moveCursor(1,11);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
		}else if((temp >= 100) && (temp < 120)){
			DcMotor_Rotate(CW,75);
			LCD_displayString("ON ");
			LCD_moveCursor(1,11);
			LCD_intgerToString(temp);
		}else if(temp >= 120){
			DcMotor_Rotate(CW,100);
			LCD_displayString("ON ");
			LCD_moveCursor(1,11);
			LCD_intgerToString(temp);
		}
	}


}
