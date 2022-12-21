 #ifndef LED_H_
#define LED_H_

#include "../../MCAL/Dio_Driver/Dio.h"
/*Enum For Defing Color Modes*/
typedef enum Choose_LED_Color
{
	Green , Yellow , Red
} LED_COLOR ;


void LED_init (uint8_t LedPort ,uint8_t LedPin) ;
void LED_on(uint8_t LedPort ,uint8_t LedPin) ;
void LED_off(uint8_t LedPort ,uint8_t LedPin) ;
void LED_Toggle(uint8_t LedPort ,uint8_t LedPin);
void Yellow_Led_Blink (uint8_t LedPort , uint8_t LedPin ) ;


#endif /* LED_H_ */