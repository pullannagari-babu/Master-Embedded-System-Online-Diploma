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


#include <stdio.h>

#define Set(Register_name,bit_no)     Register_name|=(1<<bit_no)    //to set bit
#define Reset(Register_name,bit_no)   Register_name&=~(1<<bit_no)   //to reset bit
#define Toggle(Register_name,bit_no)  Register_name^=(1<<bit_no)    //to set bit

typedef volatile unsigned int vuint32_t ;

//RCC reset and clock control Peripheral Base Address
#define RCC            0x40021000
#define RCC_APB2ENR    *( vuint32_t *)( RCC + 0x18 )   //APB2 peripheral Clock Enable Register

//EXTI External Interrupt Peripheral
#define EXTI           0x40010400
#define EXTI_IMR       *( vuint32_t *)( EXTI + 0x00 )   //Interrupt Mask Register
#define EXTI_RTSR      *( vuint32_t *)( EXTI + 0x08 )   //Rising trigger selection Register
#define EXTI_PR        *( vuint32_t *)( EXTI + 0x14 )   //Pending Register

//Nested Vectored Interrupt Controller
#define NVIC           0xE000E100
#define NVIC_ISER0     *( vuint32_t *)( NVIC + 0x00 )   //Interrupt Set-Enable Register

//AFIO Altrenate Function I/O Peripheral
#define AFIO           0x40010000
#define AFIO_EXTICR1   *( vuint32_t *)( AFIO + 0x08 )   //External interrupt configuration Register 1

//GPIO General Purpose Input Output Peripheral
#define GPIOA          0x40010800
#define GPIOA_CRL      *( vuint32_t *)( GPIOA + 0x00 )   //Port Configuration Register Low
#define GPIOA_CRH      *( vuint32_t *)( GPIOA + 0x04 )   //Port Configuration Register High
#define GPIOA_ODR      *( vuint32_t *)( GPIOA + 0x0C )   //Port Output Data Register


void Init_HSI_Clock()
{
	Set(RCC_APB2ENR,0);    //Enable AFIO  Clock
	Set(RCC_APB2ENR,2);    //Enable GPIOA Clock
	return;
}

void Init_EXTI0()
{
	//Enable rising trigger selection register
	Set(EXTI_RTSR,0);

	//Enable Interrupt Mask Register
	Set(EXTI_IMR,0);

	//Enable gloable Nested Vectored Interrupt Controller
	Set(NVIC_ISER0,6);

	return;
}

void Init_AFIO()
{
	//Enable AFIO for EXTI0
	//By default set 0b000 for PORTA

	return;
}

void Init_GPIOA()
{
	//Enable Pin0 as input
	//CNF0  Floating input by write 01
	//MODE0 Input mode by write 00
	Set(GPIOA_CRL,2);

	//Enable Pin13 as output
	//CNF13  General purpose output push-pull by write 00
	Reset(GPIOA_CRH,22);

	//MODE13 Output mode, max speed 2 MHz. by write 10
	Set(GPIOA_CRH,21);

	return;
}

int main()
{
	Init_HSI_Clock();   //INIT HSI Clock
	Init_GPIOA();       //Init GPIOA
	Init_AFIO();        //Init AFIO
	Init_EXTI0();        //Init EXTI0

	while(1);

	return 0;
}

void EXTI0_IRQHandler()
{
    //Set port output data register
	Toggle(GPIOA_ODR,13);

	//Reset Pending Register by write 1
	Set(EXTI_PR,0);

}