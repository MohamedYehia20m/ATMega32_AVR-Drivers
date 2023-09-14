#include "SWP2.h"
#include "DIO.h"

DC_VidInit()
{
	DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN1,DIO_OUTPUT);
	DIO_VidSetPinValue(DIO_PORTA,DIO_PIN0,DIO_HIGH);
	DIO_VidSetPinValue(DIO_PORTA,DIO_PIN1,DIO_LOW);

	DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN2,DIO_INPUT);
	DIO_VidSetPinValue(DIO_PORTA,DIO_PIN2,DIO_HIGH);




}

DC_VidChangeDirection()
{
	while(1)
	{
		if(DIO_U8GetPinValue(DIO_PORTA,DIO_PIN2) == 0)
		{
			DIO_VidSetPinValue(DIO_PORTA,DIO_PIN0,DIO_LOW);
			DIO_VidSetPinValue(DIO_PORTA,DIO_PIN1,DIO_HIGH);
		}
		else
		{
			DIO_VidSetPinValue(DIO_PORTA,DIO_PIN0,DIO_HIGH);
			DIO_VidSetPinValue(DIO_PORTA,DIO_PIN1,DIO_LOW);
		}
	}
}
