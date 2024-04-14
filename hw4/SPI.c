#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"

static inline void cs_select() {
    asm volatile("nop \n nop \n nop");
    gpio_put(PICO_DEFAULT_SPI_CSN_PIN, 0);  // Active low
    asm volatile("nop \n nop \n nop");
}

static inline void cs_deselect() {
    asm volatile("nop \n nop \n nop");
    gpio_put(PICO_DEFAULT_SPI_CSN_PIN, 1);
    asm volatile("nop \n nop \n nop");
}

static void write_register(uint16_t data) {
    uint8_t buf[2];
    buf[0] = data  >> 8;  // remove read bit as this is a write
    buf[1] = data & 0xFF;
    // printf("buff0: %x\n", buf[0]);
    // printf("buff1: %x\n\n", buf[1]);
    cs_select();
    spi_write_blocking(spi_default, buf, 2);
    cs_deselect();
}


int main() {
    stdio_init_all();
    while (!stdio_usb_connected()) {
        sleep_ms(100);
    }
    printf("Start!\n");

    // This example will use SPI0 at 0.5MHz.
    spi_init(spi_default, 500 * 1000);
    gpio_set_function(PICO_DEFAULT_SPI_RX_PIN, GPIO_FUNC_SPI);
    gpio_set_function(PICO_DEFAULT_SPI_SCK_PIN, GPIO_FUNC_SPI);
    gpio_set_function(PICO_DEFAULT_SPI_TX_PIN, GPIO_FUNC_SPI);

    // Chip select is active-low, so we'll initialise it to a driven-high state
    gpio_init(PICO_DEFAULT_SPI_CSN_PIN);
    gpio_set_dir(PICO_DEFAULT_SPI_CSN_PIN, GPIO_OUT);
    gpio_put(PICO_DEFAULT_SPI_CSN_PIN, 1);

    while (1){
        // initialize

        //  D9 D8 D7 D6 D5 D4 D3 D2 D1 D0 x x
        //  1  1  1  1  1  1  1  1  1  1  0 0
        uint16_t triSecond = 0;
        uint16_t triData = 0;
        uint16_t sinSecond = 0;
        uint16_t sinData = 0;

        for (int t = 0; t < 2000; t++){ // 2000 samples in 1s
            uint16_t triFirst = 0x7000;
            uint16_t sinFirst = 0xf000;

            // triangle wave: -----------------------------------
            if (t < 1000){
                triSecond = (int)(t * 1.024);}
            else{
                triSecond = 2048 - (int)(t * 1.024);}
            triData = (triFirst>>2 | triSecond)<<2;

            // sin wave: -----------------------------------
            double phase = (double)t / 1000.0 * 2 * M_PI;       // complete 2π radians every 1000 samples
            sinSecond = (uint16_t)((sin(phase) + 1.0) * 512.0); // scale from [-1, 1] to [0, 1024]
            sinData = (sinFirst >> 2 | sinSecond) << 2;

            write_register(triData);
            write_register(sinData);
            sleep_us(500);
        }
    }
}