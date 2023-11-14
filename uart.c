#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <errno.h>


int uart_transmit(int uart0_filestream, char* data, int length)
{
    int count = write(uart0_filestream, data, length);
    if (count < 0) {
        perror("UART TX error");
        return -1;
    }
    return count;
}

int uart_init(int port_num, int speed) {
    char port[20];
    sprintf(port, "/dev/ttyS%d", port_num);
    int uart0_filestream = open(port, O_RDWR | O_NOCTTY | O_NDELAY);
    if (uart0_filestream == -1) {
        perror("Failed to open UART");
        return -1;
    }
    
    struct termios options;
    memset(&options, 0, sizeof(options));  // 清空 options 结构体
    
    if (tcgetattr(uart0_filestream, &options) != 0) {
        perror("Failed to get attributes");
        close(uart0_filestream);
        return -1;
    }
    
    cfsetospeed(&options, speed);
    cfsetispeed(&options, speed);

    options.c_cflag &= ~(PARENB | CSTOPB | CSIZE);  // 清除奇偶校验、停止位和数据位设置
    options.c_cflag |= CS8;  // 设置为8位数据位
    options.c_iflag = IGNPAR;  // 忽略奇偶校验错误的输入字符
    options.c_oflag = 0;  // 输出模式设置为默认
    options.c_lflag = 0;  // 非规范模式

    if (tcsetattr(uart0_filestream, TCSANOW, &options) != 0) {
        perror("Failed to set attributes");
        close(uart0_filestream);
        return -1;
    }

    tcflush(uart0_filestream, TCIOFLUSH);  // 清空输入输出缓冲区
    return uart0_filestream;
}


void main(char* args)
{
    int uart0_filestream = uart_init(3, B921600);
    char* data = "Hello World!";
    while (1)
    {
        uart_transmit(uart0_filestream, data, strlen(data));
        //sleep(1);
        usleep(1000);  // 1 毫秒
    }
    close(uart0_filestream);
}