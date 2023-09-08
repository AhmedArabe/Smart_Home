/***** Author : Alaa Gbr ****************************/
/***** SWC:     LED      ****************************/
/***** Date:    3/8/2023 ****************************/
/***** Version : 1.00    ****************************/
/****************************************************/

#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include"LED_Interface.h"

void LED_voidInit(LED_t *Copy_PstructLed)
{
	DIO_voidSetPinDirection(Copy_PstructLed->PORT,Copy_PstructLed->PIN,DIO_OUTPUT);

	switch(Copy_PstructLed->ActiveState)
	{

	case ACTIVE_HIGH:
		DIO_voidSetPinValue(Copy_PstructLed->PORT,Copy_PstructLed->PIN,DIO_LOW);
		break;

	case ACTIVE_LOW:
		DIO_voidSetPinValue(Copy_PstructLed->PORT,Copy_PstructLed->PIN,DIO_HIGH);
		break;


	}
}

	void LED_ON(LED_t *Copy_PstructLed)
	{

		switch(Copy_PstructLed->ActiveState)
		{

		case ACTIVE_HIGH:
			DIO_voidSetPinValue(Copy_PstructLed->PORT,Copy_PstructLed->PIN,DIO_HIGH);
			break;

		case ACTIVE_LOW:
			DIO_voidSetPinValue(Copy_PstructLed->PORT,Copy_PstructLed->PIN,DIO_LOW);
			break;


		}

	}

	void LED_OFF(LED_t *Copy_PstructLed)
	{

		switch(Copy_PstructLed->ActiveState)
				{

				case ACTIVE_HIGH:
					DIO_voidSetPinValue(Copy_PstructLed->PORT,Copy_PstructLed->PIN,DIO_LOW);
					break;

				case ACTIVE_LOW:
					DIO_voidSetPinValue(Copy_PstructLed->PORT,Copy_PstructLed->PIN,DIO_HIGH);
					break;


				}



	}










