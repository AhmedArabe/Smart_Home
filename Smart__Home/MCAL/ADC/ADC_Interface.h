/*
 * ADC_Interface.h
 *
 *  Created on: Aug 12, 2023
 *      Author: WIN10
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#include"ADC_Config.h"

/*ADC Channel Select*/
#define ADC_Channel_0   0
#define ADC_Channel_1   1
#define ADC_Channel_2   2
#define ADC_Channel_3   3
#define ADC_Channel_4   4
#define ADC_Channel_5   5
#define ADC_Channel_6   6
#define ADC_Channel_7   7

/* ADC Voltage Select*/
#define ADC_AREF  			0
#define ADC_AVCC_Cap		1
#define ADC_Internal_volt	2


/* ADC Mode Select */
#define ADC_Auto_Trigger   			0
#define ADC_Single_Conversion		1

/* ADC Adjust Select */
#define ADC_Left_Adjust				0
#define ADC_Right_Adjust			1







void ADC_voidInit(u8 Copy_u8ADC_V_Mode	,	u8 Copy_u8ADC_Mode	,	u8 Copy_u8ADC_Adjust);

void ADC_voidStartConversion(u8 Copy_u8ADC_Channel);

u16 ADC_voidRead();



#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
