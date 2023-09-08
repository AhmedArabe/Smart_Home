/****************************************************/
/***** Author : Alaa Gbr ****************************/
/***** SWC:     Stepper  ****************************/
/***** Date:    8/8/2023 ****************************/
/***** Version : 1.00    ****************************/
/****************************************************/

#ifndef HAL_STEPPER_STEPPER_INTERFACE_H_
#define HAL_STEPPER_STEPPER_INTERFACE_H_

#define STEPPER_FULL_STEP       0
#define STEPPER_HALF_STEP       1

#define STEPPER_ClockWise              0
#define STEPPER_CounterClockWise       1


void Stepper_voidInit();
void Stepper_voidON(u8 Copy_u8StepMode,u8 Copy_u8Direction,u16 Copy_u16Degree);
void Stepper_ClockWise_FullStep();
void Stepper_CounterClockWise_FullStep();

void Stepper_ClockWise_HalfStep();
void Stepper_CounterClockWise_HalfStep();



#endif /* HAL_STEPPER_STEPPER_INTERFACE_H_ */
