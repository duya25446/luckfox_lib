#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "lib_uart.h"


void main(char* args)
{
    int uart0_filestream = uart_init(3, B921600);
    unsigned char* data = "Hello World!";
    while (1)
    {
        uart_transmit(uart0_filestream, data, strlen(data));
        sleep(1);
        //usleep(1);  // 1 毫秒
    }
    close(uart0_filestream);
}