#ifndef APP_CONTROLLER_H
#define APP_CONTROLLER_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    STATE_POWER_OFF = 0,
    STATE_RUNNING,
    STATE_SETTING_TEMP
} AppState;

void APP_Controller_Init(void);
void APP_Controller_Update(void);

#endif

