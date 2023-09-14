#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART.h"
#include <avr/io.h>

void USART_VidSendChar(u8 Copy_U8Char);

u8 USART_U8GetChar(void);

void USART_VidInit(void)
{
	u8 Local_U8UCSRCValue = 0b10000000 ;
	u16 Local_U16BaudValue = 51 ;

	/*Setup the Baud rate*/
	UBRRL = (u8)Local_U16BaudValue ;
	UBRRH = (u8)(Local_U16BaudValue >> 8);

	/*Normal Speed*/
	CLR_BIT(UCSRA , U2X);

	/*Tx , Rx Enables*/
	SET_BIT(UCSRB , TXEN);
	SET_BIT(UCSRB , RXEN);

	/*async*/
	CLR_BIT(Local_U8UCSRCValue , UMSEL);

	/*parity*/
	CLR_BIT(Local_U8UCSRCValue , UPM0);
	CLR_BIT(Local_U8UCSRCValue , UPM1);

	/*2 stop bits*/
	SET_BIT(Local_U8UCSRCValue , USBS);

	/*Character Size 8 bits*/
	SET_BIT(Local_U8UCSRCValue , UCSZ0);
	SET_BIT(Local_U8UCSRCValue , UCSZ1);
	CLR_BIT(UCSRB , UCSZ2);

	/*update Register value*/
	UCSRC = Local_U8UCSRCValue ;
}

void USART_VidSendChar(u8 Copy_U8Char)
{
	while (GET_BIT(UCSRA , UDRE) == 0);
	UDR = Copy_U8Char ;
}

u8 USART_U8GetChar(void)
{
	u8 Local_U8CharValue;
	while (GET_BIT(UCSRA , RXC) == 0);
	Local_U8CharValue = UDR ;
	return Local_U8CharValue;
}



