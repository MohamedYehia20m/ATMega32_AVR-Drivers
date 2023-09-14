
#include "internalEEPROM.h"

void EEPROM_write(u16 address, u8 data)
{
	//* Wait for completion of previous write */
	while(EECR & (1<<EEWE));

	/* Set up address and data registers */
	EEARH = (u8)(address >> 8);
	EEARL = (u8)(address);

	EEDR = data;
	/* Write logical one to EEMWE */
	EECR |= (1<<EEMWE);
	/* Start eeprom write by setting EEWE */
	EECR |= (1<<EEWE);
}


u8 EEPROM_read(u16 address)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));

	/* Set up address register */
	EEARH = (u8)(address >> 8);
	EEARL = (u8)(address);

	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);

	/* Return data from data register */
	return EEDR;
}
