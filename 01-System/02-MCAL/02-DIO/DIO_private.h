//AUTHOR	:Mohamed Gamal
//VERSION	:V01
//DATE		:11-August-2020

#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/*Base Addresses*/
#define DIO_PORTA_BASE_ADDRESS	0x40010800
#define DIO_PORTB_BASE_ADDRESS	0x40010C00
#define DIO_PORTC_BASE_ADDRESS	0x40011000


/*PORTA Register definitions*/
#define DIO_PORTA_CRL	(*(u32*)0x40010800)
#define DIO_PORTA_CRH	(*(u32*)0x40010804)
#define DIO_PORTA_IDR	(*(u32*)0x40010808)
#define DIO_PORTA_ODR	(*(u32*)0x4001080C)
#define	DIO_PORTA_BSRR	(*(u32*)0x40010810)
#define DIO_PORTA_BRR	(*(u32*)0x40010814)
#define DIO_PORTA_LCKR	(*(u32*)0x40010818)

/*PORTB Register definitions*/
#define DIO_PORTB_CRL	(*(u32*)0x40010C00)
#define DIO_PORTB_CRH	(*(u32*)0x40010C04)
#define DIO_PORTB_IDR	(*(u32*)0x40010C08)
#define DIO_PORTB_ODR	(*(u32*)0x40010C0C)
#define	DIO_PORTB_BSRR	(*(u32*)0x40010C10)
#define DIO_PORTB_BRR	(*(u32*)0x40010C14)
#define DIO_PORTB_LCKR	(*(u32*)0x40010C18)

/*PORTC Register definistions*/
#define DIO_PORTC_CRL	(*(u32*)0x40011000)
#define DIO_PORTC_CRH	(*(u32*)0x40011004)
#define DIO_PORTC_IDR	(*(u32*)0x40011008)
#define DIO_PORTC_ODR	(*(u32*)0x4001100C)
#define	DIO_PORTC_BSRR	(*(u32*)0x40011010)
#define DIO_PORTC_BRR	(*(u32*)0x40011014)
#define DIO_PORTC_LCKR	(*(u32*)0x40011018)



#endif