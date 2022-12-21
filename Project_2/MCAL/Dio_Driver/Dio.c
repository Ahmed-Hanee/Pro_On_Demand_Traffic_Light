#include "Dio.h" 
void Dio_init(uint8_t PortNumber ,uint8_t PinNumber ,uint8_t Direction) 
{
	switch(PortNumber)
	{
		case PORT_A: 
		if(Direction == IN)
		{
		DDRA &= ~(1<<PinNumber) ;
		}
		else if(Direction == OUT)
		{
			DDRA |=(1<<PinNumber) ;
		}
		      break ;
	/*******************************************/
		case PORT_B:
		if(Direction == IN)
		{
			DDRB &= ~(1<<PinNumber) ;
		}
		else if(Direction == OUT)
		{
			DDRB |=(1<<PinNumber) ;
		}	
	     	break ; 
		/*****************************************************/
		/*****************************************************/
		case PORT_D:
		if(Direction == IN)
		{
			DDRD &= ~(1<<PinNumber) ;
		}
		else if(Direction == OUT)
		{
			DDRD |=(1<<PinNumber) ;
		}		 
		break;		 
	}
}
void Dio_read(uint8_t PortNumber ,uint8_t PinNumber ,uint8_t *Value) 
{
	{
	switch(PortNumber){
		case PORT_A:
			*Value = ((PINA&(1<<PinNumber))>>PinNumber);
		break;
		case PORT_B:
			*Value = ((PINB&(1<<PinNumber))>>PinNumber);
		break;
		case PORT_D:
			*Value = ((PIND&(1<<PinNumber))>>PinNumber);
		break;
	}
}
}
void Dio_write(uint8_t PortNumber ,uint8_t PinNumber , uint8_t Value) 
{
	
	switch(PortNumber)
	{
		case PORT_A:
		if(Value == LOW)
		{
			PORTA &= ~(1<<PinNumber) ;
		}
		else if(Value == HIGH)
		{
			PORTA |=(1<<PinNumber) ;
		}
		break ;
		/*******************************************/
		case PORT_B:
		if(Value == LOW)
		{
			PORTB &= ~(1<<PinNumber) ;
		}
		else if(Value == HIGH)
		{
			PORTB |=(1<<PinNumber) ;
		}
		break ;
		/*****************************************************/
		/*****************************************************/
		case PORT_D:
		if(Value == LOW)
		{
			PORTD &= ~(1<<PinNumber) ;
		}
		else if(Value == HIGH)
		{
			PORTD |=(1<<PinNumber) ;
		}
		break;
		default:
		
		break;
	}
}
void Dio_Toggle(uint8_t PortNumber ,uint8_t PinNumber) 
{
	{
		switch(PortNumber){
			case PORT_A:
			PORTA ^= (1<<PinNumber);
			break;
			case PORT_B:
			PORTB ^= (1<<PinNumber);
			break;
			case PORT_D:
			PORTD ^= (1<<PinNumber);
			break;
		}
	}
}