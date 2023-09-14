#include"LCD2.h"

void LCD_VidInit(void)
{
	//Directions
	DIO_VidSetPinDirection( LCD_RS_PORT , LCD_RS_PIN , DIO_OUTPUT );
	DIO_VidSetPinDirection( LCD_RW_PORT , LCD_RW_PIN , DIO_OUTPUT );
	DIO_VidSetPinDirection( LCD_E_PORT , LCD_E_PIN , DIO_OUTPUT );
	DIO_VidSetPortDirection( LCD_DATA_COMMAND_PORT , 0b11111111 );


	_delay_ms(35);

	LCD_VidSendCommand( 0b00111000 );

	_delay_us(45);

	LCD_VidSendCommand( 0b00001100 );

	_delay_us(45);

	LCD_VidSendCommand( 0b00000001 );

	_delay_ms(2);

	LCD_VidSendCommand( 0b00000110 );

}


void LCD_VidSendCommand( u8 Copy_U8Command )
{
	//RS = 0
	DIO_VidSetPinValue( LCD_RS_PORT , LCD_RS_PIN , DIO_LOW );

	//RW = 0
	DIO_VidSetPinValue( LCD_RW_PORT , LCD_RW_PIN , DIO_LOW );

	//Command
	DIO_VidSetPortValue( LCD_DATA_COMMAND_PORT , Copy_U8Command ) ;


	//E
	DIO_VidSetPinValue( LCD_E_PORT , LCD_E_PIN , DIO_HIGH );

	_delay_us(1);

	DIO_VidSetPinValue( LCD_E_PORT , LCD_E_PIN , DIO_LOW );

}


void LCD_VidSendChar( u8 Copy_U8Char )
{
	//RS =1
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




//Send String
void LCD_VidSendString( u8 *Copy_Pu8String )
{
	for( int i = 0 ; Copy_Pu8String[i] != '\0' ; i++ )
	{
		LCD_VidSendChar( Copy_Pu8String[i] );
	}
}

//Send Number
void LCD_VidSendNumber( u32 Copy_U32Number )  //e.g Copy_U32Number = 14325
{
	u32 Local_u32Counter=1 , Local_u32Digit=0;

	if (Copy_U32Number == 0)
	{
		LCD_VidSendChar('0');
	}
	else
	{
		while (Copy_U32Number/Local_u32Counter != 0) //14325 , 1432  ,143 ,14 ,1 , zero
		{
			Local_u32Counter *= 10;      //1 , 10 , 100  ,1000 ,10000 ,100 000
		}
		Local_u32Counter /=10;         //100 000 -->10 000 -->refer to number of digits?

		while (Local_u32Counter != 0)  //10 000
		{
			Local_u32Digit = Copy_U32Number/Local_u32Counter; //1

			LCD_VidSendChar(Local_u32Digit + '0'); //print 1

			Copy_U32Number = Copy_U32Number%Local_u32Counter; //4325

			Local_u32Counter /= 10; //1 000 and repeat to print all local digits
		}
	}
}


//Goto
void LCD_VidGoToLocation ( u8 Copy_U8RowNumber , u8 Copy_U8ColNumber ) //LCD_FIRST_LINE   0 //LCD_Second_LINE   1

{
	if( Copy_U8RowNumber == LCD_FIRST_LINE )
	{
		LCD_VidSendCommand( 0b10000000/*For Busy Flag*/ + Copy_U8ColNumber );
	}
	else if( Copy_U8RowNumber == LCD_Second_LINE )
	{
		LCD_VidSendCommand( 0b10000000/*For Busy Flag*/ + 0b01000000/*First address of line 2*/ + Copy_U8ColNumber); //?
	}
}







