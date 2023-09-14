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

void DIO_VidSetPortDirection(u8 Copy_U8Port , u8 Copy_U8Direction)
{
	if( Copy_U8Direction == DIO_INPUT )
		{
			switch (Copy_U8Port)
			{
				case DIO_PORTA:
					CLR_BYTE(DDRA);
					break;
				case DIO_PORTB:
					CLR_BYTE(DDRB);
					break;
				case DIO_PORTC:
					CLR_BYTE(DDRC);
					break;
				case DIO_PORTD:
					CLR_BYTE(DDRD);
					break;
				default:
					break;
			}
		}
		else if( Copy_U8Direction == DIO_OUTPUT )
		{
			switch (Copy_U8Port)
			{
				case DIO_PORTA:
					SET_BYTE(DDRA);
					break;
				case DIO_PORTB:
					SET_BYTE(DDRB);
					break;
				case DIO_PORTC:
					SET_BYTE(DDRC);
					break;
				case DIO_PORTD:
					SET_BYTE(DDRD);
					break;
				default:
					break;
			}
		}
}

void DIO_VidSetPortValue(u8 Copy_U8Port , u8 Copy_U8Value)
{
	if( Copy_U8Value == DIO_LOW )
		{
			switch (Copy_U8Port)
			{
				case DIO_PORTA:
					CLR_BYTE(PORTA);
					break;
				case DIO_PORTB:
					CLR_BYTE(PORTB);
					break;
				case DIO_PORTC:
					CLR_BYTE(PORTC);
					break;
				case DIO_PORTD:
					CLR_BYTE(PORTD);
					break;
				default:
					break;
			}
		}
		else if( Copy_U8Value == DIO_HIGH )
		{
			switch (Copy_U8Port)
			{
				case DIO_PORTA:
					SET_BYTE(PORTA);
					break;
				case DIO_PORTB:
					SET_BYTE(PORTB);
					break;
				case DIO_PORTC:
					SET_BYTE(PORTC);
					break;
				case DIO_PORTD:
					SET_BYTE(PORTD);
					break;
				default:
					break;
			}
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

