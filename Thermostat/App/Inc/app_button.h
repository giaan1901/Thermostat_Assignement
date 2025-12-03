#ifndef APP_BUTTONS_H
#define APP_BUTTONS_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    BTN_NONE = 0,
    BTN_POWER_SHORT,
    BTN_SET_SHORT,
    BTN_UP_SHORT,
    BTN_DOWN_SHORT
} ButtonEvent;

void APP_Buttons_Init(void);
void APP_Buttons_Update(void);   // call every 20 ms
ButtonEvent APP_Buttons_GetEvent(void);

#endif
