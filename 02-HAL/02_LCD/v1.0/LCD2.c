#include "LCD2.h"


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


void LCD_VidSendCommand(u8 Copy_U8Command) //to be revised
{
	DIO_VidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_LOW); //rs = 0
	DIO_VidSetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_LOW);  //rw = 0
	DIO_VidSetPortValue(LCD_DATA_COMMAND_PORT , Copy_U8Command);
	DIO_VidSetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_HIGH); //E
	_delay_us(1);
	DIO_VidSetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_LOW);

}

void LCD_VidSendChar(u8 Copy_U8Char)
{
	DIO_VidSetPinValue( LCD_RS_PORT , LCD_RS_PIN , DIO_HIGH );

		//RW = 0
		DIO_VidSetPinValue( LCD_RW_PORT , LCD_RW_PIN , DIO_LOW );

		//Command
		DIO_VidSetPortValue( LCD_DATA_COMMAND_PORT , Copy_U8Char ) ;


		//E
		DIO_VidSetPinValue( LCD_E_PORT , LCD_E_PIN , DIO_HIGH );

		_delay_us(1);

		DIO_VidSetPinValue( LCD_E_PORT , LCD_E_PIN , DIO_LOW );

}

void LCD_VidSendString(u8 *Copy_U8String) //task //use sendchar
{
	u8 index ;
	for(index = 0 ; Copy_U8String[index] != '\0' ; index++)
	{
		LCD_VidSendChar( Copy_U8String[index] );
	}

}

void LCD_VidSendNumber(u32 Copy_U32Number) //task
{
	DIO_VidSetPinValue( LCD_RS_PORT , LCD_RS_PIN , DIO_HIGH );

		//RW = 0
		DIO_VidSetPinValue( LCD_RW_PORT , LCD_RW_PIN , DIO_LOW );

		u32 u8ASCIINumber = Copy_U32Number + 48; //convert to ascii

		//Command
		DIO_VidSetPortValue( LCD_DATA_COMMAND_PORT , u8ASCIINumber ) ;


		//E
		DIO_VidSetPinValue( LCD_E_PORT , LCD_E_PIN , DIO_HIGH );

		_delay_us(1);

		DIO_VidSetPinValue( LCD_E_PORT , LCD_E_PIN , DIO_LOW );

}

void LCD_VidGoToLocation(u8 Copy_U8RowNumber , u8 Copy_U8colNNumber)//task //need revision
{
	u8 DDRAM_address;
	if(Copy_U8RowNumber = 1 ) //first row 0:15 --> 0:15
		DDRAM_address = Copy_U8colNNumber;
	else //seconnd row 16:31 --> 40:55
		DDRAM_address = Copy_U8colNNumber + 40;

		u8 command = 0b10000000 | DDRAM_address;
	LCD_VidSendCommand(command); //set DDRAM address  0b 1 AC6 AC5 AC4 AC3 AC2 AC1 AC0
}

void LCD_Vidinit(void)
{
	DIO_VidSetPinDirection(LCD_RS_PORT,LCD_RS_PIN,DIO_OUTPUT); //rs
	DIO_VidSetPinDirection(LCD_RW_PORT,LCD_RW_PIN,DIO_OUTPUT); //rw
	DIO_VidSetPinDirection(LCD_E_PORT,LCD_E_PIN,DIO_OUTPUT); //E
	DIO_VidSetPortDirection(LCD_DATA_COMMAND_PORT , 0b11111111);
	_delay_ms(35);

		LCD_VidSendCommand( 0b00111000 );

		_delay_us(45);

		LCD_VidSendCommand( 0b00001100 );

		_delay_us(45);

		LCD_VidSendCommand( 0b00000001 );

		_delay_ms(2);

		LCD_VidSendCommand( 0b00000110 );
}



