#include "Timer.h"
#define Number_Of_OverFlows 77  
unsigned int Over_Flow_Counter = 0;

void Timer_init(){
	TCCR0 = 0x00; 
	TCNT0 =0X00;                                           
}

void Timer0()
{
	
	TCCR0 |= (1<<2) ;
	while ( Over_Flow_Counter < Number_Of_OverFlows )
	{
		while ((TIFR & (1 << 0))  == 0) ;
		TIFR |=(1<<0) ;
		Over_Flow_Counter++;
	}
	Over_Flow_Counter = 0 ;
}

void Timer_Stop(void)
{
TCCR0 |= 0X00 ;
}

