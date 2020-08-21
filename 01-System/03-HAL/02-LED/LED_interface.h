//Author:	Mohamed Gamal
//Date	:	15 August 2020
//Version:	V01

//Version	:	V02
//Date		:	21-August 2020
/*Version 2 Has private structs so the user cannot change the LED specs*/


#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#define ACTIVE_HIGH		1
#define ACTIVE_LOW		0


 void *LED_voidAttachLEDToPin(u8 Copy_u8Pin, u8 Copy_u8Port, u8 Copy_u8LEDConfig);

 void LED_voidDisAttachLEDFromPin(void *L);

 void LED_voidOn(void *L);

 void LED_voidOff(void *L);

 void LED_voidToggle(void *L);
#endif