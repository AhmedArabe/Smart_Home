/*
 * ADC_Program.c
 *
 *  Created on: Aug 12, 2023
 *      Author: WIN10
 */


#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/DIO/DIO_Interface.h"

#include"ADC_Interface.h"
#include"ADC_Private.h"






void ADC_voidInit(u8 Copy_u8ADC_V_Mode	,	u8 Copy_u8ADC_Mode	,	u8 Copy_u8ADC_Adjust)
{


	//Select Division Factor 64
	CLR_BIT(ADCSRA_REG,0);
	SET_BIT(ADCSRA_REG,1);
	SET_BIT(ADCSRA_REG,2);

	switch(Copy_u8ADC_V_Mode)
	{
	case ADC_AREF:
		CLR_BIT(ADMUX_REG,7);
		CLR_BIT(ADMUX_REG,6);

		break;

	case ADC_AVCC_Cap:
		CLR_BIT(ADMUX_REG,7);
		SET_BIT(ADMUX_REG,6);

		break;


	case ADC_Internal_volt:
		SET_BIT(ADMUX_REG,7);
		SET_BIT(ADMUX_REG,6);
		break;


	}

	switch(Copy_u8ADC_Mode)
	{

	case ADC_Auto_Trigger:

		SET_BIT(ADCSRA_REG,5);

		break;


	case ADC_Single_Conversion:
		CLR_BIT(ADCSRA_REG,5);
		break;

	}


	switch(Copy_u8ADC_Adjust)
	{

	case ADC_Left_Adjust:
		SET_BIT(ADMUX_REG,5);

		break;


	case ADC_Right_Adjust:
		CLR_BIT(ADMUX_REG,5);
		break;
	}

	//Enable ADC
	SET_BIT(ADCSRA_REG,7);






}

void ADC_voidStartConversion(u8 Copy_u8ADC_Channel)
{


	//Select Channel
	switch(Copy_u8ADC_Channel)
	{

	case ADC_Channel_0:

		CLR_BIT(ADMUX_REG,0);
		CLR_BIT(ADMUX_REG,1);
		CLR_BIT(ADMUX_REG,2);

		break;


	case ADC_Channel_1:
		SET_BIT(ADMUX_REG,0);
		CLR_BIT(ADMUX_REG,1);
		CLR_BIT(ADMUX_REG,2);

		break;

	case ADC_Channel_2:

		CLR_BIT(ADMUX_REG,0);
		SET_BIT(ADMUX_REG,1);
		CLR_BIT(ADMUX_REG,2);

		break;

	case ADC_Channel_3:

		SET_BIT(ADMUX_REG,0);
		SET_BIT(ADMUX_REG,1);
		CLR_BIT(ADMUX_REG,2);

		break;
	case ADC_Channel_4:


		CLR_BIT(ADMUX_REG,0);
		CLR_BIT(ADMUX_REG,1);
		SET_BIT(ADMUX_REG,2);
		break;
	case ADC_Channel_5:
		SET_BIT(ADMUX_REG,0);
		CLR_BIT(ADMUX_REG,1);
		SET_BIT(ADMUX_REG,2);

		break;

	case ADC_Channel_6:

		CLR_BIT(ADMUX_REG,0);
		SET_BIT(ADMUX_REG,1);
		SET_BIT(ADMUX_REG,2);

		break;



	case ADC_Channel_7:
		SET_BIT(ADMUX_REG,0);
		SET_BIT(ADMUX_REG,1);
		SET_BIT(ADMUX_REG,2);

		break;
	}

	//Single Conversion Start
	SET_BIT(ADCSRA_REG,6);


}

u16 ADC_voidRead(){

	u16 Local_Data;
	//wait for end of conversion
	while(GET_BIT(ADCSRA_REG,4)!=1);

	//clear flag
	SET_BIT(ADCSRA_REG,4);

	if(GET_BIT(ADMUX_REG,5)==0)
	{
		Local_Data =ADCLH_REG;

	}else
	{
		Local_Data=(ADCL_REG>>6);
		Local_Data|=(ADCH_REG<<2);
	}


	//return data stored
	return Local_Data;

}

