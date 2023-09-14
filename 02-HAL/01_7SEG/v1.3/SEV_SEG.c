
#include"DIO.h"
#include"SEV_SEG.h"

void SEV_SEG_VidInit(void)
{
	//Set Direction
	DIO_VidSetPortDirection( SEV_SEG_PORT , 0b11111111 );

}


void SEV_SEG_VidSetNumber (  u8 Copy_U8Number )
{
	//Set the value
	DIO_VidSetPortValue( SEV_SEG_PORT , Copy_U8Number );
}
