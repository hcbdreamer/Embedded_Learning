#include "LED.h"
#include "stm32f1xx_hal.h"


void LED_Init()
{
	GPIO_InitTypeDef GPIO__InitType_Struc;
	//使能外部时钟
	__HAL_RCC_GPIOC_CLK_ENABLE();
	
	GPIO__InitType_Struc.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO__InitType_Struc.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
                               |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
	GPIO__InitType_Struc.Pull = GPIO_PULLUP;
	GPIO__InitType_Struc.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
                               |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,GPIO_PIN_RESET);
	
	//初始化GPIO口
	HAL_GPIO_Init(GPIOC,&GPIO__InitType_Struc);
}
