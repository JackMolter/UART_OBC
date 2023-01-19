#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/uart.h"

#include "UART.h"

uint8_t data[12] = {3,32,2,4,12,34,3,7,8,9,19,0};


void uart_setup() {
    uart_init(UART_ID, UART_BAUD_RATE);     // sets baud and peripheral

    gpio_set_function(UART_TX, GPIO_FUNC_UART);     // sets pins
    gpio_set_function(UART_RX, GPIO_FUNC_UART);

    uart_set_hw_flow(UART_ID, false, false);    // flow control

    // TODO: add interrupt and DMA stuff 
    // This will be useful for the large data transfers of the OpenLST
}

void openlst_setup() {

}
 
void uart_test() {
    sleep_ms(100);
    //uart_putc_raw(UART_ID, 'J'); // sends a J
    //uart_putc(UART_ID, 'M');
    uart_puts(UART_ID, "Jack was here");
}

void send_packet(uint8_t *data, int len, int dest_hwid) {

}

int main() {
    stdio_init_all();
    uart_setup();
    //uart_test();
}