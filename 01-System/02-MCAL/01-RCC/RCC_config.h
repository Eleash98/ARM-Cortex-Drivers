//AUTHOR	:Mohamed Gamal
//VERSION	:V01
//DATE		:8-August-2020

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*options:  RCC_HSE_CRYSTAL
            RCC_HSE_RC
            RCC_HSI
            RCC_PLL             */
#define RCC_CLOCK_TYPE    RCC_HSE_CRYSTAL

/* Options:		RCC_PLL_IN_HSI_DIV_2
				RCC_PLL_IN_HSE			*/

#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT	RCC_PLL_IN_HSE

/*Options1:	TRUE
			FALSE
Options:	CRYSTAL
			RC 					*/
#if RCC_CLOCK_TYPE == RCC_PLL_IN_HSE
	#define RCC_PLL_HSE_DIV_2	TRUE
	#define RCC_PLL_HSE_TYPE	CRYSTAL
#endif

/*Options:	2-16*/
#define RCC_MUL_VAL		2
#endif


#endif // RCC_CONFIG_H
