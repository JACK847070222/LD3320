#include "stm32f10x.h"


void Systick_Init(void);
extern void TimingDelay_Decrement(void);
void Delay_us(__IO u32 nTime);
