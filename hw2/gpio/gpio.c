#include <stdio.h>
#include "pico/stdlib.h"
int main() {
    stdio_init_all();
    while (!stdio_usb_connected()) {
        sleep_ms(100);
    }
    printf("Start!\n");
 
    while (1) {
        gpio_init(18);
        gpio_set_dir(18, GPIO_OUT);
        gpio_put(18, 1);
        // gpio_get(PIN_NUM);
    }
}