//AUTHOR	:Mohamed Gamal
//VERSION	:V01
//DATE		:8-August-2020

/*Include Guard*/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*Macro definitions*/
#define RCC_AHB     0
#define RCC_APB1    1
#define RCC_APB2    2
/*
#define RCC_CLOCk_MODE      INTERNAL_OSC
#define PLL_MODE            PLL_DISABLED
#define PLL_MULT_FACTOR     2
#define CSS_MODE            CSS_OFF
*/

/*Functions Prototypes*/
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidClockInit(void);

#endif // RCC_INTERFACE_H
