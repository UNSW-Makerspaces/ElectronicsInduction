#include <stdio.h>
#include <cmath>
#include "pico/stdlib.h"
#include "WS2812.h"

#define LED_PIN 25
#define LED_LENGTH 1

int main() {

    stdio_init_all();
    WS2812 ledStrip(
        LED_PIN,            
        LED_LENGTH,         
        pio0,               
        0,                  
        WS2812::FORMAT_GRB  
    );

    ledStrip.fill( WS2812::RGB(255, 255, 255) );
    ledStrip.show();
    sleep_ms(10);

    while (true) {
        ledStrip.fill(WS2812::RGB((uint8_t)rand(), (uint8_t)rand(), (uint8_t)rand()));
        ledStrip.show();
        sleep_ms(50);
    }

    return 0;
}
