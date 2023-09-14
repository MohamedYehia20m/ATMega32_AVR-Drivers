#include "7SEG.h"

#include "BIT_MATH.h"

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
				CLR_BIT(PORTD,Copu_U8Pin);
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
				SET_BIT(PORTD,Copu_U8Pin);
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
			TOGGLE_BIT(PORTD,Copy_U8Pin);
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

	//0 --> 0b00111111
	//1 --> 0b00000110
	//2 --> 0b01011011
	//3 --> 0b01001111
	//4 --> 0b01100110
	//5 --> 0b01101101
	//6 --> 0b01111101
	//7 --> 0b00000111
	//8 --> 0b01111111
	//9 --> 0b01101111


void DIO_Vid7SegConfig(u8 Copy_U8Port , u8 Copy_U8Value)
{
	switch (Copy_U8Port)
	{
		case DIO_PORTA:  //A
			DIO_VidSetPortDirection(DIO_PORTA , DIO_OUTPUT);
			switch (Copy_U8Value)
			{
				case 0 :
					PORTA = 0b00111111;
					break;
				case 1 :
					PORTA = 0b00000110;
					break;
				case 2 :
					PORTA = 0b01011011;
					break;
				case 3 :
					PORTA = 0b01001111;
					break;
				case 4 :
					PORTA = 0b01100110;
					break;
				case 5 :
					PORTA = 0b01101101;
					break;
				case 6 :
					PORTA = 0b01111101;
					break;
				case 7 :
					PORTA = 0b00000111;
					break;
				case 8 :
					PORTA = 0b01111111;
					break;
				case 9 :
					PORTA = 0b01101111;
					break;
				default:
					break;
				}
				break;

			case DIO_PORTB:  //B
				DIO_VidSetPortDirection(DIO_PORTB , DIO_OUTPUT);
				switch (Copy_U8Value)
				{
					case  0 :
						PORTB = 0b00111111;
						break;
					case  1 :
						PORTB = 0b00000110;
						break;
					case  2 :
						PORTB = 0b01011011;
						break;
					case  3:
						PORTB = 0b01001111;
						break;
					case  4:
						PORTB = 0b01100110;
						break;
					case  5:
						PORTB = 0b01101101;
						break;
					case  6:
						PORTB = 0b01111101;
						break;
					case  7:
						PORTB = 0b00000111;
						break;
					case  8:
						PORTB = 0b01111111;
						break;
					case  9:
						PORTB = 0b01101111;
						break;
					default:
						break;
				}
				break;

				case DIO_PORTC: //C
					DIO_VidSetPortDirection(DIO_PORTC , DIO_OUTPUT);
					switch (Copy_U8Value)
					{
						case  0:
							PORTC = 0b00111111;
							break;
						case  1:
							PORTC = 0b00000110;
							break;
						case  2:
							PORTC = 0b01011011;
							break;
						case  3:
							PORTC = 0b01001111;
							break;
						case  4:
							PORTC = 0b01100110;
							break;
						case  5:
							PORTC = 0b01101101;
							break;
						case  6:
							PORTC = 0b01111101;
							break;
						case  7:
							PORTC = 0b00000111;
							break;
						case  8:
							PORTC = 0b01111111;
							break;
						case  9:
							PORTC = 0b01101111;
							break;
						default:
							break;
					 }
					break;

					case DIO_PORTD: //D
						DIO_VidSetPortDirection(DIO_PORTD , DIO_OUTPUT);
						switch (Copy_U8Value)
						{
							case  0:
								PORTD = 0b00111111;
								break;
							case  1:
								PORTD = 0b00000110;
								break;
							case  2:
								PORTD = 0b01011011;
								break;
							case  3:
								PORTD = 0b01001111;
								break;
							case  4:
								PORTD = 0b01100110;
								break;
							case  5:
								PORTD = 0b01101101;
								break;
							case  6:
								PORTD = 0b01111101;
								break;
							case  7:
								PORTD = 0b00000111;
								break;
							case  8:
								PORTD = 0b01111111;
								break;
							case  9:
								PORTD = 0b01101111;;
								break;
							default:
								break;
						}
						break;
					default:
						break;
		}
}



