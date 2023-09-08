/***** Author : Alaa Gbr ****************************/
/***** SWC:     LED      ****************************/
/***** Date:    3/8/2023 ****************************/
/***** Version : 1.00    ****************************/
/****************************************************/

#ifndef LED_LED_INTERFACE_H_
#define LED_LED_INTERFACE_H_

typedef struct
{
	u8 PORT;
	u8 PIN;
	u8 ActiveState;


}LED_t;

#define ACTIVE_HIGH 1
#define ACTIVE_LOW  0

void LED_voidInit(LED_t *Copy_PstructLed);
void LED_ON(LED_t *Copy_PstructLed);
void LED_OFF(LED_t *Copy_PstructLed);

#endif /* LED_LED_INTERFACE_H_ */
