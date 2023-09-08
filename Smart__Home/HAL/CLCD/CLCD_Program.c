/****************************************************/
/***** Author : Alaa Gbr ****************************/
/***** SWC:     CLCD     ****************************/
/***** Date:    5/8/2023 ****************************/
/***** Version : 1.00    ****************************/
/****************************************************/


#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/DIO/DIO_Interface.h"

#include"CLCD_Interface.h"
#include"CLCD_Config.h"
#include"CLCD_Private.h"
#include <util/delay.h>

void CLCD_voidInit()
{
	//DATA PORT ->OUTPUT
	DIO_voidSetPortDirection(CLCD_DATA_PORT,DIO_OUTPUT);

	//RS-RW-EN -->OUTPUT

	DIO_voidSetPinDirection(CLCD_CONTROL_PORT,CLCD_RS,DIO_OUTPUT);
	DIO_voidSetPinDirection(CLCD_CONTROL_PORT,CLCD_RW,DIO_OUTPUT);
	DIO_voidSetPinDirection(CLCD_CONTROL_PORT,CLCD_E,DIO_OUTPUT);

	//Initialization Sequence:
	_delay_ms(50);

	//Function Set
	CLCD_voidSendCommand(0b00111000);
	_delay_us(50);


	//Display ON/OFF
	CLCD_voidSendCommand(0b00001110);
	_delay_us(50);

	//Display Clear
	CLCD_voidSendCommand(0x01);
	_delay_ms(2);

	//Entry Mode SET
	CLCD_voidSendCommand(0b00000110);


	//	End OF Initialization





}
void CLCD_voidSendCommand (u8 Copy_u8Command)
{
	/*Rs ->LOW (To Send Command)*/
	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RS,DIO_LOW);

	/*RW ->LOW (To Send Command)*/
		DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RW,DIO_LOW);

	/*Send Command*/
		DIO_voidSetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/*Enable Sequence*/

		DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_E,DIO_HIGH);
		_delay_us(1);
		DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_E,DIO_LOW);
		_delay_ms(10);
}
void CLCD_voidSendData (u8 Copy_u8Data)
{

	/*Rs ->HIGH (To Send DATA)*/
	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RS,DIO_HIGH);

	/*RW ->LOW (To Send Command)*/
		DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RW,DIO_LOW);

	/*Send Command*/
		DIO_voidSetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	/*Enable Sequence*/

		DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_E,DIO_HIGH);
		_delay_us(1);
		DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_E,DIO_LOW);
		_delay_ms(10);

}

void CLCD_voidGOTO(u8 Copy_u8X,u8 Copy_u8Y)
{
	switch(Copy_u8Y)
	{

	case 1:
		CLCD_voidSendCommand(0x80+Copy_u8X-1);
		break;

	case 2:
		CLCD_voidSendCommand(0xC0+Copy_u8X-1);
		break;

	default :
//	#error "max rows is 2";
		break;



	}
}

void CLCD_CLEAR()
{
CLCD_voidSendCommand(CLCD_CLR);

}

void CLCD_voidCreateExtraChar(u8 Copy_u8PatternLoctaion,u8 *Copy_pu8ExtraChar)
{
	u8 Local_u8Address = 0;
	Local_u8Address=Copy_u8PatternLoctaion*8;

	//Go To CGram
	CLCD_voidSendCommand(64+Local_u8Address);
	for(u8 i=0;i<8;i++)
	{
		CLCD_voidSendData(Copy_pu8ExtraChar[i]);
	}


}

void CLCD_voidSendString(u8 * Copy_u8pu8Array)
{
	u8 Local_u8Counter=0;
	while(Copy_u8pu8Array[Local_u8Counter] != '\0')
	{
		CLCD_voidSendData(Copy_u8pu8Array[Local_u8Counter]);

		Local_u8Counter++;

	}

}
void CLCD_voidSendNumber(u32 Copy_u32Num,u8 Copy_u8X,u8 Copy_u8Y)
{

	u8 Local_u8Rem=0,Local_u8Counter=0;
	u32 Local_u32Num=Copy_u32Num;


	do{

		Local_u32Num/=10;
		Local_u8Counter++;

	}
	while(Local_u32Num!=0);

	for(u8 i=Local_u8Counter;i>0;i--)
	{

		Local_u8Rem=Copy_u32Num%10;
		Copy_u32Num/=10;
		CLCD_voidGOTO(i+Copy_u8X,Copy_u8Y);
		CLCD_voidSendData((48+Local_u8Rem));


	}



}



