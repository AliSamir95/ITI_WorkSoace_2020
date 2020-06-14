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
				CLEAR_BIT(DDRA,Pin);
			}
			else{
				SET_BIT(DDRA,Pin);
			}
			break;

		case 'B':
			if(Dir==0)
			{
				CLEAR_BIT(DDRB,Pin);
			}
			else
			{
				SET_BIT(DDRB,Pin);
			}
			break;

		case 'C':
			if(Dir==0)
			{
				CLEAR_BIT(DDRC,Pin);
			}
			else
			{
				SET_BIT(DDRC,Pin);
			}
			break;

		case 'D':
			if(Dir==0)
			{
				CLEAR_BIT(DDRD,Pin);
			}
			else{
				SET_BIT(DDRD,Pin);
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
				CLEAR_BIT(PORTA,Pin);
			}
			else{
				SET_BIT(PORTA,Pin);
			}
			break;

		case 'B':
			if(value==0)
			{
				CLEAR_BIT(PORTB,Pin);
			}
			else
			{
				SET_BIT(PORTB,Pin);
			}
			break;

		case 'C':
			if(value==0)
			{
				CLEAR_BIT(PORTC,Pin);
			}
			else
			{
				SET_BIT(PORTA,Pin);
			}
			break;

		case 'D':
			if(value==0)
			{
				CLEAR_BIT(PORTD,Pin);
			}
			else{
				SET_BIT(PORTD,Pin);
			}
			break;

	}
}

u8 GetPinValue(u8 Port, u8 Pin){
	u8 Result;
	switch (Port)
	{
		case 'A': Result= GET_BIT(PINA,Pin);

			break;

		case 'B':Result= GET_BIT(PINB,Pin);
			break;

		case 'C': Result= GET_BIT(PINC,Pin);

			break;

		case 'D': Result= GET_BIT(PIND,Pin);

			break;

	}
	return Result;
}
