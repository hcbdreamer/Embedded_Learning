#include "stm32f1xx_hal.h"
#include "LED.h"
#include "delay.h"


/*使用库函数*/
int main()
{
	//HAL库初始化
	HAL_Init();
	//时钟初始化
	Stm32_Clock_Init(RCC_PLL_MUL9);
	delay_init(72);
	//LED外设初始化
	LED_Init();
	while(1)
	{
		//LED0、1灭
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);
		delay_ms(500);
		//LED0、1亮
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
		delay_ms(500);
	}
}
