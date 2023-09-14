#include"DIO.h"

#define KEYPAD_PORT DIO_PORTD

void KEYPAD_VidInit(void);
u8 KEYPAD_U8GetPressedKey(void);
