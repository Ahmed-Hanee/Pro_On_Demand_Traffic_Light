

#ifndef INCFILE1_H_
#define INCFILE1_H_

#include "../../Utilitis/Registers.h" 

/*Defining External Interrupt*/
#define EXT_INT_0 __vector_1


/*Defining Macros*/ 
/*Set Global Interrupt */
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

#define Choose_External_Interrupt() MCUCR |= (1 << 0) | (1 << 1);

#define Enable_External_Interrupt() GICR |= (1 << 6);
/*Definign ISR*/
#define ISR(INT_VECT) \
void INT_VECT(void) __attribute__ ((signal,used)); \
void INT_VECT(void)


#endif /* INCFILE1_H_ */