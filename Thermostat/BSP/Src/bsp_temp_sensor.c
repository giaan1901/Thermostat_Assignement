#include "bsp_temp_sensor.h"

extern ADC_HandleTypeDef hadc1;

float BSP_TempSensor_ReadCelsius(void) {
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    uint32_t adc_val = HAL_ADC_GetValue(&hadc1);
    float temp = adc_val * 3.3 / 4095 * 100; // LM35 conversion
    return temp;
}

