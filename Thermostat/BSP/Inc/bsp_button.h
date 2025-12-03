#ifndef BSP_BUTTON_H
#define BSP_BUTTON_H

#include "stm32f4xx_hal.h"

// Button identifiers
#define BUTTON_POWER  1
#define BUTTON_SET    2
#define BUTTON_UP     3
#define BUTTON_DOWN   4

#define POWER_BUTTON_PORT   GPIOA
#define POWER_BUTTON_PIN    GPIO_PIN_1

#define SET_BUTTON_PORT     GPIOA
#define SET_BUTTON_PIN      GPIO_PIN_2

#define UP_BUTTON_PORT      GPIOA
#define UP_BUTTON_PIN       GPIO_PIN_3

#define DOWN_BUTTON_PORT    GPIOA
#define DOWN_BUTTON_PIN     GPIO_PIN_4

uint8_t BSP_Button_Read(uint8_t button);

#endif
