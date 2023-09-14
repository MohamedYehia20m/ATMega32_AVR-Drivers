#ifndef DIO.h
#define DIO.h



#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include<avr/io.h>
#include "avr/delay.h"

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

#define SEV_SEG_PORT2 DIO_PORTC
#define SEV_SEG_PORT1 DIO_PORTD

	//0 --> 0b00111111
	//1 --> 0b00000110
	//2 --> 0b01011011
	//3 --> 0b01001111
	//4 --> 0b01100110
	//5 --> 0b01101101
	//6 --> 0b01111101
	//7 --> 0b00000111
	//8 --> 0b01111111
	//9 --> 0b01101111

#define SEV_SEG_ZERO 0b00111111
#define SEV_SEG_ONE 0b00000110
#define SEV_SEG_TWO 0b01011011
#define SEV_SEG_THREE 0b01001111
#define SEV_SEG_FOUR 0b01100110
#define SEV_SEG_FIVE 0b01101101
#define SEV_SEG_SEX 0b01111101
#define SEV_SEG_SEVEN 0b00000111
#define SEV_SEG_EIGHT 0b01111111
#define SEV_SEG_NINE 0b01101111




/* function to set the direction */
void DIO_VidSetPinDirection(u8 Copy_U8Port , u8 Copu_U8Pin , u8 copy_U8Direction);


/* function to set the value */
void DIO_VidSetPinValue(u8 Copy_U8Port , u8 Copu_U8Pin , u8 copy_U8Value);

void DIO_VidSetPortDirection(u8 Copy_U8Port , u8 Copy_U8Direction);

void DIO_VidSetPortValue(u8 Copy_U8Port , u8 Copy_U8Value);

void DIO_VidTogglePinValue(u8 Copy_U8PORT , u8 Copy_U8Pin);  //+lab 1 -->4 lec1-interfacing without drive D9
															//+lab 1 -->5 lec1-interfacing with drive  D10

void SEV_SEG_VidInit(void);

void SEV_SEG_VidSetNumber(u8 Copy_U8Port, u8 Copy_U8Value);





#endif
