/***** Author : Alaa Gbr ****************************/
/***** SWC:Seven_Segment ****************************/
/***** Date:    3/8/2023 ****************************/
/***** Version : 1.00    ****************************/
/****************************************************/


#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_

typedef struct
{
	u8 PORT;
	u8 CommanState;


}SSD_t;

#define Comman_Cathod 1
#define Comman_Anode  0

void SSD_voidInit(SSD_t *Copy_PstructLed);
void SSD_Display(SSD_t *Copy_PstructLed,u8 num);
void SSD_Disable(SSD_t *Copy_PstructLed);




#endif /* HAL_SSD_SSD_INTERFACE_H_ */
