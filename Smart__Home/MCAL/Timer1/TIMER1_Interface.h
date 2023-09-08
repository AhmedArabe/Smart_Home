/*
 * TIMER1_Interface.h
 *
 *  Created on: Aug 17, 2023
 *      Author: WIN10
 */

#ifndef MCAL_TIMER1_TIMER1_INTERFACE_H_
#define MCAL_TIMER1_TIMER1_INTERFACE_H_

typedef enum{
	T1_NORMAL_MODE,
	T1_PHASE_8bit_PWM_MODE,
	T1_PHASE_9bit_PWM_MODE,
	T1_PHASE_10bit_PWM_MODE,
	T1_CTC1_MODE,
	T1_FAST_PWM_8bit,
	T1_FAST_PWM_9bit,
	T1_FAST_PWM_10bit,
	T1_PHASE_FREQ_Correct1_MODE,
	T1_PHASE_FREQ_Correct2_MODE,
	T1_PHASE_Correct1_MODE,
	T1_PHASE_Correct2_MODE,
	T1_CTC2_MODE,
	T1_Reserved,
	T1_FAST_PWM_1,
	T1_FAST_PWM_2


}TIMER1_WaveForm_Mode_t;

typedef enum{
	T1_CTC_OC1A_DISCONNECTED,
	T1_CTC_OC1A_TOGGLE,
	T1_CTC_OC1A_CLEAR,
	T1_CTC_OC1A_SET
}CTC_NOPWM_OC1A_Mode_t;
typedef enum{
	T1_CTC_OC1B_DISCONNECTED,
	T1_CTC_OC1B_TOGGLE,
	T1_CTC_OC1B_CLEAR,
	T1_CTC_OC1B_SET
}CTC_NOPWM_OC1B_Mode_t;


typedef enum
{
	T1_FAST_OC1A_DISCONNECTED,
	T1_FAST_OC1A_CLEAR=2,
	T1_FAST_OC1A_SET
}FASTPWM_OC1A_Mode_t;
typedef enum
{
	T1_FAST_OC1B_DISCONNECTED,
	T1_FAST_OC1B_CLEAR=2,
	T1_FAST_OC1B_SET
}FASTPWM_OC1B_Mode_t;

typedef enum
{
	T1_PHASE_OC1A_DISCONNECTED,
	T1_PHASE_OC1A_CLEAR=2,  //clear when up counting -- set when down counting
	T1_PHASE_OC1A_SET		  //set when up counting -- clear when down counting
}PHASE_CORRECT_PWM_OC1A_Mode_t;
typedef enum
{
	T1_PHASE_OC1B_DISCONNECTED,
	T1_PHASE_OC1B_CLEAR=2,  //clear when up counting -- set when down counting
	T1_PHASE_OC1B_SET		  //set when up counting -- clear when down counting
}PHASE_CORRECT_PWM_OC1B_Mode_t;

typedef enum
{
	T1_NO_CLK,
	T1_CLK_FCPU,
	T1_CLK_FCPU_8,
	T1_CLK_FCPU_64,
	T1_CLK_FCPU_256,
	T1_CLK_FCPU_1024,
	T1_CLK_EXT_FALLING_EDGE,
	T1_CLK_EXT_RISING_EDGE

}T1_CLOCK_MODE_t;
typedef enum{
	T1_Polling , T1_Interrupt
}TIMER1_Technique_t;

typedef enum
{
	T1_ChannelA,T1_ChannelB
}TIMER1_Channel;


typedef struct
{
	TIMER1_WaveForm_Mode_t T1_WF_MODE;
	TIMER1_Channel         T1_Channel;
	CTC_NOPWM_OC1A_Mode_t T1_CTC_OC1A;
	CTC_NOPWM_OC1B_Mode_t T1_CTC_OC1B;
	FASTPWM_OC1A_Mode_t   T1_FASTPWM_OC1A;
	FASTPWM_OC1B_Mode_t   T1_FASTPWM_OC1B;
	PHASE_CORRECT_PWM_OC1A_Mode_t T1_PHASE_OC1A;
	PHASE_CORRECT_PWM_OC1B_Mode_t T1_PHASE_OC1B;
	T1_CLOCK_MODE_t T1_CLOCK_MODE;
	TIMER1_Technique_t T1_TECHNIQUE;
	u16 T1_Preload_value;
	u16 T1_Compare_value;

}TIMER1_CONFIG;



void T1_voidInit(TIMER1_CONFIG *Ptr_Str);
void T1_voidStartTimer(TIMER1_CONFIG *Ptr_Str);


void T1_SetCallBack(void (*PF)(void));

void T1_voidSetCompareValueT1A(u16 Copy_u16CompareValue);
void T1_voidSetCompareValueT1B(u16 Copy_u16CompareValue);


void T1_voidSet_ICRValue(u16 Copy_u16ICR_VALUE);

u16 T1_ReadTCNT1Value(void);
void T1_WriteTCNT1A(u16 Copy_u8TCNTVal);



#endif /* MCAL_TIMER1_TIMER1_INTERFACE_H_ */
