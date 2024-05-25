cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(HW6)

pico_sdk_init()

add_executable(HW6)

target_sources(HW6 PRIVATE I2COLED.c ssd1306.c)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(HW6 pico_stdlib hardware_i2c hardware_adc)

pico_enable_stdio_usb(HW6 1)
pico_enable_stdio_uart(HW6 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(HW6)