//AUTHOR	:Mohamed Gamal
//VERSION	:V01
//DATE		:8-August-2020

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/*Register definitions*/

#define RCC_CR          *((u32*)0x40021000)  //clock selection for processor
#define RCC_CFGR        *((u32*)0x40021004)  //clock selection for processor
#define RCC_CIR         *((u32*)0x40021008)
#define RCC_APB2RSTR    *((u32*)0x4002100C)
#define RCC_APB1RSTR    *((u32*)0x40021010)
#define RCC_AHBENR      *((u32*)0x40021014)   //E/D clocks for peripherals
#define RCC_APB2ENR     *((u32*)0x40021018)   //E/D clocks for peripherals
#define RCC_APB1ENR     *((u32*)0x4002101C)   //E/D clocks for peripherals
#define RCC_BDCR        *((u32*)0x40021020)
#define RCC_CSR         *((u32*)0x40021024)

/*Clock Types*/
#define RCC_HSE_CRYSTAL     0
#define RCC_HSE_RC          1
#define RCC_HSI             2
#define RCC_PLL             3

/* PLL Options*/
#define RCC_PLL_IN_HSI_DIV_2	0
#define RCC_PLL_IN_HSE			1
#define TRUE					1
#define FALSE					0
#define CRYSTAL					1
#define RC 						0
/*RCC_CR BIT DIFINITIONS*/
#define HSION   0
#define HSIRDY  1
#define HSITRIM 3
#define HSICAL  8
#define HSEON   16
#define HSERDY  17
#define PLLMUL  18

/*RCC_CFGR BIT DIFINITIONS*/


/*Configure Macros*/

#endif // RCC_PRIVATE_H
