#include "Key.h"
#include "delay.h"


void Key_Init(void)
{
	 
	//初始化IO口时钟(Key0、Key1在GPIOC,Key2在GPIOD,Key_WakeUp在GPIOA)
	//Key0、Key1、Key2按下为低电平，Key_WakeUp按下为高电平
	 __HAL_RCC_GPIOA_CLK_ENABLE();
	 __HAL_RCC_GPIOC_CLK_ENABLE();
	 __HAL_RCC_GPIOD_CLK_ENABLE();
	
	 GPIO_InitTypeDef GPIO_Initure;
	//初始化GPIOA中GPIO_PIN_0口
	 GPIO_Initure.Pin = GPIO_PIN_0;
	 GPIO_Initure.Mode = GPIO_MODE_INPUT;
	 GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH;
	 GPIO_Initure.Pull = GPIO_PULLDOWN;//下拉
	 HAL_GPIO_Init(GPIOA,&GPIO_Initure); 
	 
	//初始化GPIOC中GPIO_PIN_8口、GPIO_PIN_9口
	 GPIO_Initure.Pin = GPIO_PIN_8 | GPIO_PIN_9;
	 GPIO_Initure.Mode = GPIO_MODE_INPUT;
	 GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH;
	 GPIO_Initure.Pull = GPIO_PULLUP;//上拉
	 HAL_GPIO_Init(GPIOC,&GPIO_Initure); 
	 
    //初始化GPIOD中GPIO_PIN_2口
	 GPIO_Initure.Pin = GPIO_PIN_2;
	 GPIO_Initure.Mode = GPIO_MODE_INPUT;
	 GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH;
	 GPIO_Initure.Pull = GPIO_PULLUP;//上拉
	 HAL_GPIO_Init(GPIOD,&GPIO_Initure);
}

//按键扫描函数
//mode:0,不支持连续按；1，支持连续按
u8 Key_Scan(u8 mode)
{
	static u8 key_up = 1;
	if(mode)
		key_up = 1;
	if(key_up &&(KEY0 == 0 || KEY1 == 0 || KEY2 == 0 ||KEY_WK_UP ==1))
	{
		delay_ms(10); //延时防抖
		key_up = 0;
		if(KEY0 == 0)
			return KEY0_PRESS;
		else if(KEY1 == 0)
			return KEY1_PRESS;
		else if(KEY2 == 0)
			return KEY2_PRESS;
		else if(KEY_WK_UP == 1)
			return KEY_WK_UP_PRESS;		
	}
	else if(KEY0 == 1 && KEY1 == 1 && KEY2 == 1 && KEY_WK_UP == 0)
		key_up = 1;
	    return 0;			
}

