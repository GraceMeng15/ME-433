cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(HW3)

pico_sdk_init()

add_executable(HW3)

target_sources(HW3 PRIVATE combined.c)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(HW3 pico_stdlib hardware_adc)

pico_enable_stdio_usb(HW3 1)
pico_enable_stdio_uart(HW3 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(HW3)