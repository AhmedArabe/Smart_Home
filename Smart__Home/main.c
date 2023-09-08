/*
 * main.c
 *
 *  Created on: Aug 6, 2023
 *      Author: WIN10
 */
#define F_CPU		8000000UL
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include <string.h>
#include "MCAL/DIO/DIO_Interface.h"
#include  "HAL/LED/LED_Interface.h"
#include <util/delay.h>
#include "HAl/CLCD/CLCD_Interface.h"
#include  "MCAL/ADC/ADC_Interface.h"
#include "MCAL/TIMERS/TIMERS_Interface.h"
#include "MCAL/Timer1/TIMER1_Interface.h"
#include "HAL/Servo/Servo_interface.h"
#include "MCAL/UART/UART_Interface.h"
#include "APP/Users.h"


int main()
{

	/* Initialize LCD */
	CLCD_voidInit();
	/*Initialize Servo */
	Servo_voidInit();
	/*Initialize UART */
	UART_voidInit(Parity_Disabled,one_stop_bit,eight_bits,9600);

	/*Set Port A To Be Output For LEDs */
	DIO_voidSetPortDirection(DIO_PORTA,DIO_OUTPUT);
	/*set pin 0 as output to a buzzer */
	DIO_voidSetPortDirection(DIO_PORTB,DIO_OUTPUT);


	u8 password[5];
	u8 user[10];
	u8 flag=0;
	u8 Local_u8Counter=0;
	u8 fail_flag=0;
	u8 Name_flag=0;
	u8 Local_u8Counter2=0;
	u8 choice;
	u8 index;

	UART_voidSendStringSync((u8*)"welcome :");

	while(1)
	{
		if(flag!=3)
		{

			CLCD_CLEAR();
			UART_voidSendStringSync((u8*)"\rEnter UserName:");
			CLCD_voidSendString((u8*)"Enter UserName:");
			CLCD_voidGOTO(1,2);
			UART_voidreceiveStringSync(user);
		}

		while(Local_u8Counter2 != 5)
		{
			if(strcmp(user,names[Local_u8Counter2])==0)
			{
				Name_flag=1;
				index=Local_u8Counter2;
			}
			Local_u8Counter2++;
		}

		if(Name_flag==1)
		{
			CLCD_CLEAR();
			UART_voidSendStringSync((u8*)"\rEnter Password:");
			CLCD_voidSendString((u8*)"Enter Password:");
			CLCD_voidGOTO(1,2);
			UART_voidreceiveStringSync(password);
			if(strcmp(password,passes[index])==0)
			{
				flag=4;
			}else
			{
				flag=3;

			}
		}else
		{
			CLCD_CLEAR();
			UART_voidSendStringSync((u8*)"Wrong User name\n");
			CLCD_voidSendString((u8*)"Wrong User");
			_delay_ms(300);
			Local_u8Counter2=0;
		}

		if(flag==4)
		{

			UART_voidSendStringSync((u8*)"\rWelcome To Back  \n\n");
			CLCD_CLEAR();
			CLCD_voidSendString((u8*)"Welcome TO");
			CLCD_voidGOTO(1,2);
			CLCD_voidSendString((u8*)"Your Home");
			_delay_ms(1000);

			while(flag==4)
			{

				UART_voidSendStringSync((u8*)"\r1-Door\n\n");
				UART_voidSendStringSync((u8*)"\r2-LED  ");
				UART_voidSendStringSync((u8*)" 3-Fan     \n");


				CLCD_CLEAR();
				CLCD_voidSendString((u8*)"1-Door_C");
				CLCD_voidGOTO(1,2);
				CLCD_voidSendString((u8*)"2-LED_C");

				CLCD_voidSendString((u8*)" 3-FAN_C");

				choice=UART_u8ReciveDataSync();
				//UART_voidSendDataSync(choice);////////////


				if(choice=='1')
				{
					UART_voidSendStringSync((u8*)"\r1-Open Door\n");
					UART_voidSendStringSync((u8*)"\r2-Close Door   ");

					CLCD_CLEAR();
					CLCD_voidSendString((u8*)"1-Open Door");
					CLCD_voidGOTO(1,2);
					CLCD_voidSendString((u8*)"2-Close Door");
					u8 choice2=UART_u8ReciveDataSync();
					//	UART_voidSendDataSync(choice2);
					if(choice2=='1')
					{

						Servo_voidSetAngle(90);
					//UART_voidSendStringSync((u8*)"\r-Door Is Open   ");
						CLCD_CLEAR();
						CLCD_voidSendString((u8*)"Door Is");
						CLCD_voidGOTO(1,2);
						CLCD_voidSendString((u8*)"Open");
						_delay_ms(500);

					}else if(choice2=='2')
					{
						Servo_voidSetAngle(0);
					//	UART_voidSendStringSync((u8*)"\r-Door Is Closed\n");
						CLCD_CLEAR();
						CLCD_voidSendString((u8*)"Door Is");
						CLCD_voidGOTO(1,2);
						CLCD_voidSendString((u8*)"Closed");
						_delay_ms(500);
					}



				}else if (choice=='2')
				{

					UART_voidSendStringSync((u8*)"\r1-LED ON\n");
					UART_voidSendStringSync((u8*)"\r2-LED OFF    ");
					CLCD_CLEAR();
					CLCD_voidSendString((u8*)"1-LED ON");
					CLCD_voidGOTO(1,2);
					CLCD_voidSendString((u8*)"2-LED OFF");
					u8 choice2=UART_u8ReciveDataSync();
					//UART_voidSendDataSync(choice2);
					if(choice2=='1')
					{

						DIO_voidSetPortValue(DIO_PORTA,DIO_PORT_OUTPUT);
						CLCD_CLEAR();
						CLCD_voidSendString((u8*)"LED Is");
						CLCD_voidGOTO(1,2);
						CLCD_voidSendString((u8*)"ON");
						_delay_ms(500);

					}else if(choice2=='2')
					{
						DIO_voidSetPortValue(DIO_PORTA,DIO_PORT_LOW);
						CLCD_CLEAR();
						CLCD_voidSendString((u8*)"LED Is");
						CLCD_voidGOTO(1,2);
						CLCD_voidSendString((u8*)"OFF");
						_delay_ms(500);



					}

				}
				else if(choice=='3')
				{
					UART_voidSendStringSync((u8*)"\r1-FAN ON\n");
					UART_voidSendStringSync((u8*)"\r2-FAN OFF    ");
					CLCD_CLEAR();
					CLCD_voidSendString((u8*)"1-FAN ON");
					CLCD_voidGOTO(1,2);
					CLCD_voidSendString((u8*)"2-FAN OFF");
					u8 choice2=UART_u8ReciveDataSync();
					if(choice2=='1')
					{
						DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_HIGH);
						CLCD_CLEAR();
						CLCD_voidSendString((u8*)"FAN Is");
						CLCD_voidGOTO(1,2);
						CLCD_voidSendString((u8*)"ON");
						_delay_ms(500);

					}else if(choice2=='2')
					{
						DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_LOW);
						CLCD_CLEAR();
						CLCD_voidSendString((u8*)"FAN Is");
						CLCD_voidGOTO(1,2);
						CLCD_voidSendString((u8*)"OFF");
						_delay_ms(500);

					}

				}

				else
				{
					UART_voidSendStringSync((u8*)"Wrong choice\n");
					flag=0;

				}
			}


		}
		else if(flag!=4 &&Name_flag==1)
		{

			UART_voidSendStringSync((u8*)"Wrong Pass      ");
			CLCD_CLEAR();
			CLCD_voidSendString((u8*)"Wrong Pass      ");
			_delay_ms(300);
			flag=3;
			fail_flag++;
			while(fail_flag==3)
			{

				DIO_voidSetPortValue(DIO_PORTA,DIO_PORT_HIGH);
				DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_HIGH);
				_delay_ms(300);
				DIO_voidSetPortValue(DIO_PORTA,DIO_PORT_LOW);
				_delay_ms(300);

			}
			Local_u8Counter=0;
		}
	}





	return 0;
}
