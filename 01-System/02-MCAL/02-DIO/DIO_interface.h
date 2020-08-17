//AUTHOR	:Mohamed Gamal
//VERSION	:V01
//DATE		:11-August-2020

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define DIO_PORTA	0
#define	DIO_PORTB	1
#define DIO_PORTC	2

#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7
#define PIN8	8
#define PIN9	9
#define PIN10	10
#define PIN11	11
#define PIN12	12
#define PIN13	13
#define PIN14	14
#define PIN15	15


#define DIO_OUTPUT_SPEED_10MHZ_PP	0b0001		//10Mhz push pull
#define DIO_OUTPUT_SPEED_10MHZ_OD	0b0101		//10MHz	open drain
#define DIO_OUTPUT_SPEED_10MHZ_AFPP	0b1001		//10MHz	alternative function open drain
#define DIO_OUTPUT_SPEED_10MHZ_AFOD	0b1101		//10MHz	alternative function open drain

#define DIO_OUTPUT_SPEED_2MHZ_PP	0b0010		//10Mhz push pull
#define DIO_OUTPUT_SPEED_2MHZ_OD	0b0110		//10MHz	open drain
#define DIO_OUTPUT_SPEED_2MHZ_AFPP	0b101		//10MHz	alternative function open drain
#define DIO_OUTPUT_SPEED_2MHZ_AFOD	0b1110		//10MHz	alternative function open drain

#define DIO_OUTPUT_SPEED_50MHZ_PP	0b0011		//10Mhz push pull
#define DIO_OUTPUT_SPEED_50MHZ_OD	0b0111		//10MHz	open drain
#define DIO_OUTPUT_SPEED_50MHZ_AFPP	0b1011		//10MHz	alternative function open drain
#define DIO_OUTPUT_SPEED_50MHZ_AFOD	0b1110		//10MHz	alternative function open drain
/*
#define OUTPUT_SPEED_10MHZ_PP	0b0001		//10Mhz push pull
#define OUTPUT_SPEED_10MHZ_OD	0b0101		//10MHz	open drain
#define OUTPUT_SPEED_10MHZ_AFPP	0b1001		//10MHz	alternative function open drain
#define OUTPUT_SPEED_10MHZ_AFOD	0b0101		//10MHz	alternative function open drain
*/

#define DIO_INPUT_ANALOG		0b0000		//10Mhz push pull
#define DIO_INPUT_FLOATING		0b0100		//10MHz	open drain
#define DIO_INPUT_PULLUP_DOWN	0b1000		//10MHz	alternative function open drain

#define DIO_HIGH 			1
#define DIO_LOW				0








void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);

void DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

u8 DIO_voidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);


#endif