 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: source file for the LM35 Temperature Sensor driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#include "lm35_sensor.h"

#include "adc.h"

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void)
{
	struct {
		ADC_ReferenceVolatge ref_volt;
		ADC_Prescaler prescaler;
	}config;
	config.ref_volt = Internal;
	config.prescaler = 8;
	ADC_init(&config); 			/* initialize ADC driver */
	uint8 temp_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}

