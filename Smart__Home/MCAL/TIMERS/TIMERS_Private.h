/*
 * TIMERS_private.h
 *
 *  Created on: Aug 15, 2023
 *      Author: First
 */

#ifndef MCAL_TIMERS_TIMERS_PRIVATE_H_
#define MCAL_TIMERS_TIMERS_PRIVATE_H_

#define TCCR0_REG		*((volatile u8*)0x53)
#define TCNT0_REG		*((volatile u8*)0x52)
#define OCR0_REG		*((volatile u8*)0x5C)

#define TIMSK_REG		*((volatile u8*)0x59)
#define TIFR_REG		*((volatile u8*)0x58)


#define TCCR1A_REG  *((volatile u8*)0x4F)
#define TCCR1B_REG  *((volatile u8*)0x4E)
#define TCNT1_REG   *((volatile u16*)0x4C)
#define OCR1A_REG   *((volatile u16*)0x4A)
#define OCR1B_REG   *((volatile u16*)0x48)
#define ICR1_REG    *((volatile u16*)0x46)


#define FOC0   		7
#define WGM00		6
#define COM01		5
#define COM00		4
#define WGM01 		3
#define	CS02		2
#define	CS01 		1
#define CS00		0



#endif /* MCAL_TIMERS_TIMERS_PRIVATE_H_ */
