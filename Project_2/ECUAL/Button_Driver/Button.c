#include "Button.h"
/*Setting Port and pin information of button as Input*/
void Button_init(uint8_t ButtonPort,uint8_t ButtonPin)
{
	/*Initializing Port and Pin on Atmega 32 Device*/
		Dio_init(ButtonPort,ButtonPin,IN);

}
/* Reading Port and pin information of button as High or Low*/
void Button_read(uint8_t ButtonPort,uint8_t ButtonPin,uint8_t *Value)
{
	
	Dio_read(ButtonPort,ButtonPin,Value);
}
