#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"
#include "ADC.h"
#include "LCD2.h"
#include "KBD.h"
#include "internalEEPROM.h"


#include "SmartHome.h"
#include <avr/io.h>
#include <avr/delay.h>

#define F_CPU 8000000UL

void main (void)
{
	KBD_VidInit();
	LCD_VidInit();

	//SH_VidLogin();
	SH_VidSimpleLogin();
	while(1)
	{
		SH_VidInitLightSystem();
		SH_VidInitAC();
		SH_VidInitDCMotor();

	}

}
