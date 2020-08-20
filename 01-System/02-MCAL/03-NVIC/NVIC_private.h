//Author	:		Mohamed Gamal
//Date		:		19-August-2020
//Version	:		V01

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

// 0xE000E100

//ISER : Interrupt Set Enable Register

#define NVIC_ISER0		(*(u32*)(0xE000E100))
#define NVIC_ISER1		(*(u32*)(0xE000E104))

// ICER	:	Interrupt Clear Enable Register
#define NVIC_ICER0		(*(u32*)(0xE000E180))
#define NVIC_ICER1		(*(u32*)(0xE000E184))

//ISPR	:	Interrupt Set Pending Register
#define NVIC_ISPR0		(*(u32*)(0xE000E200))
#define NVIC_ISPR1		(*(u32*)(0xE000E204))

//ICPR	:	Interrupt Clear Pending Register
#define NVIC_ICPR0		(*(u32*)(0xE000E280))
#define NVIC_ICPR1		(*(u32*)(0xE000E284))

//IABR	:	Interrupt Active Bit Register
#define NVIC_IABR0		(*(volatile u32*)(0xE000E300))
#define NVIC_IABR1		(*(volatile u32*)(0xE000E304))


#endif