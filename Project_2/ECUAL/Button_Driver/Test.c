// #include "button.h"
// #include "../../Application/Application.h"
// int main(void)
// {
// 	uint8_t Status;
// 	Button_init(PORT_D, PIN2);
// 	Dio_init(PORT_A,PIN2,OUT);
// 	while(1)
// 	{
// 		Button_read(PORT_D, PIN2, &Status);
// 		if(Status ==HIGH){
// 		LED_on(PORT_A,PIN2);
// 	}
// 	}
// }