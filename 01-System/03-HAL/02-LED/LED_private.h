//Author:	Mohamed Gamal
//Date	:	15 August 2020
//Version:	V01


//Version	:	V02
//Date		:	21-August 2020
/*Version 2 Has private structs so the user cannot change the LED specs*/

#ifndef LED_PRIVATE_H
#define LED_PRIVATE_H


struct LED {
	u8 Pin,
	 Port,
	 Config;
};
typedef struct LED LED;


#endif
