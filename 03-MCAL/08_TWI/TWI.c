#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TWI.h"

#include <avr/io.h>

/************* Master ************/
void TWI_VidMasterInit(void)
{
	/*speed*/
		//prescaler --> 1
		CLR_BIT(TWSR , TWPS1);
		CLR_BIT(TWSR , TWPS0);
		//from the equation
		TWBR = 3;
		/* Enable TWI */
		SET_BIT(TWCR , TWEN);
}

void TWI_VidStartCondition(void)
{
	/* start condition */
	SET_BIT(TWSR , TWSTA);

	/* CLR Flag */
	SET_BIT(TWCR , TWINT);

	/* Wait for the flag */
	while((GET_BIT(TWCR , TWINT)) == 0);

}

void TWI_VidSendSlaveAddressToWrite(u8 copy_U8Address)
{
	/* Send the Address */
	TWDR = (copy_U8Address << 1);

	/* Set write operation */
	CLR_BIT(TWDR , 0);

	/* CLR start condition*/
	CLR_BIT(TWCR , TWSTA);

	/* CLR Flag */
	SET_BIT(TWCR , TWINT);

	/* Wait for the flag */
	while((GET_BIT(TWCR , TWINT)) == 0);
}

void TWI_VidSendSlaveAddressToRead(u8 copy_U8Address)
{
	/* Send the Address */
	TWDR = (copy_U8Address << 1);

	/* Set write operation */
	SET_BIT(TWDR , 0);

	/* CLR start condition*/
	CLR_BIT(TWCR , TWSTA);

	/* CLR Flag */
	SET_BIT(TWCR , TWINT);

	/* Wait for the flag */
	while((GET_BIT(TWCR , TWINT)) == 0);

}

void TWI_VidMasterSendDataToSlave( u8 copy_U8Data)
{
	/* Send Data */
	TWDR = copy_U8Data;

	/* CLR Flag */
	SET_BIT(TWCR , TWINT);

	/* Wait for the flag */
	while((GET_BIT(TWCR , TWINT)) == 0);
}

u8 TWI_U8MasterReadDataFromSlave(void)
{
	/* CLR Flag */
	SET_BIT(TWCR , TWINT);

	/* Wait for the flag */
	while((GET_BIT(TWCR , TWINT)) == 0);

	/* Read the Data */
	return TWDR ;
}

void TWI_VidStopCondition(void)
{
	/* stop condition */
	SET_BIT(TWSR , TWSTO);

	/* CLR Flag */
	SET_BIT(TWCR , TWINT);

}

/************* slave **************/

void TWI_VidSlaveInit( u8 Copy_U8SlaveAddress)
{
	/* ACK Enable */
	SET_BIT( TWCR , TWEA );

	/* Set up the address */
	TWAR = Copy_U8SlaveAddress << 1;

	/* Enable TWI */
	SET_BIT( TWCR , TWEN );


}

void TWI_VidSlaveSendDataToMaster( u8 copy_U8SlaveData)
{

}

u8 TWI_U8SlaveGetDataFromMaster(void)
{
	/* Address */
	while ((TWSR & 0b11111000) != 0x60);

	/*CLR Flag*/
	SET_BIT(TWCR , TWINT);

	/* Data */
	while ((TWSR & 0b11111000) != 0x80);

	return TWDR ;
}



















/* Specs */
/*
 * wired
 * serial
 * multi master multi slave
 * synchronous
 * half duplex
 * throughput
*/

/* H.W Interface*/
/*
 *	SCL --> CLK
 *	SDA --> Data , add
 */


/* Frame Format */
/**
 *	start condition
 *	slave address 7 bits + 1 bit R/W
 *	ACK
 *	Data
 *	ACK
 *	Stop Condition
 *
 */

