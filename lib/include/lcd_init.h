#ifndef __LCD_INIT_H
#define __LCD_INIT_H
#include "main.h"

#define USE_HORIZONTAL 3  //���ú�������������ʾ 0��1Ϊ���� 2��3Ϊ����


#define LCD_W 240
#define LCD_H 240



//-----------------LCD�˿ڶ���---------------- 

// #define LCD_SCLK_Clr() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET)//SCL=SCLK
// #define LCD_SCLK_Set() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET)

// #define LCD_MOSI_Clr() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_RESET)//SDA=MOSI
// #define LCD_MOSI_Set() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET)

// #define LCD_RES_Clr()  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_RESET)//RES
// #define LCD_RES_Set()  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_SET)

// #define LCD_DC_Clr()   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_RESET)//DC
// #define LCD_DC_Set()   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_SET)

// #define LCD_CS_Clr()   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET)//BLK
// #define LCD_CS_Set()   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET)

// #define LCD_BLK_Clr()  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_RESET)//BLK
// #define LCD_BLK_Set()  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_SET)


//void LCD_GPIO_Init(void);//��ʼ��GPIO
void LCD_Writ_Bus(unsigned char dat);//ģ��SPIʱ��
void LCD_WR_DATA8(unsigned char dat);//д��һ���ֽ�
void LCD_WR_DATA(unsigned short dat);//д�������ֽ�
void LCD_WR_REG(unsigned char dat);//д��һ��ָ��
void LCD_Address_Set(unsigned short x1,unsigned short y1,unsigned short x2,unsigned short y2);//�������꺯��
void LCD_Init(void);//LCD��ʼ��
#endif




