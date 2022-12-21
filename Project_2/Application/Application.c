#include "Application.h"
#include <util/delay.h>

uint8_t Pressed_Button ;
uint8_t Car_Last_Color ;
LED_MODES Mode=Car_Mode ;
/*Initializations for Ports,Pins,Interrupts Which Will Be Used */
void APP_init(void)
{
	LED_init(PORT_A,PIN0);
	LED_init(PORT_A,PIN1);
	LED_init(PORT_A,PIN2);
	LED_init(PORT_B,PIN0);
	LED_init(PORT_B,PIN1);
	LED_init(PORT_B,PIN2);
	Button_init(PORT_D,PIN2);
	Timer_init();
	sei() ;
	Choose_External_Interrupt() ;
	Enable_External_Interrupt();
}
/*Main Function Which Start The Application */

void Start(){
	switch(Mode){
		case Car_Mode :/*Car-Mode Pins*/
		/*Manipulating With Car Led As Normal Mode Works*/
		/*Car Green Led is on */
		LED_on(PORT_A,PIN0);/*Turning On Car Green Led */
		LED_off(PORT_A,PIN1);/*Turning On Car yellow Led */
		LED_off(PORT_A,PIN2);
		LED_off(PORT_B,PIN0);
		LED_off(PORT_B,PIN1);
		LED_off(PORT_B,PIN2);
		Timer0();
		LED_off(PORT_A,PIN0);/*Turning off Car Green Led */
		Car_Last_Color = Green ;/*Setting Car Last Color to Green */
		Yellow_Led_Blink(PORT_A,PIN1) ;/*Turning On Car yellow Led */
		Car_Last_Color = Yellow ;/*Setting Car Last Color to Yellow */
		LED_on(PORT_A,PIN2);
		Timer0();
		LED_off(PORT_A,PIN2);
		Car_Last_Color = Red ;/*Setting Car Last Color to Red */
		Yellow_Led_Blink(PORT_A,PIN1) ;/*Blinking CAR Yellow LED*/
		break ;
		case PEDESTRIAN_MODE :
		/*Button Is Pressed And System automatically Will change to pedestrian mode and decide which is the next led color to be on or off Upon Car last color*/
		switch(Car_Last_Color)
		{
			/*case red pedestrian green led is on for 5sec and car led will be on for 5 sec*/
			case Red :
			LED_on(PORT_B , PIN0) ;
			Timer0() ;
			LED_off(PORT_A, PIN2) ;
			LED_off(PORT_B , PIN0) ;
			break;
			/*case Yellow pedestrian red led is on for 5sec and Both yellow leds will blink then car red led is on and pedestrian green led is on */
			case Yellow :
			LED_off( PORT_A , PIN0) ;/*Turning On Car Green Led */

			LED_on (PORT_B , PIN2) ;
			Two_led_Toogle(PORT_A, PIN1 , PORT_B , PIN1) ;/*Turning On both yellow Led */

			LED_off (PORT_A , PIN1 ) ;/*Turning On Car yellow Led */

			LED_off (PORT_B , PIN1) ;
			LED_off(PORT_B , PIN2) ;
			LED_on(PORT_B , PIN0) ;
			LED_on(PORT_A, PIN2) ;
			Timer0() ;
			break;
			/*case Green Car Green Led is set to off and Both yellow led will blink then car red led is on and pedestrian's  green led also*/
			case Green :
			LED_off( PORT_A , PIN0) ;/*Turning On Car Green Led */

			LED_on (PORT_B , PIN2) ;
			Two_led_Toogle(PORT_A, PIN1 , PORT_B , PIN1) ;
			LED_off (PORT_A , PIN1 ) ;/*Turning On Car yellow Led */

			LED_off (PORT_B , PIN1) ;
			LED_off(PORT_B , PIN2) ;
			LED_on(PORT_B , PIN0) ;
			LED_on(PORT_A, PIN2) ;
			Timer0() ;
			break;
		}

		LED_off (PORT_A , PIN2 )  ;
		LED_off(PORT_B , PIN0) ;
		Two_led_Toogle (PORT_A, PIN1 , PORT_B , PIN1) ;
		LED_off (PORT_A , PIN1 ) ;/*Turning On Car yellow Led */

		LED_off (PORT_B , PIN1) ;
		LED_off(PORT_B,PIN0) ;
		LED_on(PORT_B , PIN2) ;
		LED_on(PORT_A, PIN0) ;/*Turning On Car Green Led */

		if (Car_Last_Color == Yellow) {
			Timer0() ;
			LED_off(PORT_A,PIN0) ;
			break ;
		}
		Mode=Car_Mode;

	}
}

/*Vector function Which Decide What To Do When The Button Is Pressed */

ISR (EXT_INT_0) {
	/*Delaying Button 300 sc*/
     _delay_ms(100);
	/*Checking State of Button*/
	Button_read(PORT_D, PIN2,&Pressed_Button);
	if(Pressed_Button == HIGH ) {
		Mode=PEDESTRIAN_MODE; /*switch to PEDESTRIAN_MODE*/
		Start() ;
	}
}