#include"DIO.h"
#include"KPD.h"

#define F_CPU 8000000UL
#include"avr/delay.h"


u8 KPD_U8Arrangement [4][4] =
{
		{'1' , '2' , '3' , '+' } ,
		{'4' , '5' , '6' , '-' } ,
		{'7' , '8' , '9' , '*' } ,
		{'=' , '0' , '%' , '/' }
};

u8 KPD_U8GetPressedKey(void)
{
	u8 Local_U8ColCounter ;
	u8 Local_U8RowCounter ;
	u8 Local_U8Pressed ;
	u8 Local_u8ReturnValue = 20 ;



	for( Local_U8ColCounter = 0 ; Local_U8ColCounter < 4 ; Local_U8ColCounter++ )
	{
		DIO_VidSetPinValue( KPD_PORT , Local_U8ColCounter , DIO_LOW );

		for( Local_U8RowCounter = 0 ; Local_U8RowCounter < 4 ; Local_U8RowCounter++)
		{
			Local_U8Pressed = DIO_U8GetPinValue( KPD_PORT , Local_U8RowCounter+4 );

			if( Local_U8Pressed == 0 ) //Pressed
			{
				//Return the value
				Local_u8ReturnValue = KPD_U8Arrangement[Local_U8RowCounter][Local_U8ColCounter];
				while( Local_U8Pressed == 0 )
				{
					Local_U8Pressed = DIO_U8GetPinValue( KPD_PORT , Local_U8RowCounter+4 );
				}

				_delay_ms(10);
			}
		}
		DIO_VidSetPinValue( KPD_PORT , Local_U8ColCounter , DIO_HIGH );
	}

	return Local_u8ReturnValue ;

}


void KPD_VidInit(void)
{
	/*
	 * Col Pins --> Pin0 --> Pin3
	 * Row Pins --> Pin4 --> Pin7
	 * */
	DIO_VidSetPortDirection( KPD_PORT , 0b00001111 );

	DIO_VidSetPortValue( KPD_PORT , 0b11111111 );


}



