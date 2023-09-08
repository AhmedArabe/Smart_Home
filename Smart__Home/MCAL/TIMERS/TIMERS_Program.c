/*
 * TIMERS_Program.c
 *
 *  Created on: Aug 15, 2023
 *      Author: WIN10
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMERS_Interface.h"
#include "TIMERS_Private.h"
#include "TIMERS_Config.h"

static void (*GP_Notification) (void)= NULL;

void __vector_10(void) __attribute__((signal));
void __vector_11(void) __attribute__((signal));

void T0_voidInit(TIMER0_CONFIG *Ptr_Str)
{
	if((Ptr_Str ->WF_MODE ==NORMAL_MODE) ||(Ptr_Str ->WF_MODE ==CTC_MODE))
	{
		SET_BIT(TCCR0_REG,FOC0);
	}else
	{
		CLR_BIT(TCCR0_REG,FOC0);
	}

	//Select Operating Wave Form Mode
	switch(Ptr_Str->WF_MODE)
	{
	case NORMAL_MODE:

		CLR_BIT(TCCR0_REG,WGM00);
		CLR_BIT(TCCR0_REG,WGM01);
		break;

	case PHASE_PWM_MODE:

		SET_BIT(TCCR0_REG,WGM00);
		CLR_BIT(TCCR0_REG,WGM01);
		//OC0_Options
		TCCR0_REG &= 0xcf;
		TCCR0_REG |= ((Ptr_Str -> PHASE_OC0) <<4);

		break;

	case CTC_MODE:
		CLR_BIT(TCCR0_REG,WGM00);
		SET_BIT(TCCR0_REG,WGM01);
		//OC0_Options
		TCCR0_REG &= 0xcf;
		TCCR0_REG |= ((Ptr_Str -> CTC_OC0) <<4);
		break;

	case FAST_PWM:
		SET_BIT(TCCR0_REG,WGM00);
		SET_BIT(TCCR0_REG,WGM01);
		//OC0_Options
		TCCR0_REG &= 0xcf;
		TCCR0_REG |= ((Ptr_Str -> FASTPWM_OC0) <<4);
		break;
	}

	//Select CLock
	TCCR0_REG &=0xf8;
	TCCR0_REG |= (Ptr_Str->CLOCK_MODE);

	//Choose Polling Or Interrupt
	//Enable PIE
	switch(Ptr_Str->TECHNIQUE)
	{
	case Polling:
		break;

	case Interrupt:
		switch(Ptr_Str->WF_MODE)
		{
		case NORMAL_MODE:
			SET_BIT(TIMSK_REG,0);
			break;

		case CTC_MODE:
			SET_BIT(TIMSK_REG,1);
			break;

		}
		break;
	}

}

void T0_voidStartTimer(TIMER0_CONFIG *Ptr_Str)
{
	switch(Ptr_Str->WF_MODE)
	{
	case NORMAL_MODE:
		TCNT0_REG	= Ptr_Str->Preload_value;
		switch(Ptr_Str->TECHNIQUE)
		{
		case Polling:
			//wait till flag
			while(GET_BIT(TIFR_REG,0) ==0);
			//clear flag
			SET_BIT(TIFR_REG,0);
			break;
		case Interrupt:
			//ISR Will Do The Work
			break;

		}
		break;

		case CTC_MODE:
			OCR0_REG	= Ptr_Str->Compare_value;
			switch(Ptr_Str->TECHNIQUE)
			{
			case Polling:
				//wait till flag
				while(GET_BIT(TIFR_REG,1) ==0);
				//clear flag
				SET_BIT(TIFR_REG,1);
				break;


			case Interrupt:
				//ISR Will Do The Work
				break;
			}
			break;

			case PHASE_PWM_MODE:
				OCR0_REG	= Ptr_Str->Compare_value;

				break;


			case FAST_PWM:
				OCR0_REG	= Ptr_Str->Compare_value;

				break;




	}
}



void T0_SetCallBack(void (*PF)(void))
{
	if(PF !=NULL)
	{
		GP_Notification=PF;

	}

}


void __vector_10(void){

	if(GP_Notification !=NULL)
	{
		GP_Notification();

	}

}
void __vector_11(void){

	if(GP_Notification !=NULL)
	{
		GP_Notification();

	}

}

u8 T0_ReadTCNT0Value(void)
{

	return TCNT0_REG;
}









