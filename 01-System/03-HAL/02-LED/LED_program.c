//Author:	Mohamed Gamal
//Date	:	15 August 2020
//Version:	V01

//Version	:	V02
//Date		:	21-August 2020
/*Version 2 Has private structs so the user cannot change the LED specs*/

#include <stdlib.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"
#include "DIO_interface.h"

#include <stdlib.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

#include "DIO_interface.h"

void *LED_voidAttachLEDToPin(u8 Copy_u8Pin, u8 Copy_u8Port, u8 Copy_u8LEDConfig){
    LED *L = (LED*) malloc(sizeof(LED));
	L->Pin = Copy_u8Pin;
	L->Port = Copy_u8Port;
	L->Config = Copy_u8LEDConfig;
	//DIO_voidSetPinDirection(L->Port,L->Pin, DIO_OUTPUT_SPEED_10MHZ_PP);
	DIO_voidSetPinDirection(Copy_u8Port,Copy_u8Pin,DIO_OUTPUT_SPEED_10MHZ_PP);
	if (Copy_u8LEDConfig == ACTIVE_HIGH)
		//DIO_voidSetPinValue(L->Port,L->Pin, DIO_LOW);
		DIO_voidSetPinValue(Copy_u8Port,Copy_u8Pin,DIO_HIGH);
		else
		//DIO_voidSetPinValue(L->Port,L->Pin, DIO_HIGH);
		DIO_voidSetPinValue(Copy_u8Port,Copy_u8Pin, DIO_HIGH);

    return L;
}

void LED_voidDisAttachLEDFromPin(void *L1){
	LED *L = (LED*)L1;
	DIO_voidSetPinDirection(L->Port,L->Pin,DIO_INPUT_ANALOG);
		free(L);
}

void LED_voidOn(void *L1){
	LED *L = (LED *)L1;
	if (L->Config == ACTIVE_HIGH)
		DIO_voidSetPinValue(L->Port,L->Pin, DIO_HIGH);
	else
		DIO_voidSetPinValue(L->Port,L->Pin, DIO_LOW);
}

void LED_voidOff(void *L1){
	LED *L = (LED *)L1;
	if (L->Config == ACTIVE_HIGH)
		DIO_voidSetPinValue(L->Port,L->Pin, DIO_LOW);
	else
		DIO_voidSetPinValue(L->Port,L->Pin, DIO_HIGH);
}

void LED_voidToggle(void *L1){
	LED *L = (LED *)L1;
	if (DIO_voidGetPinValue(L->Port, L->Pin) == DIO_HIGH)
		DIO_voidSetPinValue(L->Port,L->Pin, DIO_LOW);
	else
		DIO_voidSetPinValue(L->Port,L->Pin, DIO_HIGH);
}