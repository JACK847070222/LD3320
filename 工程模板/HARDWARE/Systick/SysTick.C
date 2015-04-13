#include "SysTick.h"

static u32 TimingDelay;
/*
总定时T=ticks*(1/f)
@f为嘀嗒定时器所使用的驱动时钟源（AHB或AHB/8）这里去AHB（72M）
@ticks是计数寄存器的装载值
定时1us，ticks=72
定时10us,ticks=720
定时1ms,ticks=72000
*/

void Systick_Init(void)
{
	if(SysTick_Config(720))//10us中断
	{
		while(1);
	}	
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;//关闭嘀嗒定时器
}

void TimingDelay_Decrement(void)    
{    
	if (TimingDelay != 0x00)    
	{     
		TimingDelay--;    
	}    
}   

void Delay_us(__IO u32 nTime)    
{     
	TimingDelay = nTime;        
	
	// 使能滴答定时器      
	SysTick->CTRL |=  SysTick_CTRL_ENABLE_Msk;    
	
	while(TimingDelay != 0);    
	
}  

