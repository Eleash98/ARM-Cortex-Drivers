//Author	:	Mohamed Gamal Eleash
//Version	:	V01
//Date		:	26 August 2020



#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

void MSTK_voidInit(void);				//choose clock

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);			//act as delay "Synchronous function"
	//Load = Copy_u32Ticks
	//Enable systick
	//while(flag == 0);
	
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr) (void));		//Asynchronous function
	//Load = Copy_u32Ticks
	//Enable interrupt and systick
	//CALLBACK = ptr
	//return
	
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr) (void));	//Asynchronous function

void MSTK_voidStopTimer();				//Stops the timer

u32 MSTK_u32GetElapsedTime();			//returns the Elapsed time since the last set "read value register"

u32 MSTK_u32GetRemainingTime();			//return the remaining time to the next interrupt "load - value"



#endif

