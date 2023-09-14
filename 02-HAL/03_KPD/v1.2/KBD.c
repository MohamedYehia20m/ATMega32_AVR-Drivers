#include "DIO.h"
//#include "SEV_SEG.h"
#include"KBD.h"

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/delay.h>


u8 KBD_U8Arrangement [4][4] =
{
		{'7' , '8' , '9' , '/' } ,
		{'4' , '5' , '6' , '*' },
		{'1' , '2' , '3' , '-' },
		{'c' , '0' , '=' , '+' }
};

void KBD_VidInit(void)
{
	/*
	 * Col Pins --> Pin0 --> Pin3
	 * Row Pins --> Pin4 --> Pin7
	 * */
	//DIO_VidSetPortDirection( KBD_PORT , 0b00001111 );
	DDRB = 0b00001111;

	//DIO_VidSetPortValue( KBD_PORT , 0b11111111 );
	PORTB = 0b11111111;

}

u8 KBD_U8GetPressedKey(void)
{
	u8 Local_U8ColCounter ;
	u8 Local_U8RowCounter ;
	u8 Local_U8Pressed ;
	u8 Local_u8ReturnValue = 20 ;



	for( Local_U8ColCounter = 0 ; Local_U8ColCounter < 4 ; Local_U8ColCounter++ )
	{
		DIO_VidSetPinValue( KBD_PORT , Local_U8ColCounter , DIO_LOW );

		for( Local_U8RowCounter = 0 ; Local_U8RowCounter < 4 ; Local_U8RowCounter++)
		{
			Local_U8Pressed = DIO_U8GetPinValue( KBD_PORT , Local_U8RowCounter+4 );

			if( Local_U8Pressed == 0 ) //Pressed
			{
				//Return the value
				Local_u8ReturnValue = KBD_U8Arrangement[Local_U8RowCounter][Local_U8ColCounter];
				while( Local_U8Pressed == 0 )
				{
					Local_U8Pressed = DIO_U8GetPinValue( KBD_PORT , Local_U8RowCounter+4 );
				}

				_delay_ms(500);
			}
		}
		DIO_VidSetPinValue( KBD_PORT , Local_U8ColCounter , DIO_HIGH );
	}

	return Local_u8ReturnValue ;

}
