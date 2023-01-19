// values 
#define UART_BAUD_RATE 115200
#define UART_ID uart0

// pins
#define UART_TX 16
#define UART_RX 17
// #define UART_TX 4
// #define UART_RX 5

// functions 

// initilization
void uart_setup();
void openlst_setup();

// tests sending something
void uart_test();

// send a packet 
int send_packet(uint8_t *data, int len, int dest_hwid);
