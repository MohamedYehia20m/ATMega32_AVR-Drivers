#include"KPD.h"


u8 KBD_U8Arrangement [4][4] =
	{
			{'7' , '8' , '9' , '/' } ,
			{'4' , '5' , '6' , '*' },
			{'1' ,'2' , '3' , '-' },
			{'%' , '0' , '=' , '+'}
	};






void KEYPAD_VidInit(void){

DIO_VidSetPortDirection(KEYPAD_PORT, 0b00001111);
DIO_VidSetPortValue(KEYPAD_PORT,0b11111111);

}

u8 KEYPAD_U8GetPressedKey(void){


u8 Local_U8ColCounter;
u8 Local_U8RowCounter;
u8 Local_U8Pressed;
u8 Local_U8ReturnValue=20;

for (Local_U8ColCounter=0;Local_U8ColCounter<4;Local_U8ColCounter++){

DIO_VidSetPinValue(KEYPAD_PORT, Local_U8ColCounter,DIO_LOW);

		for( Local_U8RowCounter = 0 ; Local_U8RowCounter < 4 ; Local_U8RowCounter++)
				{
					Local_U8Pressed =  DIO_U8GetPinValue( KEYPAD_PORT , Local_U8RowCounter+4 );

					if( Local_U8Pressed == 0 ) //Pressed
					{
						//Return the value
						Local_U8ReturnValue = KBD_U8Arrangement[Local_U8RowCounter][Local_U8ColCounter];
						while( Local_U8Pressed == 0 ){

						Local_U8Pressed= DIO_U8GetPinValue(KEYPAD_PORT, Local_U8RowCounter+4);}
						_delay_ms(10);

					}
				}
				DIO_VidSetPinValue( KEYPAD_PORT, Local_U8ColCounter , DIO_HIGH );
			}

			return Local_U8ReturnValue;

		}
