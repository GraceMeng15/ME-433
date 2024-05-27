#include <stdio.h>
#include <string.h> // for memset
#include "ssd1306.h"
#include "hardware/i2c.h"
#include "hardware/adc.h"
#include "pico/stdlib.h"
#include "font.h"


void drawChar(int x, int y, char letter){
    for (int i=0; i<5; i++){
        char c = ASCII[(letter-0x20)][i];
        for (int j=0; j<8; j++){
            char bit = (c>>j)&1;

            if (bit == 0b1){
                ssd1306_drawPixel(x+i, y+j, 1);
            }
            else{
                ssd1306_drawPixel(x+i, y+j, 0);
            }
        }
    }
}


void drawMessage(int x, int y, char* m){
    int i = 0;
    while (m[i]){
        drawChar(x+5*i+1, y, m[i]);
        i++;
    }
}


int main(){
    stdio_init_all();

    // Initialize I2C
    i2c_init(i2c_default, 100 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);

    ssd1306_setup();

    // Initialize GPIO
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);

    // Initialize ADC
    adc_init();             // init the adc module
    adc_gpio_init(26);      // set ADC0 pin to be adc input instead of GPIO
    adc_select_input(0);    // select to read from ADC0

    sleep_ms(250); // sleep so that data polling and register update don't collide

    while (1) {
        unsigned int t_start = to_us_since_boot(get_absolute_time());

        uint16_t rawadc = adc_read();
        float adc = 3.3/4095*rawadc;

        char message[50];
        sprintf(message,"ADC Value(0~3.3): %.2f V", adc);
        drawMessage(5, 5, message);
        ssd1306_update();
        
        unsigned int t_end = to_us_since_boot(get_absolute_time());
        double fps = 1000000/(t_end - t_start);
        sprintf(message,"fps: %.1f Hz", fps);
        drawMessage(20, 15, message);
        ssd1306_update();
    }
}