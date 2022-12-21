
#ifndef APPLICATION_H_
#define APPLICATION_H_

/*Including All Drivers Modules of Lower Layers*/

#include "../ECUAL/LED_Driver/LED.h"
#include "../ECUAL/Button_Driver/Button.h"
#include "../MCAL/Timer_Driver/Timer.h"
#include "../MCAL/Interrupts/Interrupts.h"
#include "../Utilitis/Registers.h"
/*Function Prototypes*/
void APP_init(void);
void APP_start(void);

/*Enum Defining Modes In Our Application*/

typedef enum MODES
{
	Car_Mode , PEDESTRIAN_MODE
} LED_MODES ;

#endif /* APPLICATION_H_ */