#include "stm32f10x.h"
#include "SysTick.h"
#include "Usart.h"
#include "spi.h"
#include "led.h"
#include "key.h"
#include "LD3320.h"

void NVIC_Configuration(void) 
{ 

  NVIC_InitTypeDef NVIC_InitStructure;

  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0); /*中断优先级*/

  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;   /*3.4的库不是使用USART1_IRQChannel，看stm32f10x.h吧*/

  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; 

  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 

  NVIC_Init(&NVIC_InitStructure); 

}

int main(void)
{	
	/*  滴答定时器初始化  */
	Systick_Init();
	/*  中断配置  */
	NVIC_Configuration();
	/*  SPI初始化 */
	SPI1_Init();
	/*  串口配置  */
	USART_Configuration(115200);	
	//LED_Init();
	//KEY_Init();
//	printf("\r\n This is a USART1_printf demo \r\n");
//	printf("\r\n ("__DATE__ " - " __TIME__ ") \r\n");
//	printf("\r\n %s:%d",__FILE__,__LINE__);	
	
	LD3320_main();
	while(1)
	{
		LED0 = ~LED0;
		if(KEY0==0)
		{
			Delay_us(10000);//100mS去抖动 
			if(KEY0==0)
			{
				
			}
		}
		Delay_us(50000);//100mS去抖动 
	}
}

