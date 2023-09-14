#include "DIO.h"

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

