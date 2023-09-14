#include "SmartHome.h"

void SH_VidInitAC()
{
	ADC_VidInit();

	u16 Local_U16DigValue_1 , Local_U8AnalogValue_1 ;

	Local_U16DigValue_1 = ADC_U16GetDigitalValue(ADC_CHANNEL_1);
	Local_U8AnalogValue_1 = (u16)((Local_U16DigValue_1 * 5000UL)/1024);

	DIO_VidSetPinDirection(DIO_PORTA ,DIO_PIN1 , DIO_INPUT);
	DIO_VidSetPinDirection(DIO_PORTC ,DIO_PIN4 , DIO_OUTPUT);

	if((Local_U8AnalogValue_1 > 250))  //temp sensor //250 --> 25 Celsius
		DIO_VidSetPinValue(DIO_PORTC,DIO_PIN4,DIO_HIGH);
	else
		DIO_VidSetPinValue(DIO_PORTC,DIO_PIN4,DIO_LOW);
}

void SH_VidInitLightSystem()
{
	ADC_VidInit();

	u16 Local_U16DigValue , Local_U8AnalogValue ;

	Local_U16DigValue = ADC_U16GetDigitalValue(ADC_CHANNEL_0);
	Local_U8AnalogValue = (u16)((Local_U16DigValue * 5000UL)/1024);

	DIO_VidSetPinDirection(DIO_PORTA, DIO_PIN0 , DIO_INPUT);

	DIO_VidSetPinDirection(DIO_PORTC ,  DIO_PIN0 ,  DIO_OUTPUT);
	DIO_VidSetPinDirection(DIO_PORTC ,  DIO_PIN1 ,  DIO_OUTPUT);
	DIO_VidSetPinDirection(DIO_PORTC ,  DIO_PIN2 ,  DIO_OUTPUT);
	DIO_VidSetPinDirection(DIO_PORTC ,  DIO_PIN3 ,  DIO_OUTPUT);

	if((Local_U8AnalogValue >= 0) && (Local_U8AnalogValue < 1500) )
	{
		DIO_VidSetPinValue(DIO_PORTC,DIO_PIN0,DIO_HIGH);
		DIO_VidSetPinValue(DIO_PORTC,DIO_PIN1,DIO_LOW);
		DIO_VidSetPinValue(DIO_PORTC,DIO_PIN2,DIO_LOW);
		DIO_VidSetPinValue(DIO_PORTC,DIO_PIN3,DIO_LOW);
	}

	else if ((Local_U8AnalogValue >= 1500) && (Local_U8AnalogValue < 3000) )
	{
		DIO_VidSetPinValue(DIO_PORTC,DIO_PIN0,DIO_HIGH);
		DIO_VidSetPinValue(DIO_PORTC,DIO_PIN1,DIO_HIGH);
		DIO_VidSetPinValue(DIO_PORTC,DIO_PIN2,DIO_LOW);
		DIO_VidSetPinValue(DIO_PORTC,DIO_PIN3,DIO_LOW);
	}

	else if ((Local_U8AnalogValue >= 3000) && (Local_U8AnalogValue < 4500) )
	{
		DIO_VidSetPinValue(DIO_PORTC,DIO_PIN0,DIO_HIGH);
		DIO_VidSetPinValue(DIO_PORTC,DIO_PIN1,DIO_HIGH);
		DIO_VidSetPinValue(DIO_PORTC,DIO_PIN2,DIO_HIGH);
		DIO_VidSetPinValue(DIO_PORTC,DIO_PIN3,DIO_LOW);
	}

	else
	{
		DIO_VidSetPinValue(DIO_PORTC,DIO_PIN0,DIO_HIGH);
		DIO_VidSetPinValue(DIO_PORTC,DIO_PIN1,DIO_HIGH);
		DIO_VidSetPinValue(DIO_PORTC,DIO_PIN2,DIO_HIGH);
		DIO_VidSetPinValue(DIO_PORTC,DIO_PIN3,DIO_HIGH);
	}

}

void SH_VidInitDCMotor()
{
	DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN6,DIO_OUTPUT);
	DIO_VidSetPinValue(DIO_PORTA,DIO_PIN5,DIO_HIGH);

	if(!(DIO_U8GetPinValue(DIO_PORTA,DIO_PIN5)))
	{
		LCD_VidInit();
		LCD_VidSendString("SWITCH pressed");

		DIO_VidSetPinValue(DIO_PORTA,DIO_PIN5,DIO_HIGH);
		DIO_VidSetPinValue(DIO_PORTA,DIO_PIN6,DIO_LOW);
		DIO_VidSetPinValue(DIO_PORTA,DIO_PIN7,DIO_HIGH);

		_delay_ms(1000);
	}
	else
	{
		LCD_VidInit();
		LCD_VidSendString("not pressed");

		DIO_VidSetPinValue(DIO_PORTA,DIO_PIN5,DIO_HIGH);
		DIO_VidSetPinValue(DIO_PORTA,DIO_PIN6,DIO_HIGH);
		_delay_ms(1000);
	}
}

void SH_VidLogin()
{
	u8 x = safe_pass_status(0xFF); //status address
	u16 * passAddress = (u16 *)0xEE; //0x00EE --> password address
	if (x == 0xFF)
	{
		safe_set_pass(passAddress,0xFF);
	}
	else
	{
			LCD_VidInit();
			LCD_VidSendString("check pass");
			_delay_ms(2000);
			u8 y = safe_check_pass(passAddress);
			if (0xff == y)
			{
				LCD_VidInit();
				LCD_VidSendString("Correct password");
				_delay_ms(2000);
			}
			else
			{
				LCD_VidInit();
				LCD_VidSendString("Incorrect pass");
				_delay_ms(2000);
			}
	}
}

