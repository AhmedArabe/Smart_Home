/*
 * UART_Program.c
 *
 *  Created on: Aug 20, 2023
 *      Author: WIN10
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include"UART_Interface.h"
#include"UART_Private.h"
#include"UART_Config.h"

//static void (*GP_Notification) (void) = NULL;

u8 Dummy_SendData=0,Dummy_RecieveData;

void __vector_13(void) __attribute__((signal));
void __vector_14(void) __attribute__((signal));

void UART_voidInit(UART_Parity_Mode Parity_Mode,UART_Stop_Bit Stop_bits,UART_Data_size Data_size,u16 Baud_Rate)
{
	u16 BAUD_PRESCALE =(((8000000 / (Baud_Rate * 16UL))) - 1);


	/* Enable receiver and transmitter */
	SET_BIT(UCSRB_REG,TXEN);
	SET_BIT(UCSRB_REG,RXEN);


	/* Set frame format: data,parity ,stop bit */
	CLR_BIT(UCSRC_REG,UMSEL);  //ASync

	/*parity Mode*/
	UCSRC_REG &= 0xCF;
	UCSRC_REG |= (Parity_Mode<<4);

	/*Stop Bits*/
	UCSRC_REG &= 0xF7;
	UCSRC_REG |= (Stop_bits<<3);

	/*Data Size*/
	UCSRC_REG &= 0xF9;
	UCSRC_REG |= (Data_size<<1);
	UCSRB_REG &= 0xFB;
	UCSRB_REG |= (Data_size);


	/* Set baud rate */
	UBRRH_REG= (BAUD_PRESCALE>>8);
	UBRRL_REG=BAUD_PRESCALE;



}
void UART_voidSendDataSync(u8 Copy_u8UARTData)
{

	/* Wait for empty transmit buffer */
	while(GET_BIT(UCSRA_REG,UDRE)==0);
	/* Put data into buffer, sends the data */
	UDR_REG = Copy_u8UARTData;

}
u8 UART_u8ReciveDataSync()
{
	while(GET_BIT(UCSRA_REG,RXC)==0);


	return UDR_REG;
}
void UART_voidSendStringSync(u8 *str)
{

	u8 i=0;


	while(str[i]!='.' &&str[i]!='\0')
	{
		UART_voidSendDataSync(str[i]);
		i++;
	}

}
void UART_voidreceiveStringSync(u8  *str)
{
	u8 i=0;

	while(str[i-1]!=13)
	{

		str[i]=UART_u8ReciveDataSync();
	//	UART_voidSendDataSync(str[i]);
		CLCD_voidSendData(str[i]);
		i++;
	}
	str[i-1]='\0';
}

void UART_voidSendDataASync(u8 Copy_u8UARTData)
{

	/*Enable PIE*/
	SET_BIT(UCSRB_REG,UDRIE);

	/* Put data into buffer, sends the data */
	Dummy_SendData = Copy_u8UARTData;
}
u8 UART_u8ReciveDataASync()
{

	/*Enable PIE*/
	SET_BIT(UCSRB_REG,RXCIE);
return Dummy_RecieveData;



}

void __vector_14(void)
{


	UDR_REG = Dummy_SendData;
	CLR_BIT(UCSRB_REG,UDRIE);

}
void __vector_13(void)
{

	Dummy_RecieveData = UDR_REG;
}




