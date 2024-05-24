cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(HW5)

pico_sdk_init()

add_executable(HW5)

target_sources(HW5 PRIVATE I2C.c)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(HW5 pico_stdlib hardware_i2c)

pico_enable_stdio_usb(HW5 1)
pico_enable_stdio_uart(HW5 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(HW5)