//Author	:	Mohamed Gamal Eleash
//Version	:	V01
//Date		:	26 August 2020
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"


void (*CALLBACK) (void);
u8 SINGLE_FLAG = 0 ;

void MSTK_voidInit(void){	//choose clock
	STK->CTRL = (STK_CLOCK_SOURCE)<<2;

}	

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks){			//act as delay "Synchronous function"
	STK->LOAD = Copy_u32Ticks;
	//Enable systick
	STK->CTRL |= 0x0001;
	//while(flag == 0);
	while (GET_BIT(STK->CTRL,16) == 0){
	
	}
	STK->LOAD = 0;

}
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr) (void)){		//Asynchronous function
	SINGLE_FLAG = 1;
	STK->LOAD = Copy_u32Ticks;
	//Enable interrupt and systick
	STK->CTRL |= 0x003;
	CALLBACK = Copy_ptr;
	//return

}
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr) (void)){	//Asynchronous function
	STK->LOAD = Copy_u32Ticks;
	//Enable interrupt and systick
	STK->CTRL |= 0x003;
	CALLBACK = Copy_ptr;
	//return

}
void MSTK_voidStopTimer(){				//Stops the timer
	STK->CTRL = (STK_CLOCK_SOURCE)<<2;
}
u32 MSTK_u32GetElapsedTime(){			//returns the Elapsed time since the last set "read value register"
	return (u32)STK->VALUE;

}
u32 MSTK_u32GetRemainingTime(){			//return the remaining time to the next interrupt "load - value"
	return (u32)(STK->LOAD - STK->VALUE);

}



void SysTick_Handler(void){
	CALLBACK();
	if (SINGLE_FLAG == 1){
		CLR_BIT(STK->CTRL,1);
		SINGLE_FLAG = 0;
	}
}

