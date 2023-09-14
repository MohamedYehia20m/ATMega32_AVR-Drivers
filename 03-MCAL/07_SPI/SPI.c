#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI.h"
#include <avr/io.h>


void SPI_VidMasterInit(void)
{
	/*Master Mode*/
	SET_BIT(SPCR , MSTR);

	/*MSB*/
	CLR_BIT(SPCR , DORD);

	/* /16 */
	SET_BIT(SPCR , SPR0);
	CLR_BIT(SPCR , SPR1);
	CLR_BIT(SPCR , SPI2X);

	/*CLK Setup*/
	SET_BIT(SPCR , CPHA);
	SET_BIT(SPCR , CPOL);

	/*SPI Enable*/
	SET_BIT(SPCR , SPE);
}

void SPI_VidSlaveInit(void)
{
	/*Slave Mode*/
	CLR_BIT(SPCR , MSTR);

	/*MSB*/
	CLR_BIT(SPCR , DORD);

	/*CLK Setup*/
	SET_BIT(SPCR , CPHA);
	SET_BIT(SPCR , CPOL);

	/*SPI Enable*/
	SET_BIT(SPCR , SPE);
}

u8 SPI_U8TransmitRecieve( u8 Copy_U8Data )
{
	SPDR = Copy_U8Data;
	while((GET_BIT(SPSR , SPIF)) == 0);
	return SPDR ;
}

void SPI_U8Transmit( u8 Copy_U8Data )
{
	SPDR = Copy_U8Data;
}

u8 SPI_U8TRecieve()
{
	while((GET_BIT(SPSR , SPIF)) == 0);
	return SPDR ;
}



