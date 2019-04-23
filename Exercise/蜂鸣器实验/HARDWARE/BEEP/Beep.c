
//使能时钟的库函数在该头文件中
//#include "stm32f1xx_hal.h"
#include "Beep.h"




//蜂鸣器初始化
void BEEP_Init(void)
{
	//如果使用指针，指针需要初始化，预分配内存（malloc），在stm32中，可供分配的内存是有限的，谨慎使用
	GPIO_InitTypeDef GPIO_Initure;
	//蜂鸣器在PB8口，需要先初始化GPIOB的时钟
     __HAL_RCC_GPIOB_CLK_ENABLE();
	
	GPIO_Initure.Mode =  GPIO_MODE_OUTPUT_PP;//设置模式为推挽输出
	GPIO_Initure.Pin = GPIO_PIN_8;//PB8
	GPIO_Initure.Pull = GPIO_PULLUP;//上拉
	GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH;//高速
	HAL_GPIO_Init(GPIOB,&GPIO_Initure); //初始化蜂鸣器对应IO口

	//设置蜂鸣器初始状态
	//HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);	//蜂鸣器对应引脚GPIOB8拉高，
	
}

