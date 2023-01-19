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
    uart_init(OPENLST_UART_ID, OPENLST_UART_BAUD_RATE);

    gpio_set_function(OPENLST_UART_TX, GPIO_FUNC_UART);     // sets pins
    gpio_set_function(OPENLST_UART_RX, GPIO_FUNC_UART);

    uart_set_hw_flow(OPENLST_UART_ID, false, false);    // flow control

}
 
void uart_test() {
    sleep_ms(100);
    //uart_putc_raw(UART_ID, 'J'); // sends a J
    //uart_putc(UART_ID, 'M');
    uart_puts(UART_ID, "Jack was here");
}

// simple test of sending and recieivng ack 
void uart_ack_test() {
    sleep_ms(100);
    uint8_t ack_packet[9]; // initilizes and sets length of the ack packet
    uint8_t acknowledge[9];

    ack_packet[0] = 0x22;   // always the same
    ack_packet[1] = 0x69;   // always the same
    ack_packet[2] = 0x06;
    ack_packet[3] = 0xFF;
    ack_packet[4] = 0xFF;
    ack_packet[5] = 0x3D;   // increments up 1 each time ??
    ack_packet[6] = 0x59;
    ack_packet[7] = 0x01;
    ack_packet[8] = 0x10;
    uart_write_blocking(UART_ID, ack_packet, 9);
    uart_read_blocking(UART_ID, acknowledge, 9);
}

void uart_get_telem() {
    sleep_ms(100);
    uint8_t get_telem[];
    uint8_t telem[];

    get_telem[0] =

}

int send_packet(uint8_t *data, int len, int dest_hwid) {

}

int main() {
    stdio_init_all();
    uart_setup();
    //uart_test();
    //uart_ack_test();
}