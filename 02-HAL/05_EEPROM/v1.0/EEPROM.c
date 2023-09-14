#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TWI.h"
#include "EEPROM.h"
#include "DIO.h"

#include <avr/delay.h>

#define F_CPU 8000000UL

void EEPROM_VidWriteData(u16 Copy_U16Address ,u8 Copy_U8Data)
{
	/* start condition */
	TWI_VidStartCondition();

	/*send address*/
	TWI_VidSendSlaveAddressToWrite(0x50 | (0 << 2)| (Copy_U16Address >> 8) );
	TWI_VidMasterSendDataToSlave((u8)Copy_U16Address);

	/* send data */
	TWI_VidMasterSendDataToSlave(Copy_U8Data);

	/* stop Condition */
	TWI_VidStopCondition();

	_delay_ms(10);
}

u8 EEPROM_VidReadData(u16 Copy_U16Address )
{
	u8 Data ;
	/* start condition */
	TWI_VidStartCondition();

	/*send address*/
	TWI_VidSendSlaveAddressToWrite(0x50 | (0 << 2)| (Copy_U16Address >> 8) );
	TWI_VidMasterSendDataToSlave((u8)Copy_U16Address);

	/* start condition */
	TWI_VidStartCondition();
	/*send address*/
	TWI_VidSendSlaveAddressToWrite(0x50 | (0 << 2)| (Copy_U16Address >> 8) );


	/*get the data*/
	Data = TWI_U8MasterReadDataFromSlave();

	/* stop Condition */
	TWI_VidStopCondition();



	/*return data*/
	return Data;
}
