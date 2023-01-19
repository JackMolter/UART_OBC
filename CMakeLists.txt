cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(UART_OBC)

pico_sdk_init()

add_executable(UART
    UART.c
)

target_link_libraries(UART
    pico_stdlib

    
    )

pico_enable_stdio_usb(UART 1) # from video, enables USB for minicom 
pico_enable_stdio_uart(UART 0)

pico_add_extra_outputs(UART)