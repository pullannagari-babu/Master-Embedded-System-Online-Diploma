/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/******************************************************************************/

#include <stdio.h>

#define Delay        for(_delay=0 ; _delay < 2000 ; _delay++)   //delay time

typedef volatile unsigned int vuint32_t ;

//GPIOA addresses
#define GPIOA        0x40010800

//PORTA configuration register
#define GPIOA_CRH    *(vuint32_t *)(GPIOA + 0x04)
#define GPIOA_ODR    *(vuint32_t *)(GPIOA + 0x0C)

//RCC reset and clock control address
#define RCC          0x40021000

//APB2 peripheral clock enable register address
#define RCC_APB2ENR  *(vuint32_t *)(RCC + 0x18)

//GPIOA clock enable bit
#define IOPAEN 2

#define Set(Register_name,bit_no)     Register_name|=(1<<bit_no)    //to set bit
#define Reset(Register_name,bit_no)   Register_name&=~(1<<bit_no)   //to reset bit

int main()
{
	vuint32_t _delay;

	//Enable PCLK2 clock
	//Enable GPIOA peripheral clock
	Set(RCC_APB2ENR,IOPAEN);

	//Init GPIOA
	//Enable CNF13  write 00 (General purpose output push-pull)
	Reset(GPIOA_CRH,22);

	//Enable MODE13 write 01 (Output mode, max speed 10 MHz)
	Set(GPIOA_CRH,21);

	while(1)
	{
		Set(GPIOA_ODR,13);    //led is ON
		Delay;
		Reset(GPIOA_ODR,13);  //led is ON
		Delay;
	}
	return 0;
}
