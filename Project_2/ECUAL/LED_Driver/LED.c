#include "led.h"

/*Initializing Port and Pin on Atmega 32 Device For Leds*/

void LED_init(uint8_t LedPort,uint8_t LedPin){
	Dio_init(LedPort,LedPin,OUT);
}
/*Write High on For Leds */

void LED_on(uint8_t LedPort,uint8_t LedPin){
	Dio_write(LedPort,LedPin,HIGH);
}
/*Write low on For Leds */

void LED_off(uint8_t LedPort,uint8_t LedPin){
	Dio_write(LedPort,LedPin,LOW);
}
/*Toggle Led Between 0 And 1*/
void LED_toggle(uint8_t LedPort,uint8_t LedPin){
	Dio_Toggle(LedPort,LedPin);
}
/*Toggle led for specific timer*/
void Yellow_Led_Blink (uint8_t LedPort , uint8_t LedPin ) {

TCCR0 |= (1<<2);
unsigned int OverFlowsCounter = 0 ;
	while ( OverFlowsCounter < 77 ) 
	{
		while ( ( TIFR & (1 << 0) ) == 0 ) ;	
		
		if (OverFlowsCounter % 6 == 0 ) {
			LED_toggle(LedPort,LedPin);
		}
	   TIFR |= (1<<0); 
		OverFlowsCounter++;
	}
	LED_off(LedPort,LedPin) ;
	 OverFlowsCounter = 0 ;
}
/*Toggle two leds at the same time*/

void Two_led_Toogle (uint8_t LedPort , uint8_t LedPin , uint8_t Led_2_Port , uint8_t Led_2_Pin ) {
		
	TCCR0 |=(1<<2) ; 
		unsigned int OverFlowsCounter = 0 ;
	while ( OverFlowsCounter < 77 ) 
	{
		while ( ( TIFR & (1 << 0) ) == 0 ) ;		
		if (OverFlowsCounter % 6 == 0 ) {
			LED_toggle(LedPort,LedPin);
			LED_toggle(Led_2_Port,Led_2_Pin);
		}
		
TIFR |= (1<<0) ; 
		OverFlowsCounter++;
	}
	LED_off(LedPort,LedPin) ;
	OverFlowsCounter = 0 ;

}