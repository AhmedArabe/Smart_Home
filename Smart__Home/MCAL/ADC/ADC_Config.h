/*
 * ADC_Config.h
 *
 *  Created on: Aug 12, 2023
 *      Author: WIN10
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

//Options : ADC_Channel_0 -> ADC_Channel_7

#define ADC_Channel   ADC_Channel_4


//Options :ADC_AREF  || ADC_AVCC_Cap || ADC_Internal_volt

#define ADC_V_Mode    ADC_AVCC_Cap


//Options :ADC_Single_Conbversion  ||	ADC_Auto_Trigger
#define ADC_Mode    ADC_Single_Conversion


//Options :ADC_Right_Adjust || ADC_Left_Adjust
#define ADC_Adjust   ADC_Right_Adjust



#endif /* MCAL_ADC_ADC_CONFIG_H_ */
