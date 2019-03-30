#include "stm32f1xx_hal.h"
#include "LED.h"
#include "delay.h"

int main()
{
	HAL_Init();
	Stm32_Clock_Init(RCC_PLL_MUL9);
	delay_init(72);
	LED_Init();
	while(1)
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);
		delay_ms(500);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
		delay_ms(500);
	}
}
