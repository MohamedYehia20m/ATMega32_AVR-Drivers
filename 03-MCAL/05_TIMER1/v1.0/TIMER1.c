

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "TIMER1.h"

void Timers_VidTimer1Init(void)
{
	/*select mode */

	/*Normal mode */
	//CLR_BIT(TCCR0 , WGM00);
	//CLR_BIT(TCCR0 , WGM01);

	/*CTC mode*/
	//CLR_BIT(TCCR0 , WGM00);
	//SET_BIT(TCCR0 , WGM01);

	/*Fast PWM --> 14*/
	CLR_BIT(TCCR1A , WGM10);
	SET_BIT(TCCR1A , WGM11);
	SET_BIT(TCCR1B , WGM12);
	SET_BIT(TCCR1B , WGM13);

	/*Select Mode OC1A Pin --> Fast PWM*/
	CLR_BIT(TCCR1A , COM1A0 );
	SET_BIT(TCCR1A , COM1A1 );

	/*Setup the value of ICR1 */
	ICR1 = 19999;

	/*Setup OCR1A --> for the angle of servo */
	OCR1A = 999;


	/*Enable the interrupt */
	/*GIE*/
	SET_BIT(SREG , 7);
	/*PIE   --> OVF */
	SET_BIT(TIMSK , TOIE0);

	/*PIE   --> CTC */
	SET_BIT(TIMSK , OCIE0);

	/*setup the preload value*/
	//TCNT0 = 0;

	/*setup OCR Value*/
	OCR0 = 99;

	/*select prescaler factor */
	/* /8 */
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);

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






