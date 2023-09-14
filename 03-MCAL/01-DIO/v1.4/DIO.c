#include "DIO.h"
#include <avr/io.h>

void DIO_VidSetPinDirection(u8 Copy_U8Port , u8 Copu_U8Pin , u8 copy_U8Direction)
{
	if( copy_U8Direction == DIO_INPUT )
	{
		switch (Copy_U8Port)
		{
			case DIO_PORTA:
				CLR_BIT(DDRA,Copu_U8Pin);
				break;
			case DIO_PORTB:
				CLR_BIT(DDRB,Copu_U8Pin);
				break;
			case DIO_PORTC:
				CLR_BIT(DDRC,Copu_U8Pin);
				break;
			case DIO_PORTD:
				CLR_BIT(DDRD,Copu_U8Pin);
				break;
			default:
				break;
		}
	}
	else if( copy_U8Direction == DIO_OUTPUT )
	{
		switch (Copy_U8Port)
		{
			case DIO_PORTA:
				SET_BIT(DDRA,Copu_U8Pin);
				break;
			case DIO_PORTB:
				SET_BIT(DDRB,Copu_U8Pin);
				break;
			case DIO_PORTC:
				SET_BIT(DDRC,Copu_U8Pin);
				break;
			case DIO_PORTD:
				SET_BIT(DDRD,Copu_U8Pin);
				break;
			default:
				break;
		}
	}
}

void DIO_VidSetPinValue(u8 Copy_U8Port , u8 Copu_U8Pin , u8 copy_U8Value)
{
	if( copy_U8Value == DIO_LOW )
	{
		switch (Copy_U8Port)
		{
			case DIO_PORTA:
				CLR_BIT(PORTA,Copu_U8Pin);
				break;
			case DIO_PORTB:
				CLR_BIT(PORTB,Copu_U8Pin);
				break;
			case DIO_PORTC:
				CLR_BIT(PORTC,Copu_U8Pin);
				break;
			case DIO_PORTD:
				CLR_BIT(PORTD,Copu_U8Pin);
				break;
			default:
				break;
		}
	}
	else if( copy_U8Value == DIO_HIGH )
	{
		switch (Copy_U8Port)
		{
			case DIO_PORTA:
				SET_BIT(PORTA,Copu_U8Pin);
				break;
			case DIO_PORTB:
				SET_BIT(PORTB,Copu_U8Pin);
				break;
			case DIO_PORTC:
				SET_BIT(PORTC,Copu_U8Pin);
				break;
			case DIO_PORTD:
				SET_BIT(PORTD,Copu_U8Pin);
				break;
			default:
				break;
		}
	}
}

void DIO_VidSetPortDirection(u8 Copy_U8Port , u8 Copy_U8Direction)
{	switch (Copy_U8Port)
	{
		case DIO_PORTA:
			DDRA = Copy_U8Direction;
			break;
		case DIO_PORTB:
			DDRB = Copy_U8Direction;
			break;
		case DIO_PORTC:
			DDRC = Copy_U8Direction;
			break;
		case DIO_PORTD:
			DDRD = Copy_U8Direction;
			break;
		default:
			break;
	}
}

void DIO_VidSetPortValue(u8 Copy_U8Port , u8 Copy_U8Value)
{

			switch (Copy_U8Port)
			{
				case DIO_PORTA:
					PORTA = Copy_U8Value;
					break;
				case DIO_PORTB:
					PORTB = Copy_U8Value;
					break;
				case DIO_PORTC:
					PORTC = Copy_U8Value;
					break;
				case DIO_PORTD:
					PORTD = Copy_U8Value;
					break;
				default:
					break;
			}
}

void DIO_VidTogglePinValue(u8 Copy_U8PORT , u8 Copy_U8Pin)
{
	switch (Copy_U8PORT)
	{
		case DIO_PORTA:
			TOGGLE_BIT(PORTA,Copy_U8Pin);
			break;
		case DIO_PORTB:
			TOGGLE_BIT(PORTB,Copy_U8Pin);
			break;
		case DIO_PORTC:
			TOGGLE_BIT(PORTC,Copy_U8Pin);
			break;
		case DIO_PORTD:
			TOGGLE_BIT(PORTD,Copy_U8Pin);
			break;
		default:
			break;
	}

}


u8 DIO_U8GetPinValue(u8 Copy_U8Port , u8 Copy_U8Pin )
{
	switch(Copy_U8Port)
	{
		case DIO_PORTA:
			return GET_BIT(PINA,Copy_U8Pin);
			break;
		case DIO_PORTB:
			return GET_BIT(PINB,Copy_U8Pin);
			break;
		case DIO_PORTC:
			return GET_BIT(PINC,Copy_U8Pin);
			break;
		case DIO_PORTD:
			return GET_BIT(PIND,Copy_U8Pin);
			break;
		default:
			break;
	}
}

