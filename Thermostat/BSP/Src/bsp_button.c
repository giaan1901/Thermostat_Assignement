#include "bsp_button.h"

// ------------------------------
// Read button state
// Returns 1 = pressed, 0 = not pressed
// (Assumes active-low buttons)
// ------------------------------
uint8_t BSP_Button_Read(uint8_t button_id)
{
    switch(button_id)
    {
        case BUTTON_POWER:
            return HAL_GPIO_ReadPin(POWER_BUTTON_PORT, POWER_BUTTON_PIN) == GPIO_PIN_RESET;

        case BUTTON_SET:
            return HAL_GPIO_ReadPin(SET_BUTTON_PORT, SET_BUTTON_PIN) == GPIO_PIN_RESET;

        case BUTTON_UP:
            return HAL_GPIO_ReadPin(UP_BUTTON_PORT, UP_BUTTON_PIN) == GPIO_PIN_RESET;

        case BUTTON_DOWN:
            return HAL_GPIO_ReadPin(DOWN_BUTTON_PORT, DOWN_BUTTON_PIN) == GPIO_PIN_RESET;

        default:
            return 0;
    }
}
