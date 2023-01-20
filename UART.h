// values 
#define UART_BAUD_RATE 115200
#define OPENLST_UART_BAUD_RATE 115200
#define UART_ID uart0
#define OPENLST_UART_ID uart0   // from the OpenLST schematic

// pins
#define UART_TX 16  // for OBC
#define UART_RX 17
// #define UART_TX 4
// #define UART_RX 5 
#define OPENLST_UART_TX 5
#define OPENLST_UART_RX 4

// functions 

// initilization
void uart_setup();
void openlst_setup();

// tests sending something
void uart_test();
void uart_ack_test();

// get telem command 
void uart_get_telem(); 

// send a packet 
int send_packet(uint8_t *data, int len, int dest_hwid);

