#include "stm32f4xx.h"                  // Device header
#include "stm32f4xx_hal.h"              // Keil::Device:STM32Cube HAL:Common
#include "clock.h"
#include "misc.h"

GPIO_InitTypeDef portd;
GPIO_InitTypeDef porta;

uint8_t *TxBuffer;
uint8_t *RxBuffer;

void UARTInit()
{
	UART_HandleTypeDef uart;
	uart.Init.BaudRate = 9600;
	uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart.Init.Mode = UART_MODE_TX_RX;
	uart.Init.OverSampling = UART_OVERSAMPLING_8;
	uart.Init.Parity = UART_PARITY_NONE;
	uart.Init.StopBits = UART_STOPBITS_1;
	uart.Init.WordLength = UART_WORDLENGTH_8B;
	HAL_UART_Init(&uart);
  HAL_UART_Transmit_IT(&uart, TxBuffer, sizeof(TxBuffer));
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
	
	
	while(1);
}
		
void UART_IRQHandle()
{
	
}

