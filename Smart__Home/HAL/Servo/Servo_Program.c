/*
 * Servo_Program.c
 *
 *  Created on: Aug 16, 2023
 *      Author: WIN10
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/TIMER1/TIMER1_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"

#include "Servo_interface.h"

#include"../../MCAL/ADC/ADC_Interface.h"


TIMER1_CONFIG MyTimer={

		 .T1_WF_MODE = T1_FAST_PWM_1,
		 .T1_Channel = T1_ChannelA,
		 .T1_FASTPWM_OC1A=T1_FAST_OC1A_CLEAR,
		 .T1_TECHNIQUE=T1_Polling,
		 .T1_CLOCK_MODE=T1_CLK_FCPU_8

 };
void Servo_voidInit()
{


	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);
	T1_voidInit(&MyTimer);
	ADC_voidInit(ADC_AVCC_Cap,ADC_Single_Conversion,ADC_Right_Adjust);



}
void Servo_voidSetAngle(u16 Copy_u8Angle)
{
	u16 desired_angle;

	Copy_u8Angle+=90;
	desired_angle=((Copy_u8Angle*5.556)+1000);

	MyTimer.T1_Compare_value=desired_angle;
    T1_voidSet_ICRValue(20000);

	T1_voidStartTimer(&MyTimer);

}

void Servo_voidPot()
{


	u16 reading;
	ADC_voidStartConversion(ADC_Channel_4);
	reading=ADC_voidRead();
	Servo_voidSetAngle((reading/5.68)-90);


}

