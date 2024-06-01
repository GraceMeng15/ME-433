#include <stdio.h>
#include <string.h> // for memset
#include "hardware/i2c.h"
#include "hardware/uart.h"
#include "hardware/irq.h"
#include "pico/stdlib.h"

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


char m[100];
int i = 0;


void on_uart_rx() {
    while (uart_is_readable(UART_ID)) {
        uint8_t ch = uart_getc(UART_ID);
        
        // read everything into buffer unless /r /n: print to terminal
        if (ch == '\r' | ch == '\n'){
            m[i] = '\0';
            printf("Received: %s\n", m);
            memset(m, '\0', 100);
            i = 0;
        }
        else{
            m[i] = ch;
            i++;
        }

        chars_rxed++;
    }
}



int main(){
    stdio_init_all();

    // Initialize I2C
    i2c_init(i2c_default, 100 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);

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

    while (1) {
        int data;
        char buf[50];
        scanf("%d", &data);
        printf("data: %d\n", data);
        sprintf(buf, "%d", data);
        uart_puts(UART_ID, buf);
    }
}

