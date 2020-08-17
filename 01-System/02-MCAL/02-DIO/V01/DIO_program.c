//AUTHOR	:Mohamed Gamal
//VERSION	:V01
//DATE		:11-August-2020
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

void DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value){
	switch (Copy_u8Port){
		case DIO_PORTA:
			if (Copy_u8Value == DIO_HIGH){
				SET_BIT(DIO_PORTA_ODR, Copy_u8Pin);
			}
			else if (Copy_u8Value == DIO_LOW){
				CLEAR_BIT(DIO_PORTA_ODR, Copy_u8Pin);
			}
			break;
		case DIO_PORTB:
			if (Copy_u8Value == DIO_HIGH){
				SET_BIT(DIO_PORTB_ODR, Copy_u8Pin);
			}
			else if (Copy_u8Value == DIO_LOW){
				CLEAR_BIT(DIO_PORTB_ODR, Copy_u8Pin);
			}
			break;
		case DIO_PORTC:
			if (Copy_u8Value == DIO_HIGH){
				SET_BIT(DIO_PORTB_ODR, Copy_u8Pin);
			}
			else if (Copy_u8Value == DIO_LOW){
				CLEAR_BIT(DIO_PORTB_ODR, Copy_u8Pin);
			}
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