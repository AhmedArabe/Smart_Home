/****************************************************/
/***** Author : Alaa Gbr ****************************/
/***** SWC:     KeyPad   ****************************/
/***** Date:    6/8/2023 ****************************/
/***** Version : 1.00    ****************************/
/****************************************************/

#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/DIO/DIO_Interface.h"

#include"KPAD_Interface.h"
#include"KPAD_Config.h"
#include"KPAD_Private.h"
#include <util/delay.h>




void KPAD_voidInit()
{
	//SET COL PINS OUTPUT
	DIO_voidSetPinDirection(KPAD_PORT,KPAD_Col1_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(KPAD_PORT,KPAD_Col2_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(KPAD_PORT,KPAD_Col3_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(KPAD_PORT,KPAD_Col4_PIN,DIO_OUTPUT);

	//SET ROW PINS INPUT
	DIO_voidSetPinDirection(KPAD_PORT,KPAD_Row1_PIN,DIO_INPUT);
	DIO_voidSetPinDirection(KPAD_PORT,KPAD_Row2_PIN,DIO_INPUT);
	DIO_voidSetPinDirection(KPAD_PORT,KPAD_Row3_PIN,DIO_INPUT);
	DIO_voidSetPinDirection(KPAD_PORT,KPAD_Row4_PIN,DIO_INPUT);


	//SET INTIAL PORT VALUE TO 1
	DIO_voidSetPortValue(KPAD_PORT,0xFF);



}
u8 KPAD_u8GetKeyPressed()
{

	_delay_ms(50);
	u8 Local_u8KeyPressed=NOT_Pressed;

	for(u8 col_index=0;col_index<KPAD_NUM_COLS;col_index++)
	{

		DIO_voidSetPinValue(KPAD_PORT,col_index,DIO_LOW);
		for(u8 row_index=4;row_index<8;row_index++)
		{


			if(DIO_u8GetPinValue(KPAD_PORT,row_index)==0){
				Local_u8KeyPressed=KPAD_KEYS[row_index-4][col_index];
				_delay_ms(50);
				while(DIO_u8GetPinValue(KPAD_PORT,row_index)==0);

			}else
			{


			}


		}
		DIO_voidSetPinValue(KPAD_PORT,col_index,DIO_HIGH);


	}

	return Local_u8KeyPressed;

}

