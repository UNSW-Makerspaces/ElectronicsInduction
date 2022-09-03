#ifndef PICOGAMEPAD_v3A_BOARD_CONFIG_H_
#define PICOGAMEPAD_v3A_CONFIG_H_

#include <GamepadEnums.h>

#define PIN_DPAD_UP     2           // UP
#define PIN_DPAD_DOWN   3           // DOWN
#define PIN_DPAD_RIGHT  4           // RIGHT
#define PIN_DPAD_LEFT   5           // LEFT
#define PIN_BUTTON_A    -1          // 
#define PIN_BUTTON_B    -1          //
#define PIN_BUTTON_START -1 
#define PIN_BUTTON_SELECT -1 

// SOCD 

#define BOARD_LEDS_PIN 0

#define LED_BRIGHTNESS_MAXIMUM 255
#define LED_BRIGHTNESS_STEPS 5
#define LED_FORMAT LED_FORMAT_GRB
#define LEDS_PER_PIXEL 1

#define BUTTON_LAYOUT BUTTON_LAYOUT_BUTTONS_BASIC

#endif
