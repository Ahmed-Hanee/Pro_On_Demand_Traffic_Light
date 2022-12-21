	


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO_Driver/Dio.h"

void Button_init(uint8_t ButtonPort,uint8_t ButtonPin);

void Button_read(uint8_t ButtonPort,uint8_t ButtonPin,uint8_t *Value);

#endif /* BUTTON_H_ */