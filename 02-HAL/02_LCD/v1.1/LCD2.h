
#include"STD_TYPES.h"
#include"DIO.h"
#define F_CPU 8000000UL
#include"avr/delay.h"


#define   LCD_RS_PORT      DIO_PORTC
#define   LCD_RS_PIN       DIO_PIN5

#define   LCD_RW_PORT      DIO_PORTC
#define   LCD_RW_PIN       DIO_PIN6

#define   LCD_E_PORT      DIO_PORTC
#define   LCD_E_PIN       DIO_PIN7

#define   LCD_DATA_COMMAND_PORT   DIO_PORTD


#define   LCD_FIRST_LINE   0
#define   LCD_Second_LINE   1



//Init
void LCD_VidInit(void);


//Send command
void LCD_VidSendCommand( u8 Copy_U8Command );


//Send Data  ---> char , string , Number
void LCD_VidSendChar( u8 Copy_U8Char );


//Send String
void LCD_VidSendString( u8 *Copy_Pu8String ) ;

//Send Number
void LCD_VidSendNumber( u32 Copy_U8Number );

//Goto
void LCD_VidGoToLocation ( u8 Copy_U8RowNumber , u8 Copy_U8ColNumber );

