#include "stm32f4xx.h"                  // Device header
#include "stm32f4xx_hal.h"              // Keil::Device:STM32Cube HAL:Common

GPIO_InitTypeDef portd;
GPIO_InitTypeDef porta;
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
	clock.SYSCLKSource=(RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	clock.SYSCLKSource=RCC_SYSCLKSOURCE_PLLCLK;
	clock.AHBCLKDivider=RCC_SYSCLK_DIV1;
	clock.APB1CLKDivider=RCC_SYSCLK_DIV4;
	clock.APB2CLKDivider=RCC_SYSCLK_DIV2;
	HAL_RCC_ClockConfig(&clock,FLASH_LATENCY_5);
	
}

void GPIOD_Init()
{
	__HAL_RCC_GPIOD_CLK_ENABLE();
	
	portd.Mode = GPIO_MODE_OUTPUT_PP;
	portd.Pin = GPIO_PIN_12 | GPIO_PIN_13 |GPIO_PIN_14 | GPIO_PIN_15;
	portd.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	portd.Pull = GPIO_PULLUP;
	
	HAL_GPIO_Init(GPIOD,&portd);
}

void GPIOA_Init()
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	
	porta.Mode= GPIO_MODE_INPUT;
	porta.Pin=GPIO_PIN_0;
	porta.Pull=GPIO_PULLDOWN;
	porta.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	
	HAL_GPIO_Init(GPIOA,&porta);
}
int main()
{
	PLL_Init();
	GPIOD_Init();
	GPIOA_Init();
	
	while(1)
	{

	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0))
	{
	  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_SET);
	}
		else
			{
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_RESET);
	}
}
}



