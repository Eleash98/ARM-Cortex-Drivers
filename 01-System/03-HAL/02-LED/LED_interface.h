//Author:	Mohamed Gamal
//Date	:	15 August 2020
//Version:	V01

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#define ACTIVE_HIGH		1
#define ACTIVE_LOW		0


struct LED {
	u8 PIN,
	u8 Port,
	u8 Config
};
typedef struct LED LED;


LED *LED_voidAttachLEDToPin(u8 Copy_u8Pin, u8 Copy_u8Port, u8 Copy_u8LEDConfig);

void LED_DisAttachLEDFromPin(LED *L);

void LED_voidOn(LED *L);

void LED_voidOff(LED *L);

void LED_voidToggle(LED *L)

#endif