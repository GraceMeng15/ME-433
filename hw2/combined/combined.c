#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
int main() {
    stdio_init_all();
    while (!stdio_usb_connected()) {
        sleep_ms(100);
    }
    printf("Start!\n");

    gpio_init(18);
    gpio_set_dir(18, GPIO_OUT);
    gpio_put(18, 1);            // turns LED on
    bool LED = 1;

    while (1){
        gpio_put(18, 1);            // turns LED on
        bool LED = 1;
        printf("push button to turn of LED\n");
        while (LED) {
            gpio_init(15);
            gpio_set_dir(15, GPIO_IN);
            int pushed = gpio_get(15);  // read button

            if (pushed){
                gpio_put(18, 0);        // turn off lED
                printf("button pushed, LED off.\n");
                printf("Now please enter a number between 1~100\n");
                LED = 0;
            }
        }
        
        char message[50];
        scanf("%s", message);
        printf("number read: %s\r\n",message);

        int number = atoi(message);
        sleep_ms(50);

        sleep_ms(1000);
        printf("reading ADC value on pin 26...\n");

        for (int i = 1; i<=number; i++){
            int adc = 1;
            printf("%dth ADC value: %d volts\n", i, adc);
            sleep_ms(10);
        }
        printf("\n------------- Loop again...\n");
        
    }




/*
        char message[100];
        scanf("%s", message);
        printf("message: %s\r\n",message);
        sleep_ms(50);*/
}
