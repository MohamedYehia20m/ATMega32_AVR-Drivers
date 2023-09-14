#ifndef DIO_H_
#define DIO_H_



#include <avr/io.h>
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define F_CPU 8000000UL

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

#define SET_BYTE(x) x = 0b11111111
#define CLR_BYTE(x) x = 0b00000000





/* function to set the direction */
void DIO_VidSetPinDirection(u8 Copy_U8Port , u8 Copu_U8Pin , u8 copy_U8Direction);


/* function to set the value */
void DIO_VidSetPinValue(u8 Copy_U8Port , u8 Copu_U8Pin , u8 copy_U8Value);

void DIO_VidSetPortDirection(u8 Copy_U8Port , u8 Copy_U8Direction);

void DIO_VidSetPortValue(u8 Copy_U8Port , u8 Copy_U8Value);

void DIO_VidTogglePinValue(u8 Copy_U8PORT , u8 Copy_U8Pin);  //+lab 1 -->4 lec1-interfacing without drive D9
															//+lab 1 -->5 lec1-interfacing with drive  D10

void DIO_Vid7SegConfig(u8 Copy_U8Port , u8 Copy_U8Value);




#endif
