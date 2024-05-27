#include <stdio.h>
#include <string.h> // for memset
#include "ssd1306.h"
#include "hardware/i2c.h"
#include "hardware/uart.h"
#include "hardware/irq.h"
#include "pico/stdlib.h"
#include "font.h"

#define UART_ID uart0
#define BAUD_RATE 115200
#define DATA_BITS 8
#define STOP_BITS 1
#define PARITY    UART_PARITY_NONE

// We are using pins 0 and 1, but see the GPIO function select table in the
// datasheet for information on which other pins can be used.
#define UART_TX_PIN 0
#define UART_RX_PIN 1

static int chars_rxed = 0;



int i = 0;
char m[100];

// void clearMessage(){
// ;
// }

void drawMessage(int x, int y, char* m);

void on_uart_rx() {
    while (uart_is_readable(UART_ID)) {
        uint8_t ch = uart_getc(UART_ID);
        
        if (ch == '\r' | ch == '\n'){
            drawMessage(0, 0, m);
            i = 0;
        }
        else{
            m[i] = ch;
            i++;
        }

        // read everything into buffer unless /r /n
        // clean

        if (uart_is_writable(UART_ID)) {
            // Change it slightly first!
            ch++;
            uart_putc(UART_ID, ch);
        }
        chars_rxed++;
    }
}




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

    sleep_ms(250); // sleep so that data polling and register update don't collide

    // Initialize UART
    uart_init(UART_ID, 2400);

    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    int __unused actual = uart_set_baudrate(UART_ID, BAUD_RATE);

    uart_set_hw_flow(UART_ID, false, false);

    uart_set_format(UART_ID, DATA_BITS, STOP_BITS, PARITY);

    uart_set_fifo_enabled(UART_ID, false);

    int UART_IRQ = UART_ID == uart0 ? UART0_IRQ : UART1_IRQ;

    irq_set_exclusive_handler(UART_IRQ, on_uart_rx);
    irq_set_enabled(UART_IRQ, true);

    uart_set_irq_enables(UART_ID, true, false);

    //uart_puts(UART_ID, "\nHello, uart interrupts\n");

    while (1) {
        tight_loop_contents();
    }
}

