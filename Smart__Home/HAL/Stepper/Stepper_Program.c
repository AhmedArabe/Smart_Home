/****************************************************/
/***** Author : Alaa Gbr ****************************/
/***** SWC:     Stepper  ****************************/
/***** Date:    8/8/2023 ****************************/
/***** Version : 1.00    ****************************/
/****************************************************/

#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/DIO/DIO_Interface.h"

#include"Stepper_Interface.h"
#include"Stepper_Config.h"
#include"Stepper_Private.h"
#include <util/delay.h>


void Stepper_voidInit()
{
	DIO_voidSetPinDirection(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(STEPPER_PORT,STEPPER_Pink_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(STEPPER_PORT,STEPPER_Orange_PIN,DIO_OUTPUT);


		DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_LOW);
		DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_LOW);
		DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_LOW);
		DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_LOW);


}
void Stepper_voidON(u8 Copy_u8StepMode,u8 Copy_u8Direction,u16 Copy_u16Degree)
{

	u16 Local_u16Counter;

	if(Copy_u8StepMode==STEPPER_FULL_STEP)
	{
		if(Copy_u8Direction==STEPPER_ClockWise)
		{
			for(Local_u16Counter=0;Local_u16Counter<((64*Copy_u16Degree)/45);Local_u16Counter++)
			{

				Stepper_ClockWise_FullStep();
			}


		}else if(Copy_u8Direction==STEPPER_CounterClockWise)
		{
			for(Local_u16Counter=0;Local_u16Counter<((64*Copy_u16Degree)/45);Local_u16Counter++)
			{

				Stepper_CounterClockWise_FullStep();
			}

		}



	}
	else if(Copy_u8StepMode==STEPPER_HALF_STEP)
	{
		if(Copy_u8Direction==STEPPER_ClockWise)
		{
			for(Local_u16Counter=0;Local_u16Counter<((32*Copy_u16Degree)/45);Local_u16Counter++)
			{

				Stepper_ClockWise_HalfStep();
			}


		}else if(Copy_u8Direction==STEPPER_CounterClockWise)
		{
			for(Local_u16Counter=0;Local_u16Counter<((32*Copy_u16Degree)/45);Local_u16Counter++)
			{

				Stepper_CounterClockWise_HalfStep();
			}

		}


	}
}


void Stepper_ClockWise_FullStep()
{
	//Step1
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_HIGH);
	_delay_ms(freq);

	//Step2
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_HIGH);
	_delay_ms(freq);


	//Step3
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_HIGH);
	_delay_ms(freq);


	//Step4
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_LOW);
	_delay_ms(freq);



}
void Stepper_CounterClockWise_FullStep()
{

	//Step1
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_HIGH);
	_delay_ms(freq);

	//Step2
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_LOW);
	_delay_ms(freq);

	//Step3
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_LOW);
	_delay_ms(freq);

	//Step4
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_LOW);
	_delay_ms(freq);
}


void Stepper_ClockWise_HalfStep()
{
	//Step1
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_HIGH);
	_delay_ms(freq);

	//Step2
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_LOW);
	_delay_ms(freq);



	//Step3
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_LOW);
	_delay_ms(freq);


	//Step4
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_LOW);
	_delay_ms(freq);


	//Step5
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_LOW);
	_delay_ms(freq);

	//Step6
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_LOW);
	_delay_ms(freq);




	//Step7
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_HIGH);
	_delay_ms(freq);



	//Step8
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_HIGH);
	_delay_ms(freq);






}
void Stepper_CounterClockWise_HalfStep()
{

	//Step1
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_HIGH);
	_delay_ms(freq);


	//Step2
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_LOW);
	_delay_ms(freq);

	//Step3
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_LOW);
	_delay_ms(freq);


	//Step4
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_LOW);
	_delay_ms(freq);

	//Step5
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_LOW);
	_delay_ms(freq);


	//Step6
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_LOW);
	_delay_ms(freq);


	//Step7
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_HIGH);
	_delay_ms(freq);


	//Step8
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Pink_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Yellow_PIN,DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT,STEPPER_Orange_PIN,DIO_HIGH);
	_delay_ms(freq);







}
