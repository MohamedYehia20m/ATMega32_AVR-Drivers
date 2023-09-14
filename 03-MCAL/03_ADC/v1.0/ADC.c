#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/io.h>

#include "ADC.h"

void ADC_VidInit(void)
{
	// Set Ref  ---> AVCC
	SET_BIT(ADMUX , REFS0);
	CLR_BIT(ADMUX , REFS1);

	// Set right adjust
	CLR_BIT(ADMUX , ADLAR);

	// Auto trigger --> disabled
	CLR_BIT(ADCSRA , ADATE);


	// set prescaler --> 50K - 200K --> 8M /64
	CLR_BIT(ADCSRA , ADPS0);
	SET_BIT(ADCSRA , ADPS1);
	SET_BIT(ADCSRA , ADPS2);

	// ADC Enable
	SET_BIT(ADCSRA , ADEN);
}

u16 ADC_U16GetDigitalValue( u8 Copy_U8ChannelNumber )
{
	u16 Local_U16DigitalValue ;

	// Select Channel
	ADMUX &= 0b11100000 ;
	ADMUX |= Copy_U8ChannelNumber;  /*channel Number*/

	// start conversion
	SET_BIT(ADCSRA , ADSC);

	// wait for flag
	while((GET_BIT(ADCSRA , ADIF))  == 0);

	SET_BIT(ADCSRA , ADIF);

	Local_U16DigitalValue = ADC;
	return Local_U16DigitalValue;

}