u8 safe_pass_status(u16 address)
{
	u8 password_status = 0;
	password_status = EEPROM_read(address);
	return password_status;
}


u32 safe_read_pass(u16* address)
{
	u32 pass_value = 0;
	/*read the password from EEPROM*/
	pass_value = (u8)EEPROM_read(*(address+0));
	pass_value <<= 8;
	pass_value |= (u8)EEPROM_read(*(address+1));
	pass_value <<= 8;
	pass_value |= (u8)EEPROM_read(*(address+2));
	pass_value <<= 8;
	pass_value |= (u8)EEPROM_read(*(address+3));
	/*now return password*/
	return pass_value;
}

void safe_set_pass( u16* address, u16 pass_status)
{
	u8 i = 0, digit = 20;
	LCD_VidInit();
	LCD_VidSendString("Set 8-b password : ");
	LCD_VidGoToLocation(LCD_Second_LINE,1);
	for(i=0; i<6; ++i)
	{
		digit = 20;
		do
		{
			digit = KBD_U8GetPressedKey();
		} while ( digit == 20 );

		LCD_VidSendNumber(digit-48);
		_delay_ms(1000);
		LCD_VidGoToLocation(LCD_Second_LINE, 1+i);
		LCD_VidSendChar('*');
		EEPROM_write(address[i], digit-48);
	}

	EEPROM_write(pass_status, 0x00); //write (0x00) to indicate that password is set
	LCD_VidInit();
	LCD_VidGoToLocation(LCD_FIRST_LINE, 1);
	LCD_VidSendString("Password saved");
	_delay_ms(2000);
}

u8 safe_check_pass(u16* address)
{
	u8 flag = 0xff, digit = 20;
	u8 password1[6] = {0}, password2[6] = {0};
	u8 i=0;

	LCD_VidInit();
	LCD_VidSendString("Enter password:");
	LCD_VidGoToLocation(LCD_Second_LINE,1);
	/* read password from user and EEPROM */
	for(i=0; i<6; ++i)
	{
		digit = 20;
		do
		{
			digit = KBD_U8GetPressedKey();
		} while ( digit == 20 );

		LCD_VidSendNumber(digit - 48);
		_delay_ms(500);
		LCD_VidGoToLocation(LCD_Second_LINE, 1+i);
		LCD_VidSendChar('*');
		password1[i] = EEPROM_read(address[i]);
		password2[i] = (digit - 48);
	}
	/*check if the password is correct or not:*/
	for (i=0; i<6; ++i)
	{
		if (password1[i] != password2[i])
		{
			flag = 0x00;
			return flag;
		}
	}
	flag = 0xff;
	return flag;
}

void SH_VidSimpleLogin()
{
	DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN3,DIO_OUTPUT);

	u16 users_ID[num_of_users] = {1234,2345,3456,4567};
	u16 users_pass[num_of_users] = {0000,1111,2222,3333};

	u16 id,pass;
	u8 i;
	static u8 attempts = 0; //to benefit from recursion

	DIO_VidSetPinValue(DIO_PORTA,DIO_PIN3,DIO_HIGH);
	_delay_us(522);  //need adjustment
	DIO_VidSetPinValue(DIO_PORTA,DIO_PIN3,DIO_LOW);

	id = get_id();
	//id = 1234;

	for (i=0;i<num_of_users;i++)
	{
		if(id==users_ID[i])
		{
			pass=get_pass();
			//pass = 0000;
			if(pass==users_pass[i])
				break;
		}
	}

	if(i==num_of_users)
	{
		attempts++;
		LCD_VidSendCommand(0x01);
		_delay_ms(2);
		LCD_VidSendString("Wrong ID or Pass");
		_delay_ms(1000);
		if(attempts < 3)
		{
			SH_VidSimpleLogin(); //recursion
		}
		else
		{
			LCD_VidSendCommand(0x01);
			_delay_ms(2);
			LCD_VidSendString("You are Blocked!");
			while(1);
		}
	}
	else
	{
		LCD_VidSendCommand(0x01);
		_delay_ms(2);
		LCD_VidSendString("Welcome");
		_delay_ms(1500);
		DIO_VidSetPinValue(DIO_PORTA,DIO_PIN3,DIO_HIGH);
		_delay_us(522);  //need adjustment
		DIO_VidSetPinValue(DIO_PORTA,DIO_PIN3,DIO_LOW);

	}

}




u16 get_id(void)
{
	LCD_VidSendCommand(0x01);
	_delay_ms(2);
	LCD_VidSendString("ID: ");
	u8 digit;
	u16 id=0;
	for (u8 i = 0 ;i < 4 ; i++)
	{
		digit = 20;
		do
		{
			digit = KBD_U8GetPressedKey();
		} while ( digit == 20 );
		LCD_VidSendNumber(digit - 48);
		id = id*10+(digit - 48);
	}
	LCD_VidSendCommand(0x01);
	_delay_ms(2);
	return id;
}

u16 get_pass(void)
{
	LCD_VidSendCommand(0x01);
	_delay_ms(2);
	LCD_VidSendString("PASS:");
	u8 digit;
	u16 pass=0;
	for (u8 i = 0 ;i < 4 ; i++)
	{
		digit = 20;
		do
		{
			digit = KBD_U8GetPressedKey();
		} while ( digit == 20 );
		LCD_VidSendNumber(digit - 48);
		pass = pass*10+(digit - 48);
	}
	LCD_VidSendCommand(0x01);
	_delay_ms(2);

	return pass;
}
