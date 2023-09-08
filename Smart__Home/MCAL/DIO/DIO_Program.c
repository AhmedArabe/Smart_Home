/****************************************************/
/***** Author : Alaa Gbr ****************************/
/***** SWC:     DIO      ******************O**********/
/***** Date:    3/8/2023 ****************************/
/***** Version : 1.00    ****************************/
/****************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


void DIO_voidSetPinDirection (u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8Direction)
{
	switch(Copy_u8Direction)
	{

	case DIO_OUTPUT:

		switch(Copy_u8PortId)
		{
		case DIO_PORTA:
			SET_BIT(DIO_DDRA_REG,Copy_u8PinId);
		break;

		case DIO_PORTB:
			SET_BIT(DIO_DDRB_REG,Copy_u8PinId);
		break;

		case DIO_PORTC:
			SET_BIT(DIO_DDRC_REG,Copy_u8PinId);
		break;


		case DIO_PORTD:
			SET_BIT(DIO_DDRD_REG,Copy_u8PinId);
		break;
		}
		break;


	case DIO_INPUT:

		switch(Copy_u8PortId)
				{
				case DIO_PORTA:
					CLR_BIT(DIO_DDRA_REG,Copy_u8PinId);
				break;

				case DIO_PORTB:
					CLR_BIT(DIO_DDRB_REG,Copy_u8PinId);
				break;

				case DIO_PORTC:
					CLR_BIT(DIO_DDRC_REG,Copy_u8PinId);
				break;


				case DIO_PORTD:
					CLR_BIT(DIO_DDRD_REG,Copy_u8PinId);
				break;
				}

		break;

	default:

		break;
	}

}




void DIO_voidSetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8Value)
{
	switch(Copy_u8Value)
		{

		case DIO_HIGH:

			switch(Copy_u8PortId)
			{
			case DIO_PORTA:
				SET_BIT(DIO_PORTA_REG,Copy_u8PinId);
			break;

			case DIO_PORTB:
				SET_BIT(DIO_PORTB_REG,Copy_u8PinId);
			break;

			case DIO_PORTC:
				SET_BIT(DIO_PORTC_REG,Copy_u8PinId);
			break;


			case DIO_PORTD:
				SET_BIT(DIO_PORTD_REG,Copy_u8PinId);
			break;
			}
			break;


		case DIO_LOW:

			switch(Copy_u8PortId)
					{
					case DIO_PORTA:
						CLR_BIT(DIO_PORTA_REG,Copy_u8PinId);
					break;

					case DIO_PORTB:
						CLR_BIT(DIO_PORTB_REG,Copy_u8PinId);
					break;

					case DIO_PORTC:
						CLR_BIT(DIO_PORTC_REG,Copy_u8PinId);
					break;


					case DIO_PORTD:
						CLR_BIT(DIO_PORTD_REG,Copy_u8PinId);
					break;
					}

			break;
		}


}


u8 DIO_u8GetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId)
{

	u8 Local_u8ReturnedValue=255;

		switch(Copy_u8PortId)
						{
						case DIO_PORTA:
						Local_u8ReturnedValue=GET_BIT(DIO_PINA_REG,Copy_u8PinId);
						break;

						case DIO_PORTB:
						Local_u8ReturnedValue=GET_BIT(DIO_PINB_REG,Copy_u8PinId);
						break;

						case DIO_PORTC:
						Local_u8ReturnedValue=GET_BIT(DIO_PINC_REG,Copy_u8PinId);
						break;


						case DIO_PORTD:
						Local_u8ReturnedValue=GET_BIT(DIO_PIND_REG,Copy_u8PinId);
						break;
						}



	return Local_u8ReturnedValue;
}


void DIO_voidSetPortDirection (u8 Copy_u8PortId,u8 Copy_u8Direction)
{
	switch(Copy_u8Direction)
	{

	case DIO_OUTPUT:

		switch(Copy_u8PortId)
		{
		case DIO_PORTA:
			DIO_DDRA_REG=DIO_PORT_OUTPUT;
			break;

		case DIO_PORTB:
			DIO_DDRB_REG=DIO_PORT_OUTPUT;
		break;

		case DIO_PORTC:
			DIO_DDRC_REG=DIO_PORT_OUTPUT;
		break;


		case DIO_PORTD:
			DIO_DDRD_REG=DIO_PORT_OUTPUT;
		break;
		}
		break;



	case DIO_INPUT:

		switch(Copy_u8PortId)
				{
				case DIO_PORTA:
					DIO_DDRA_REG=DIO_PORT_INPUT;
				break;

				case DIO_PORTB:
					DIO_DDRB_REG=DIO_PORT_INPUT;
				break;

				case DIO_PORTC:
					DIO_DDRC_REG=DIO_PORT_INPUT;
				break;


				case DIO_PORTD:
					DIO_DDRD_REG=DIO_PORT_INPUT;
				break;
				}
	}
}


void DIO_voidSetPortValue(u8 Copy_u8PortId,u8 Copy_u8Value)
{


			switch(Copy_u8PortId)
			{
			case DIO_PORTA:
				DIO_PORTA_REG=Copy_u8Value;
			break;

			case DIO_PORTB:
				DIO_PORTB_REG=Copy_u8Value;
			break;

			case DIO_PORTC:
				DIO_PORTC_REG=Copy_u8Value;
			break;


			case DIO_PORTD:
				DIO_PORTD_REG=Copy_u8Value;
			break;
			}

}




u8 DIO_u8GetPortValue(u8 Copy_u8PortId)
{

	u8 Local_u8ReturnedValue=255;

		switch(Copy_u8PortId)
						{
						case DIO_PORTA:
						Local_u8ReturnedValue=DIO_PINA_REG;
						break;

						case DIO_PORTB:
						Local_u8ReturnedValue=DIO_PINB_REG;
						break;

						case DIO_PORTC:
						Local_u8ReturnedValue=DIO_PINC_REG;
						break;


						case DIO_PORTD:
						Local_u8ReturnedValue=DIO_PIND_REG;
						break;
						}



	return Local_u8ReturnedValue;
}

