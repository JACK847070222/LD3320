/***************************************************************************************
*说明:用于STM32F10XXX串口UART2通讯,可以将printf scanf等重定向到串口
*环境:KEIL FOR ARM MDK4.54
*硬件:对应PA2-UART2TX PA3-UART2RX，使用USART2
*版本:V0.1
*作者:
*备注:对应的PA2/PA3以及USART2已由UART_Init函数自身初始化，无需在程序中完成
***************************************************************************************/
#ifndef __USART_H
#define __USART_H

#include "stm32f10x.h"
#include "stm32f10x_usart.h"
#include "stdio.h"

/*私有变量----------------------------------------------------------------------------*/
#define USED_COM_NUMBER USART1  	//设置当前使用的串口

/*函数声明----------------------------------------------------------------------------*/
void USART_Configuration(unsigned long UART_baud); //波特率，如115200
int fputc(int ch, FILE *f);    //fputc重定向
void USART_printf(USART_TypeDef* USARTx, uint8_t *Data,...);

#endif
