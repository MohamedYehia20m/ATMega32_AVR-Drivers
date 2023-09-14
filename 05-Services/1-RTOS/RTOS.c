#include "RTOS.h"
#include <avr/io.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO.h"
#include "TIMER0.h"
#include "RTOS.h"

/****************************************/
/* RTOS.c */
/****************************************/

void RTOS_StartOS ( void (*AP_CallBack) (void) )
{
	CTC_SetCallBack (AP_CallBack);
	Timer_Init();
}


void Scheduler ( void )
{
	static u16 Counter = 0;
	Counter++;
	for ( u8 i = 0 ; i < 4 ; i++ )
	{
		if ( Counter % SysTasks[i].TaskPeriodecity == 0 )
		{
			SysTasks[i].P_TaskAction();
		}
	}
	if (Counter == 63000)
	{
		Counter = 0;
	}
}

