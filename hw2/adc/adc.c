#include "hardware/adc.h"
#include "pico/stdlib.h"
#include <stdio.h>

int main() {
    stdio_init_all();

    while (!stdio_usb_connected()) {
        sleep_ms(100);
    }
    printf("Start!\n");

    while(1){
        adc_init(); // init the adc module
        adc_gpio_init(26); // set ADC0 pin to be adc input instead of GPIO
        adc_select_input(0); // select to read from ADC0

        uint16_t result = adc_read();
        printf("adc value: %d\n", result);

        sleep_ms(100);
    }
}