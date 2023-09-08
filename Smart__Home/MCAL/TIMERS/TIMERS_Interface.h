/*
 * TIMERS_Interface.h
 *
 *  Created on: Aug 15, 2023
 *      Author: WIN10
 */

#ifndef MCAL_TIMERS_TIMERS_INTERFACE_H_
#define MCAL_TIMERS_TIMERS_INTERFACE_H_

typedef enum{
	NORMAL_MODE,
	PHASE_PWM_MODE,
	CTC_MODE,
	FAST_PWM
}TIMER0_WaveForm_Mode_t;

typedef enum{
	CTC_OC0_DISCONNECTED,
	CTC_OC0_TOGGLE,
	CTC_OC0_CLEAR,
	CTC_OC0_SET
}CTC_NOPWM_OC0_Mode_t;

typedef enum
{
	FAST_OC0_DISCONNECTED,
	FAST_OC0_CLEAR=2,
	FAST_OC0_SET


}FASTPWM_OC0_Mode_t;

typedef enum
{
	PHASE_OC0_DISCONNECTED,
	PHASE_OC0_CLEAR=2,  //clear when up counting -- set when down counting
	PHASE_OC0_SET		  //set when up counting -- clear when down counting
}PHASE_CORRECT_PWM_OC0_Mode_t;

typedef enum
{
	NO_CLK,
	CLK_FCPU,
	CLK_FCPU_8,
	CLK_FCPU_64,
	CLK_FCPU_256,
	CLK_FCPU_1024,
	CLK_EXT_FALLING_EDGE,
	CLK_EXT_RISING_EDGE

}CLOCK_MODE_t;
typedef enum{
	Polling , Interrupt
}TIMER0_Technique_t;


typedef struct
{
	TIMER0_WaveForm_Mode_t WF_MODE;
	CTC_NOPWM_OC0_Mode_t CTC_OC0;
	FASTPWM_OC0_Mode_t   FASTPWM_OC0;
	PHASE_CORRECT_PWM_OC0_Mode_t PHASE_OC0;
	CLOCK_MODE_t CLOCK_MODE;
	TIMER0_Technique_t TECHNIQUE;
	u8 Preload_value;
	u8 Compare_value;

}TIMER0_CONFIG;

void T0_voidInit(TIMER0_CONFIG *Ptr_Str);
void T0_voidStartTimer(TIMER0_CONFIG *Ptr_Str);

void T1_voidSetCompareValueT1A(u16 Copy_u16CompareValue);
void T1_voidSet_ICRValue(u16 Copy_u16ICR_VALUE);
void T1_voidInit();

void T0_SetCallBack(void (*PF)(void));









#endif /* MCAL_TIMERS_TIMERS_INTERFACE_H_ */
