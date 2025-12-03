#include "app_button.h"
#include "bsp_button.h"

// --------------------------------------
// Short press = less than 500 ms
// 20 ms update interval → 25 ticks
// --------------------------------------
#define SHORT_PRESS_TICKS   25   // 25 * 20ms = 500ms

typedef struct {
    uint8_t isDown;     // 1 when button is currently pressed
    uint16_t counter;   // counts how long the button is held
} BtnState;

static BtnState btnPower, btnSet, btnUp, btnDown;
static ButtonEvent lastEvent = BTN_NONE;

void APP_Buttons_Init(void)
{
    btnPower = (BtnState){0};
    btnSet   = (BtnState){0};
    btnUp    = (BtnState){0};
    btnDown  = (BtnState){0};

    lastEvent = BTN_NONE;
}

// Process ONE button
static ButtonEvent processButton(BtnState *btn, uint8_t rawState,  ButtonEvent shortEvent)
{
    if (rawState)      // Button is pressed (active-low → BSP returns 1)
    {
        if (!btn->isDown) {
            btn->isDown = 1;
            btn->counter = 0;
        } else {
            btn->counter++;
        }
    }
    else               // Button released
    {
        if (btn->isDown) {      // Just released
            btn->isDown = 0;

            if (btn->counter < SHORT_PRESS_TICKS)
                return shortEvent;  // short press detected
        }
    }

    return BTN_NONE;
}

void APP_Buttons_Update(void)
{
    lastEvent = BTN_NONE;

    // Read all buttons from BSP
    uint8_t rPower = BSP_Button_Read(BUTTON_POWER);
    uint8_t rSet   = BSP_Button_Read(BUTTON_SET);
    uint8_t rUp    = BSP_Button_Read(BUTTON_UP);
    uint8_t rDown  = BSP_Button_Read(BUTTON_DOWN);

    ButtonEvent e;

    // Process each button in priority order
    e = processButton(&btnPower, rPower, BTN_POWER_SHORT);
    if (e != BTN_NONE) { lastEvent = e; return; }

    e = processButton(&btnSet, rSet, BTN_SET_SHORT);
    if (e != BTN_NONE) { lastEvent = e; return; }

    e = processButton(&btnUp, rUp, BTN_UP_SHORT);
    if (e != BTN_NONE) { lastEvent = e; return; }

    e = processButton(&btnDown, rDown, BTN_DOWN_SHORT);
    if (e != BTN_NONE) { lastEvent = e; return; }
}

ButtonEvent APP_Buttons_GetEvent(void)
{
    ButtonEvent e = lastEvent;
    lastEvent = BTN_NONE;
    return e;
}
