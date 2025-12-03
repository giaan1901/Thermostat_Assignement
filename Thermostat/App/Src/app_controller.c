#include "app_controller.h"
#include "app_button.h"
#include "app_display.h"
#include "bsp_temp_sensor.h"
#include "bsp_lcd.h"

// -----------------------------
// Internal variables
// -----------------------------
static AppState currentState = STATE_POWER_OFF;
static int currentTemp = 0;
static int setTemp = 25;        // Default target temp
static uint8_t fanOn = 0;       // 0 = OFF, 1 = ON

// Hysteresis to prevent rapid toggling
#define FAN_HYSTERESIS 1

// -----------------------------
// Initialization
// -----------------------------
void APP_Controller_Init(void)
{
    currentState = STATE_POWER_OFF;
}

// -----------------------------
// Update (called every 500 ms)
// -----------------------------
void APP_Controller_Update(void)
{
    ButtonEvent evt = APP_Buttons_GetEvent();

    switch (currentState)
    {
        // ============================================
        // POWER OFF STATE
        // ============================================
        case STATE_POWER_OFF:
        {
            if (evt == BTN_POWER_SHORT)
            {
                currentState = STATE_RUNNING;
                BSP_LCD_Clear();
            }
            break;
        }

        // ============================================
        // RUNNING MODE (normal thermostat mode)
        // ============================================
        case STATE_RUNNING:
        {
            // Handle button input
            if (evt == BTN_POWER_SHORT)
            {
                fanOn = 0;
                BSP_LCD_Clear();
                currentState = STATE_POWER_OFF;
                break;
            }
            else if (evt == BTN_SET_SHORT)
            {
                currentState = STATE_SETTING_TEMP;
                APP_Display_ShowSetTemp(setTemp);
                break;
            }

            // Read temperature
            currentTemp = (int)BSP_TempSensor_ReadCelsius();

            // -------- Fan Control (ON/OFF with hysteresis) --------
            if (currentTemp > setTemp + FAN_HYSTERESIS)
                fanOn = 1;
            else if (currentTemp < setTemp - FAN_HYSTERESIS)
                fanOn = 0;

            // Update LCD
            APP_Display_ShowTemperature(currentTemp);
            APP_Display_ShowFanState(fanOn);

            break;
        }

        // ============================================
        // SET TEMPERATURE MODE
        // ============================================
        case STATE_SETTING_TEMP:
        {
            if (evt == BTN_SET_SHORT)
            {
                // Exit setting mode
                BSP_LCD_Clear();
                currentState = STATE_RUNNING;
                break;
            }

            if (evt == BTN_UP_SHORT && setTemp < 60)
                setTemp++;
            else if (evt == BTN_DOWN_SHORT && setTemp > 0)
                setTemp--;

            // Refresh LCD
            APP_Display_ShowSetTemp(setTemp);

            break;
        }
    }
}
