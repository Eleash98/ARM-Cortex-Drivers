//Author	:	Mohamed Gamal Eleash
//Version	:	V01
//Date		:	26 August 2020

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

#define STK_BASE_ADDRESS		0xE000E010

typedef struct{
	volatile u32 CTRL,
	LOAD,
	VALUE;
}STK_t;

#define STK		((volatile STK_t *)(STK_BASE_ADDRESS))

#define STK_AHB_8		0
#define STK_AHB			1

#endif

