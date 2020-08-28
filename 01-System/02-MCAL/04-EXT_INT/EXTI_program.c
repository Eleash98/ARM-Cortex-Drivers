//Author	:		Mohamed Gamal
//Date		:		22 August 2020
//Version	:		V01

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

void MEXTI_voidInit(){
	#if 	EXTI_MODE == RISING
		SET_BIT((EXTI->RTSR),EXT_LINE);
	#elif	EXT_MODE == FALLING
		SET_BIT((EXTI->FTSR),EXT_LINE);
	#elif 	EXT_MODE == ON_CHANGE
		SET_BIT((EXTI->RTSR),EXT_LINE);
		SET_BIT((EXTI->FTSR),EXT_LINE);
	#else 
		#error "Wrong MODE OR LINE !!"
	#endif
	/*disable interrupt*/
	CLR_BIT(EXT->IMR,Copy_u8Line);
}
void MEXTI_voidEnableEXTI(u8 Copy_u8Line){
	SET_BIT(EXT->IMR, Copy_u8Line);
}

void MEXTI_voidDisableEXTI(u8 Copy_u8Line){
	CLR_BIT(EXT->IMR,Copy_u8Line);
}

void MEXTI_voidSwTrigger(u8 Copy_u8Line){
	SET_BIT(EXT->IMR,Copy_u8Line);
	SET_BIT(EXT->SWIER,Copy_u8Line);
}

void MEXTI_voidSetSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode){
	switch (Copy_u8Mode){
		case RISING		:	SET_BIT(EXT->RTSR, Copy_u8Line); break;
		case FALLING	:	SET_BIT(EXT->FTSR, Copy_u8Line); break;
		case ON_CHANGE	:	SET_BIT(EXT->RTSR, Copy_u8Line);
							SET_BIT(EXT->FTSR, Copy_u8Line); break;
		default:	/*return error*/	break;
}
