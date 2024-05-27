cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(HW12)

pico_sdk_init()

add_executable(HW12)

# target_sources(HW7 PRIVATE UARTOLED.c ssd1306.c)
target_sources(HW12 PRIVATE RCservo.c)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(HW12 pico_stdlib hardware_pwm)

pico_enable_stdio_usb(HW12 1)
pico_enable_stdio_uart(HW12 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(HW12)
