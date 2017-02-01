#include "stm32f4xx.h"                  // Device header
#include "stm32f4xx_hal.h"              // Keil::Device:STM32Cube HAL:Common

void PLL_Init()
{
	RCC_ClkInitTypeDef clock;
	RCC_OscInitTypeDef osc;
	osc.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	osc.HSEState= RCC_HSE_ON;
	osc.PLL.PLLState=RCC_PLLSOURCE_HSE;
	osc.PLL.PLLSource=RCC_PLLSOURCE_HSE;
	osc.PLL.PLLM=25;
	osc.PLL.PLLN=336;
	osc.PLL.PLLP=RCC_PLLP_DIV2;
	osc.PLL.PLLQ=7;
	HAL_RCC_OscConfig(&osc);
	clock.ClockType=(RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	clock.SYSCLKSource=RCC_SYSCLKSOURCE_PLLCLK;
	clock.AHBCLKDivider=RCC_SYSCLK_DIV1;
	clock.APB1CLKDivider=RCC_SYSCLK_DIV4;
	clock.APB2CLKDivider=RCC_SYSCLK_DIV2;
	HAL_RCC_ClockConfig(&clock,FLASH_LATENCY_5);
}
