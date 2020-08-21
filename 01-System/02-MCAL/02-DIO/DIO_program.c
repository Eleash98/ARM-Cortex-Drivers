//AUTHOR	:Mohamed Gamal
//VERSION	:V01
//DATE		:11-August-2020

//Version 	:V02
//Date		:17-August-2020
/* Added DIO_voidSetPortDirection, DIO_voidSetPortValue */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode){
	switch(Copy_u8Port){
		case DIO_PORTA:
			if (Copy_u8Pin<=7){
				DIO_PORTA_CRL &= ~((0b1111) << (Copy_u8Pin*4));
				DIO_PORTA_CRL |= (Copy_u8Mode) << (Copy_u8Pin*4));
			}
			else if (Copy_u8Pin <= 15){
				Copy_u8Pin -= 8;
				DIO_PORTA_CRH &= ~((0b1111) << (Copy_u8Pin*4));
				DIO_PORTA_CRH |= (Copy_u8Mode) << (Copy_u8Pin*4));
			}
			break;
		case DIO_PORTB:
			if (Copy_u8Pin<=7){
				DIO_PORTB_CRL &= ~((0b1111) << (Copy_u8Pin*4));
				DIO_PORTB_CRL |= (Copy_u8Mode) << (Copy_u8Pin*4));
			}
			else if (Copy_u8Pin <= 15){
				Copy_u8Pin -= 8;
				DIO_PORTB_CRH &= ~((0b1111) << (Copy_u8Pin*4));
				DIO_PORTB_CRH |= (Copy_u8Mode) << (Copy_u8Pin*4));
			}
			break;
		case DIO_PORTC:
			if (Copy_u8Pin<=7){
				DIO_PORTC_CRL &= ~((0b1111) << (Copy_u8Pin*4));
				DIO_PORTC_CRL |= (Copy_u8Mode) << (Copy_u8Pin*4));
			}
			else if (Copy_u8Pin <= 15){
				Copy_u8Pin -= 8;
				DIO_PORTC_CRH &= ~((0b1111) << (Copy_u8Pin*4));
				DIO_PORTC_CRH |= (Copy_u8Mode) << (Copy_u8Pin*4));
			}
			break;
		default: /*return error*/	break;
	}
}

void DIO_voidSetPin(u8 Copy_u8Port, u8 Copy_u8Pin){
	switch (Copy_u8Port){
		case DIO_PORTA:
			DIO_PORTA_BSRR	= (1 << Copy_u8Pin);
			break;
		case DIO_PORTB:
			DIO_PORTB_BSRR	= (1 << Copy_u8Pin);
			break;
		case DIO_PORTC:
			DIO_PORTC_BSRR	= (1 << Copy_u8Pin);
			break;
		default: break;
	}
}
void DIO_voidClearPin(u8 Copy_u8Port, u8 Copy_u8Pin){
	switch (Copy_u8Port){
		case DIO_PORTA:
			DIO_PORTA_BRR	= (1 << Copy_u8Pin);
			break;
		case DIO_PORTB:
			DIO_PORTB_BRR	= (1 << Copy_u8Pin);
			break;
		case DIO_PORTC:
			DIO_PORTC_BRR	= (1 << Copy_u8Pin);
			break;
		default: break;
	}
}


u8 DIO_voidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin){
	u8 LOC_u8Result = 0;
	switch (Copy_u8Port){
		case DIO_PORTA:
			LOC_u8Result = GET_BIT(DIO_PORTA_IDR,Copy_u8Pin);
			break;
		case DIO_PORTB:
			LOC_u8Result = GET_BIT(DIO_PORTB_IDR,Copy_u8Pin);
			break;
		case DIO_PORTC:
			LOC_u8Result = GET_BIT(DIO_PORTC_IDR,Copy_u8Pin);
			break;
		default:	break;
	}
	return LOC_u8Result;
}

void DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Mode){
	u32 LOC_u32Mode = 0;
	for (u8 i=0;i<7;i++)
		LOC_u32Mode = (LOC_u32Mode << 4) | Copy_u8Mode;
	switch(Copy_u8Port){
		case DIO_PORTA:
			DIO_PORTA &= 0xffff0000;
			DIO_PORTA_CRL |= LOC_u32Mode;
			break;
		case DIO_PORTB:
			DIO_PORTA &= 0xffff0000;
			DIO_PORTB_CRL |= LOC_u32Mode;
			break;
		case DIO_PORTC:
			DIO_PORTA &= 0xffff0000;
			DIO_PORTC_CRL |= LOC_u32Mode;
			break;
		default: /*return error*/ break;
	}
}
void DIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value){
	switch (Copy_u8Port){
		case DIO_PORTA:
			DIO_PORTA_ODR = Copy_u8Value;
			break;
		case DIO_PORTB:
			DIO_PORTB_ODR = Copy_u8Value;
			break;
		case DIO_PORTC:
			DIO_PORTC_ODR = Copy_u8Value;
			break;
		default: /*return error*/ break;
	}
}

void DIO_voidLockPin(u8 Copy_u8Port, u8 Copy_u8Pin){
	switch (Copy_u8Port){
		case DIO_PORTA:
			DIO_PORTA_LCKR	= (1 << Copy_u8Pin);
			break;
		case DIO_PORTB:
			DIO_PORTB_LCKR	= (1 << Copy_u8Pin);
			break;
		case DIO_PORTC:
			DIO_PORTC_LCKR	= (1 << Copy_u8Pin);
			break;
		default: break;
	}
}
void DIO_voidSetPullResistor(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode){
	switch (Copy_u8Port){
		case PORTA:
			Copy_u8Mode == PULL_UP ? DIO_PORTA_ODR |= (1<<Copy_u8Pin); : DIO_PORTA_ODR &= ~(1<<Copy_u8Pin);
			break;
		case PORTB:
			Copy_u8Mode == PULL_UP ? DIO_PORTB_ODR |= (1<<Copy_u8Pin); : DIO_PORTB_ODR &= ~(1<<Copy_u8Pin);
			break;
		case PORTC:
			Copy_u8Mode == PULL_UP ? DIO_PORTC_ODR |= (1<<Copy_u8Pin); : DIO_PORTC_ODR &= ~(1<<Copy_u8Pin);
			break;
		default:	/*return error*/ break;
	}
}