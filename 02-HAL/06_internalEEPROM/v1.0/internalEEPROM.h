#ifndef INTERNALEEPROM_H_
#define INTERNALEEPROM_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include <avr/io.h>

/*
function name: EEPROM_write
function arguments: (uint16 address, uint8 data)
function return: void
function description: It writes 8-bit data to the given address in internal EEPROM
*/
void EEPROM_write(u16 address, u8 data);


/*
function name: EEPROM_read
function arguments: (uint16 address)
function return: uint8
function description: It reads 8-bit data from the given address in internal EEPROM
*/
u8 EEPROM_read(u16 address);


#endif /* INTERNALEEPROM_H_ */
