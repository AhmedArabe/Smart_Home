/*
 * UART_Interface.h
 *
 *  Created on: Aug 20, 2023
 *      Author: WIN10
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

typedef enum
{
	Parity_Disabled,
	Reserved,
	Parity_Even,
	Parity_Odd
}UART_Parity_Mode;

typedef enum
{
	one_stop_bit,
	two_stop_bit

}UART_Stop_Bit;

typedef enum
{
	five_bits,
	six_bits,
	seven_bits,
	eight_bits,
	reserved1,
	reserved2,
	reserved3,
	nine_bits
}UART_Data_size;


/*BaudRate Options*/
/* 2400 - 4800 - 9600 - 14400 - 19200 - 28800 - 38400 - 57600   */



void UART_voidInit(UART_Parity_Mode Parity_Mode,UART_Stop_Bit Stop_bits,UART_Data_size Data_size,u16 Baud_Rate);
void UART_voidSendDataSync(u8 Copy_u8UARTData);
u8 UART_u8ReciveDataSync();
void UART_voidSendStringSync();
void UART_voidreceiveStringSync(u8  *str);

void UART_voidSendDataASync(u8 Copy_u8UARTData);
u8 UART_u8ReciveDataASync();

void UART_SetCallBack(void (*PF)(void));

#endif /* MCAL_UART_UART_INTERFACE_H_ */
