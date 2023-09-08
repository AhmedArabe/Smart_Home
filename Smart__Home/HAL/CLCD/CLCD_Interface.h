/****************************************************/
/***** Author : Alaa Gbr ****************************/
/***** SWC:     CLCD     ****************************/
/***** Date:    5/8/2023 ****************************/
/***** Version : 1.00    ****************************/
/****************************************************/

#ifndef HAL_CLCD_CLCD_INTERFACE_H_
#define HAL_CLCD_CLCD_INTERFACE_H_

void CLCD_voidInit();
void CLCD_voidSendCommand (u8 Copy_u8Command);
void CLCD_voidSendData (u8 Copy_u8Data);
void CLCD_voidGOTO(u8 Copy_u8X,u8 Copy_u8Y);
void CLCD_CLEAR();
void CLCD_voidCreateExtraChar(u8 Copy_u8PatternNum,u8 *Copy_pu8ExtraChar);
void CLCD_voidSendString(u8 * Copy_u8pu8Array);
void CLCD_voidSendNumber(u32 Copy_u32Num,u8 Copy_u8X,u8 Copy_u8Y);

//CLCD_Commands
#define CLCD_CLR  0x01
#define Shift_Text_Left  0b00011000
#define Shift_Text_Right  0b00011100

#endif /* HAL_CLCD_CLCD_INTERFACE_H_ */
