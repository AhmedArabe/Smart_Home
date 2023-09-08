/*
 * TIMER1.c
 *
 *  Created on: Aug 17, 2023
 *      Author: WIN10
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TIMER1_Interface.h"
#include "TIMER1_Private.h"
#include "TIMER1_Config.h"
#include"../../HAL/CLCD/CLCD_Interface.h"



static void (*GP_Notification) (void)= NULL;

void __vector_7	(void)  __attribute((signal));



void T1_voidInit(TIMER1_CONFIG *Ptr_Str)
{
	if((Ptr_Str ->T1_WF_MODE ==T1_NORMAL_MODE) ||(Ptr_Str ->T1_WF_MODE ==T1_CTC1_MODE)||(Ptr_Str ->T1_WF_MODE ==T1_CTC2_MODE))
	{
		SET_BIT(TCCR1A_REG,FOC1A);
		SET_BIT(TCCR1A_REG,FOC1B);
	}else
	{
		CLR_BIT(TCCR1A_REG,FOC1B);
		CLR_BIT(TCCR1A_REG,FOC1A);


	}

	//Select Operating Wave Form Mode
	TCCR1A_REG&=0xFC;
	TCCR1A_REG|=Ptr_Str->T1_WF_MODE;
	TCCR1B_REG &=0xE7;
	TCCR1B_REG|=((Ptr_Str->T1_WF_MODE)<<1);



	//Select CLock
	TCCR1B_REG &=0xf8;
	TCCR1B_REG |= (Ptr_Str->T1_CLOCK_MODE);

	//Select OC1A Mode


	//Choose Polling Or Interrupt
	//Enable PIE
	switch(Ptr_Str->T1_TECHNIQUE)
	{
	case T1_Polling:
		break;

	case T1_Interrupt:
		switch(Ptr_Str->T1_WF_MODE)
		{
		case T1_NORMAL_MODE:
			SET_BIT(TIMSK_REG,TOIE1);
			break;

		case T1_CTC1_MODE:
			SET_BIT(TIMSK_REG,OCIE1B);
			SET_BIT(TIMSK_REG,OCIE1A);
			break;

		case T1_CTC2_MODE:
			SET_BIT(TIMSK_REG,OCIE1B);
			SET_BIT(TIMSK_REG,OCIE1A);
			break;
		}
		break;
	}


}
void T1_voidStartTimer(TIMER1_CONFIG *Ptr_Str)
{

	switch(Ptr_Str->T1_Channel)
	{

	case T1_ChannelA:

		switch(Ptr_Str->T1_WF_MODE)
		{
		case T1_NORMAL_MODE:
			TCNT1_REG	= Ptr_Str->T1_Preload_value;
			switch(Ptr_Str->T1_TECHNIQUE)
			{
			case T1_Polling:
				//wait till flag
				while(GET_BIT(TIFR_REG,TOV1) ==0);
				//clear flag
				SET_BIT(TIFR_REG,TOV1);
				break;
			case T1_Interrupt:
				//ISR Will Do The Work
				break;

			}
			break;

			case T1_CTC1_MODE:
				OCR1A_REG	= Ptr_Str->T1_Compare_value;
				TCCR1A_REG &=0x3F;
				TCCR1A_REG |= ((Ptr_Str->T1_CTC_OC1A)<<6);

				switch(Ptr_Str->T1_TECHNIQUE)
				{
				case T1_Polling:
					//wait till flag
					while(GET_BIT(TIFR_REG,OCF1A) ==0);
					//clear flag
					SET_BIT(TIFR_REG,OCF1A);
					break;


				case T1_Interrupt:
					//ISR Will Do The Work

					CLCD_voidSendData('1');
					break;
				}
				break;

				case T1_PHASE_Correct1_MODE:
					OCR1A_REG	= Ptr_Str->T1_Compare_value;
					TCCR1A_REG &=0x3F;
					TCCR1A_REG |= ((Ptr_Str->T1_PHASE_OC1A)<<6);

					break;


				case T1_FAST_PWM_1:
					OCR1A_REG	= Ptr_Str->T1_Compare_value;
					TCCR1A_REG &=0x3F;
					TCCR1A_REG |= ((Ptr_Str->T1_FASTPWM_OC1A)<<6);
					break;
		}
		break;


		case T1_ChannelB:

			switch(Ptr_Str->T1_WF_MODE)
			{
			case T1_NORMAL_MODE:
				TCNT1_REG	= Ptr_Str->T1_Preload_value;
				switch(Ptr_Str->T1_TECHNIQUE)
				{
				case T1_Polling:
					//wait till flag
					while(GET_BIT(TIFR_REG,TOV1) ==0);
					//clear flag
					SET_BIT(TIFR_REG,TOV1);
					break;
				case T1_Interrupt:
					//ISR Will Do The Work
					break;

				}
				break;

				case T1_CTC1_MODE:
					OCR1B_REG	= Ptr_Str->T1_Compare_value;
					TCCR1A_REG &=0xCF;
					TCCR1A_REG |= ((Ptr_Str->T1_CTC_OC1B)<<4);
					switch(Ptr_Str->T1_TECHNIQUE)
					{
					case T1_Polling:
						//wait till flag
						while(GET_BIT(TIFR_REG,OCF1B) ==0);
						//clear flag
						SET_BIT(TIFR_REG,OCF1B);
						break;


					case T1_Interrupt:
						//ISR Will Do The Work
						break;
					}
					break;

					case T1_PHASE_Correct1_MODE:
						OCR1B_REG	= Ptr_Str->T1_Compare_value;
						TCCR1A_REG &=0xCF;
						TCCR1A_REG |= ((Ptr_Str->T1_PHASE_OC1B)<<4);

						break;


					case T1_FAST_PWM_1:
						OCR1B_REG	= Ptr_Str->T1_Compare_value;
						CLCD_voidSendString((u8*)"ChannelB");
						TCCR1A_REG &=0xCF;
						TCCR1A_REG |= ((Ptr_Str->T1_FASTPWM_OC1B)<<4);
						break;

			}
			break;


	}
}

void T1_voidSetCompareValueT1A(u16 Copy_u16CompareValue)
{

	OCR1A_REG=Copy_u16CompareValue;
}
void T1_voidSetCompareValueT1B(u16 Copy_u16CompareValue)
{

	OCR1B_REG=Copy_u16CompareValue;
}
void T1_voidSet_ICRValue(u16 Copy_u16ICR_VALUE)
{
	ICR1_REG=Copy_u16ICR_VALUE;
}

u16 T1_ReadTCNT1Value(void)
{
	return TCNT1_REG;
}
void T1_WriteTCNT1A(u16 Copy_u8TCNTVal)
{

	TCNT1_REG=Copy_u8TCNTVal;
}


void T1_SetCallBack(void (*PF)(void))
{
	if(PF !=NULL)
	{
		GP_Notification=PF;

	}

}
void __vector_7(void)
{

	if(GP_Notification !=NULL)
	{
		GP_Notification();

	}
}


