/****************************************************/
/***** Author : Alaa Gbr ****************************/
/***** SWC:     KeyPad   ****************************/
/***** Date:    6/8/2023 ****************************/
/***** Version : 1.00    ****************************/
/****************************************************/
#ifndef HAL_KPAD_KPAD_CONFIG_H_
#define HAL_KPAD_KPAD_CONFIG_H_

//Options 1-DIO_PORTA    1-DIO_PORTB    1-DIO_PORTC   1-DIO_PORTD

#define KPAD_PORT     DIO_PORTA


//Options 1-  DIO_PIN0 -> DIO_PIN7

#define KPAD_Col1_PIN  DIO_PIN0
#define KPAD_Col2_PIN  DIO_PIN1
#define KPAD_Col3_PIN  DIO_PIN2
#define KPAD_Col4_PIN  DIO_PIN3
#define KPAD_Row1_PIN  DIO_PIN4
#define KPAD_Row2_PIN  DIO_PIN5
#define KPAD_Row3_PIN  DIO_PIN6
#define KPAD_Row4_PIN  DIO_PIN7

#define KPAD_NUM_ROWS  4
#define KPAD_NUM_COLS  4
#define NOT_Pressed    0xFF

u8 KPAD_KEYS[KPAD_NUM_ROWS][KPAD_NUM_COLS]=
{
		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'c','0','=','+'}
};




#endif /* HAL_KPAD_KPAD_CONFIG_H_ */
