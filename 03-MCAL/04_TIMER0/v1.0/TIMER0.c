

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "TIMER0.h"

#include <avr/io.h>
#include <avr/interrupt.h>

void Timers_VidTimer0Init(void)
{
	/*select mode */
	/*Normal mode */
	//CLR_BIT(TCCR0 , WGM00);
	//CLR_BIT(TCCR0 , WGM01);

	/*CTC mode*/
	//CLR_BIT(TCCR0 , WGM00);
	//SET_BIT(TCCR0 , WGM01);

	/*Fast PWM */
	//SET_BIT(TCCR0 , WGM00);
	//SET_BIT(TCCR0 , WGM01);

	/*Fast Phase correct PWM */
	SET_BIT(TCCR0 , WGM00);
	CLR_BIT(TCCR0 , WGM01);


	/*setup the mode of OC0 pin  --> Fast PWM*/
	//CLR_BIT(TCCR0 , COM00);
	//CLR_BIT(TCCR0 , COM01);

	/*setup the mode of OC0 pin  --> phase correct */
	CLR_BIT(TCCR0 , COM00);
	SET_BIT(TCCR0 , COM01);

	/*Enable the interrupt */
	/*GIE*/
	//SET_BIT(SREG , 7);
	/*PIE   --> OVF */
	//SET_BIT(TIMSK , TOIE0);

	/*PIE   --> CTC */
	//SET_BIT(TIMSK , OCIE0);

	/*setup the preload value*/
	//TCNT0 = 0;

	/*setup OCR Value*/
	//OCR0 = 99;

	/*select prescaler factor */
	/* /8 */
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);

}


ISR(TIMER0_OVF_vect)
{
	static u16 Local_U16CounterOVF = 0;
	Local_U16CounterOVF++;
	if (Local_U16CounterOVF == 3907)
	{
		Local_U16CounterOVF = 0;
		//setup the preload value
			//TCNT0 = 192;
		//functionality
		DIO_VidTogglePinValue(DIO_PORTA , DIO_PIN0);


	}
}



ISR(TIMER0_COMP_vect)
{
	static u16 Local_U16CounterCTC = 0;
	Local_U16CounterCTC++;
	if (Local_U16CounterCTC == 10000)
	{
		Local_U16CounterCTC = 0;
		/*setup the preload value*/
			//TCNT0 = 0;
		/*functionality*/
		DIO_VidTogglePinValue(DIO_PORTA , DIO_PIN0);


	}
}






