#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "lib_uart.h"
#include "lib_gpio.h"
#include "main.h"
#include "lcd.h"
#include "lcd_init.h"

// 55 54 34 4
void main(char* args)
{
    
    LCD_Init();
    LCD_Fill(0,0,240,240,BLACK);
    // int uart0_filestream = uart_init(3, B921600);
    // unsigned char* data = "Hello World!";
    // create_uart_rx_task(uart0_filestream);
    // while (1)
    // {
    //     uart_transmit(uart0_filestream, data, strlen(data));
    //     sleep(1);
    //     //usleep(1);  // 1 毫秒
    // }
    // close(uart0_filestream);
}