
#ifndef REGISTER_H_
#define REGISTER_H_


typedef unsigned char uint8_t ;
/***********************Port A Group **********************************/
#define PORTA *((volatile uint8_t*)0X3B) //pointer to character
#define DDRA *((volatile uint8_t*)0X3A) //pointer to character
#define PINA *((volatile uint8_t*)0X39) //pointer to character
/***********************Port B Group **********************************/
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB  *((volatile uint8_t*)0x37)
#define PINB  *((volatile uint8_t*)0x36)
/***********************Port C Group **********************************/
// PORTC Registers
#define PORTC *((volatile uint8_t*)0x35)
#define DDRC  *((volatile uint8_t*)0x34)
#define PINC  *((volatile uint8_t*)0x33)
/***********************Port D Group **********************************/
// PORTD Registers
#define PORTD *((volatile uint8_t*)0x32)
#define DDRD  *((volatile uint8_t*)0x31)
#define PIND  *((volatile uint8_t*)0x30)
/***********************Timers-Group **********************************/
#define TCCR0 *((volatile uint8_t*)0x53)
#define TCNT0  *((volatile uint8_t*)0x52)
#define TIFR   *((volatile uint8_t*)0x58)
#define TIMSK (*(volatile uint8_t*)(0x59))
/***********************Interrupts-Group **********************************/
#define SREG (*(volatile uint8_t*)(0x5F))
#define GICR (*(volatile uint8_t*)(0x5B))
#define MCUCR (*(volatile uint8_t*)(0x55))
/******************************************************************************/

#define PIN0 0
#define PIN1 1
#define PIN2 2



#endif /* REGISTER_H_ */