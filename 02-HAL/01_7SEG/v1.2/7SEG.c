#include "7SEG.h"
#include "DIO.h"
#include "BIT_MATH.h"


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


void SEV_SEG_VidSetNumber(u8 Copy_U8Port, u8 Copy_U8Value)
{
	switch (Copy_U8Value)
			{
				case 0 :
					DIO_VidSetPortValue(Copy_U8Port , SEV_SEG_ZERO);
					break;
				case 1 :
					DIO_VidSetPortValue(Copy_U8Port , SEV_SEG_ONE);
					break;
				case 2 :
					DIO_VidSetPortValue(Copy_U8Port , SEV_SEG_TWO);
					break;
				case 3 :
					DIO_VidSetPortValue(Copy_U8Port , SEV_SEG_THREE);
					break;
				case 4 :
					DIO_VidSetPortValue(Copy_U8Port , SEV_SEG_FOUR);
					break;
				case 5 :
					DIO_VidSetPortValue(Copy_U8Port , SEV_SEG_FIVE);
					break;
				case 6 :
					DIO_VidSetPortValue(Copy_U8Port , SEV_SEG_SEX);
					break;
				case 7 :
					DIO_VidSetPortValue(Copy_U8Port , SEV_SEG_SEVEN);
					break;
				case 8 :
					DIO_VidSetPortValue(Copy_U8Port , SEV_SEG_EIGHT);
					break;
				case 9 :
					DIO_VidSetPortValue(Copy_U8Port , SEV_SEG_NINE);
					break;
				default:
					break;
				}

}

void SEV_SEG_VidInit(void)
{
	DIO_VidSetPortDirection(SEV_SEG_PORT1,0b11111111);
	DIO_VidSetPortDirection(SEV_SEG_PORT2,0b11111111);
}


