
#include "../../Utilitis/Registers.h"
#ifndef DIO_H_
#define DIO_H_

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_D 'D'

#define IN 0
#define OUT 1

#define LOW 0
#define HIGH 1


void Dio_init(uint8_t PortNumber ,uint8_t PinNumber ,uint8_t Direction) ;
void Dio_read(uint8_t PortNumber ,uint8_t PinNumber ,uint8_t *Value) ;
void Dio_write(uint8_t PortNumber ,uint8_t PinNumber ,uint8_t Value) ;
void Dio_Toggle(uint8_t PortNumber ,uint8_t PinNumber) ;



#endif /* DIO_H_ */