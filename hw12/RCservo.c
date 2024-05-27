#include <stdio.h>
#include "hardware/pwm.h"
#include "pico/stdlib.h"

#define SERVO_PIN 16 // the built-in LED pin on the Pico, used for the servo

// Function to convert an angle to a duty cycle percentage
float angle_to_duty_cycle(float angle) {
    // Ensure angle is within the expected range
    if (angle < 0.0f) angle = 0.0f;
    if (angle > 180.0f) angle = 180.0f;

    // Convert angle to duty cycle between 2.5% and 12.5%
    return 2.5f + (angle / 180.0f) * 10.0f;
}

void set_pwm_duty_cycle(uint slice_num, uint16_t wrap, float duty_cycle_percent) {
    uint16_t level = (uint16_t)((duty_cycle_percent / 100.0f) * wrap);
    pwm_set_gpio_level(SERVO_PIN, level);
}

int main() {
    stdio_init_all();

    // Initialize GPIO
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM); // Set the LED Pin to be PWM
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN); // Get PWM slice number
    float div = 250; // Clock divider
    uint16_t wrap = 10000; // When to rollover, calculated for 50Hz
    pwm_set_clkdiv(slice_num, div); // Set the clock divider
    pwm_set_wrap(slice_num, wrap); // Set the wrap value
    pwm_set_enabled(slice_num, true); // Turn on the PWM

    while (1) {
        // Move from 0 to 180 degrees in 2 seconds
        for (float angle = 0; angle <= 180; angle += 1.0f) {
            float duty_cycle = angle_to_duty_cycle(angle);
            set_pwm_duty_cycle(slice_num, wrap, duty_cycle);
            sleep_ms(5); // Adjust speed of transition (2 seconds total for 180 steps)
        }

        // Move from 180 to 0 degrees in 2 seconds
        for (float angle = 180; angle >= 0; angle -= 1.0f) {
            float duty_cycle = angle_to_duty_cycle(angle);
            set_pwm_duty_cycle(slice_num, wrap, duty_cycle);
            sleep_ms(5); // Adjust speed of transition (2 seconds total for 180 steps)
        }
    }

    return 0;
}