#include "../../Application/Application.h"
int main(void)
{
	while (1)
	{
		Dio_init(PORT_A, PIN0, OUT);/*RUN*/
		Dio_init(PORT_A, PIN1, IN);/*NO*/
		Dio_init(PORT_A, PIN2, OUT);/*RUN*/
		Dio_init(PORT_B, PIN2, IN);/*RUN*/

		Two_led_Toogle(PORT_A,PIN1,PORT_A,PIN0);
		Two_led_Toogle(PORT_A,PIN2,PORT_B,PIN2);


		uint8_t Status = 0;
		Dio_read(PORT_A, PIN1, &Status);
		if(Status)
		{
			Dio_write(PORT_A, PIN2, LOW);
		}
	}



	}