#include "STD_TYPES.H"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"

void SetPinDirection(u8 Port, u8 Pin, u8 Dir){
	switch (Port)
	{
		case 'A':
			if(Dir==0)
			{
				DDRA&=~(1<<Pin);
			}
			else
			{
				DDRA|=(1<<Pin);
			}
			break;

		case 'B':
			if(Dir==0)
			{
				DDRB&=~(1<<Pin);
			}
			else{
				DDRB|=(1<<Pin);
			}
			break;


		case 'C':
			if(Dir==0)
			{
				DDRC&=~(1<<Pin);
			}
			else
			{
				DDRC|=(1<<Pin);
			}
			break;


		case 'D':
			if(Dir==0)
			{
				DDRD&=~(1<<Pin);
			}
			else
			{
				DDRD|=(1<<Pin);
			}
			break;


	}
}

void SetPinValue(u8 Port, u8 Pin, u8 value){

	switch (Port)
	{
		case 'A':
			if(value==0)
			{
				PORTA&=~(1<<Pin);
			}
			else
			{
				PORTA|=(1<<Pin);
			}
			break;

		case 'B':
			if(value==0)
			{
				PORTB&=~(1<<Pin);
			}
			else
			{
				PORTB|=(1<<Pin);
			}
			break;

		case 'C':
			if(value==0)
			{
				PORTC&=~(1<<Pin);
			}
			else
			{
				PORTC|=(1<<Pin);
			}
			break;
			

		case 'D':
			if(value==0)
			{
				PORTD&=~(1<<Pin);
			}
			else
			{
				PORTD|=(1<<Pin);
			}
			break;

	}
}
