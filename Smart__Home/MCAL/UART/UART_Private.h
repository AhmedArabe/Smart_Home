/*
 * UART_Private.h
 *
 *  Created on: Aug 20, 2023
 *      Author: WIN10
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_


#define UDR_REG        *((volatile u8*)0x2C)
#define	UCSRA_REG      *((volatile u8*)0x2B)
#define	UCSRB_REG      *((volatile u8*)0x2A)
#define	UCSRC_REG      *((volatile u8*)0x40)
#define UBRRH_REG	   *((volatile u8*)0x40)
#define UBRRL_REG	   *((volatile u8*)0x29)

//UCSRA_REG
#define MPCM	  	0
#define U2X     	1
#define PE     		2
#define DOR         3
#define FE          4
#define UDRE        5
#define TXC         6
#define RXC         7

//UCSRB_REG
#define TXB8	  	0
#define RXB8     	1
#define UCSZ2    	2
#define TXEN        3
#define RXEN        4
#define UDRIE       5
#define TXCIE       6
#define RXCIE       7





//UCSRC_REG
#define UCPOL	  	0
#define UCSZ0   	1
#define UCSZ1    	2
#define USBS        3
#define UPM0        4
#define UPM1        5
#define UMSEL       6
#define URSEL       7












#endif /* MCAL_UART_UART_PRIVATE_H_ */
