#include <stdio.h>

#include "hardware/i2c.h"
#include "pico/binary_info.h"
#include "pico/stdlib.h"


// device bus address
#define ADDR _u(0b0100000)

// hardware registers
#define REG_IODIR _u(0x00)
#define REG_GPIO _u(0x09)
#define REG_OLAT _u(0x0A)

void chip_init() {
    // use the "handheld device dynamic" optimal setting (see datasheet)
    uint8_t buf[2];

    // send register number followed by its corresponding value
    buf[0] = REG_IODIR;
    buf[1] = 0b01111111; // 7 is output, others all inputs
    i2c_write_blocking(i2c_default, ADDR, buf, 2, false);
}


void set(char v){
    uint8_t buf[2];
    buf[0] = REG_OLAT;
    buf[1] = v << 7;
    i2c_write_blocking(i2c_default, ADDR, buf, 2, false);
}

uint8_t read(){
    uint8_t buf[1];
    uint8_t reg = REG_GPIO;
    i2c_write_blocking(i2c_default, ADDR, &reg, 1, true);  // true to keep master control of bus
    i2c_read_blocking(i2c_default, ADDR, buf, 1, false);   // false - finished with bus

    if ((buf[0]&0b1) == 0b1){
        return 1;
    }
    else{
        return 0;
    }
}

// void chip_write(uint8_t reg, char data){
//     uint8_t buf[2];
//     buf[0] = reg;
//     buf[1] = data;
//     i2c_write_blocking(i2c_default, ADDR, buf, 2, false);
// }

// void chip_read(uint8_t reg, uint8_t* data){
//     uint8_t buf[2];
//     buf[0] = reg;
//     i2c_write_blocking(i2c_default, ADDR, &reg, 1, true);  // true to keep master control of bus
//     i2c_read_blocking(i2c_default, ADDR, buf, 1, false);   // false - finished with bus
//     *data = buf[0] << 4 | buf[1];
// }


int main() {
    stdio_init_all();

    // I2C is "open drain", pull ups to keep signal high when no data is being sent
    i2c_init(i2c_default, 100 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    chip_init();

    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);

    sleep_ms(250); // sleep so that data polling and register update don't collide
    while (1) {
        // blink gp25
        gpio_put(25, 1);            // turns LED on
        //set(1);
        sleep_ms(100);
        gpio_put(25, 0);            // turns LED on
        //set(0);
        sleep_ms(100);


        // read from gp0
        uint8_t button = read();
        //gpio_put(25, button);  
        if (button){
            set(1);
        }
        else{
            set(0);
        }
    }
}
