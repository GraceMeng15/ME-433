add_executable(adc
adc.c
        )

# pull in common dependencies
target_link_libraries(adc pico_stdlib hardware_adc)
pico_enable_stdio_usb(adc 1)
pico_enable_stdio_uart(adc 0)
# create map/bin/hex file etc.
pico_add_extra_outputs(adc)

# add url via pico_set_program_url
# example_auto_set_url(blink)
