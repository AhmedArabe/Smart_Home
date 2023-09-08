/***** Author : Alaa Gbr ****************************/
/***** SWC:Seven_Segment ****************************/
/***** Date:    3/8/2023 ****************************/
/***** Version : 1.00    ****************************/
/****************************************************/


#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include"SSD_Interface.h"
#include"SSD_Private.h"



void SSD_voidInit(SSD_t *Copy_PstructLed)
{
	DIO_voidSetPortDirection(Copy_PstructLed->PORT,DIO_OUTPUT);

		switch(Copy_PstructLed->CommanState)
			{
			case Comman_Cathod:
				DIO_voidSetPortValue(Copy_PstructLed->PORT,0x00);
				break;

			case Comman_Anode:
					DIO_voidSetPortValue(Copy_PstructLed->PORT,0xFF);
					break;
			}

}
void SSD_Display(SSD_t *Copy_PstructLed,u8 num)
{
	switch(Copy_PstructLed->CommanState)
	{
	case Comman_Cathod:
		DIO_voidSetPortValue(Copy_PstructLed->PORT,~arr[num]);
		break;

	case Comman_Anode:
			DIO_voidSetPortValue(Copy_PstructLed->PORT,arr[num]);
			break;
	}


}
void SSD_Disable(SSD_t *Copy_PstructLed)
{
	switch(Copy_PstructLed->CommanState)
		{
		case Comman_Cathod:
			DIO_voidSetPortValue(Copy_PstructLed->PORT,0x00);
			break;

		case Comman_Anode:
				DIO_voidSetPortValue(Copy_PstructLed->PORT,0xFF);
				break;
		}


}
