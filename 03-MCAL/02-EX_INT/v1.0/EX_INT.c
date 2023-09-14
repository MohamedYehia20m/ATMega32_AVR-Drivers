#include "BIT_MATH.h"
#include "DIO.h"

#include <avr/interrupt.h>
#include <avr/io.h>

/*
void (*INT0_PFUN)(void);
void (*INT1_PFUN)(void);
void (*INT2_PFUN)(void);
*/


//GIE
//PIE
//MODE

//Function  ---> ISR

/*INT0*/
void EX_INT0VidInit(void)
{
	//GIE
	SET_BIT(SREG,7);
	//PIE
	SET_BIT(GICR,6);
	//MODE
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
}

/*INT1*/
void EX_INT1VidInit(void)
{
	//GIE
	SET_BIT(SREG,7);
	//PIE
	SET_BIT(GICR,7);
	//MODE
	CLR_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
}

/*INT2*/
void EX_INT2VidInit(void)
{
	//GIE
	SET_BIT(SREG,7);
	//PIE
	SET_BIT(GICR,5);
	//MODE
	CLR_BIT(MCUCSR,6);
}
/*
void EX_INT0VidSetCallBack(void (*ptr)(void)  )
{
	INT0_PFUN = ptr;
}

void EX_INT1VidSetCallBack(void (*ptr)(void)  )
{
	INT1_PFUN = ptr;
}

void EX_INT2VidSetCallBack(void (*ptr)(void)  )
{
	INT2_PFUN = ptr;
}
*/


/* layered Arch. Rules */
//APP
		//HAL
				//MCAL

//   LIB     SER





