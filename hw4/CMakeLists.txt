cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(HW4)

pico_sdk_init()

add_executable(HW4)

target_sources(HW4 PRIVATE SPI.c)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(HW4 pico_stdlib hardware_spi)

pico_enable_stdio_usb(HW4 1)
pico_enable_stdio_uart(HW4 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(HW4)