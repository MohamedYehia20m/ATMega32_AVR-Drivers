#ifndef LCD2.h
#define LCD2.h

#include <avr/io.h>
#include <avr/delay.h>


#define DIO_INPUT 0
#define DIO_OUTPUT 1

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_HIGH 1
#define DIO_LOW 0

#define LCD_RS_PORT DIO_PORTA
#define LCD_RS_PIN DIO_PIN0

#define LCD_RW_PORT DIO_PORTA
#define LCD_RW_PIN DIO_PIN1

#define LCD_E_PORT DIO_PORTA
#define LCD_E_PIN DIO_PIN2

#define LCD_DATA_COMMAND_PORT DIO_PORTB

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include<avr/io.h>
#include "avr/delay.h"

void LCD_VidSendCommand(u8 Copy_U8Command);
//void LCD_SendData(u8 Data);
void LCD_Vidinit(void);

void LCD_VidSendChar(u8 Copy_U8Char);

void LCD_VidSendString(u8 *Copy_U8String);

void LCD_VidSendNumber(u32 Copy_U8Number);



void DIO_VidSetPinDirection(u8 Copy_U8Port , u8 Copu_U8Pin , u8 copy_U8Direction);

/* function to set the value */
void DIO_VidSetPinValue(u8 Copy_U8Port , u8 Copu_U8Pin , u8 copy_U8Value);

void DIO_VidSetPortDirection(u8 Copy_U8Port , u8 Copy_U8Direction);

void DIO_VidSetPortValue(u8 Copy_U8Port , u8 Copy_U8Value);






#endif
