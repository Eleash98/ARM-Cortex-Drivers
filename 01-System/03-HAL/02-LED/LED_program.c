//Author:	Mohamed Gamal
//Date	:	15 August 2020
//Version:	V01
#include <stdlib.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"
#include "DIO_interface.h"

LED *LED_voidAttachLEDToPin(u8 Copy_u8Pin, u8 Copy_u8Port, u8 Copy_u8LEDConfig){

    LED *L = (LED*) malloc(sizeof(LED));
	L->Pin = Copy_u8Pin;
	L->Port = Copy_u8Port;
	L->Config = Copy_u8LEDConfig;
	DIO_voidSetPinDirection(L->Port,L->Pin, DIO_OUTPUT_SPEED_10MHZ_PP);
	if (Copy_u8LEDConfig == ACTIVE_HIGH)
		DIO_voidSetPinValue(L->Port,L->Pin, DIO_LOW);
	else 
		DIO_voidSetPinValue(L->Port,L->Pin, DIO_HIGH);
	
    return L;
}

void LED_DisAttachLEDFromPin(LED *L){
	DIO_voidSetPinDirection(L->Port,L->Pin,DIO_INPUT_ANALOG);
    free(L);
}

void LED_voidOn(LED *L){
	
	if (L->Config == ACTIVE_HIGH)
		DIO_voidSetPinValue(L->Port,L->Pin, DIO_HIGH);
	else 
		DIO_voidSetPinValue(L->Port,L->Pin, DIO_LOW);

}

void LED_voidOff(LED *L){
	
	if (L->Config == ACTIVE_HIGH)
		DIO_voidSetPinValue(L->Port,L->Pin, DIO_LOW);
	else 
		DIO_voidSetPinValue(L->Port,L->Pin, DIO_HIGH);
}

void LED_voidToggle(LED *L){
	if (DIO_voidGetPinValue(L->Port, L->Pin) == DIO_HIGH)
		DIO_voidSetPinValue(L->Port,L->Pin, DIO_LOW);
	else 
		DIO_voidSetPinValue(L->Port,L->Pin, DIO_HIGH);
}