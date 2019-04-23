#include "sys.h"
#include "delay.h"
#include "usart.h"

/************************************************
 ALIENTEK NANO板STM32F103开发板实验0-2
 Template工程模板-调试章节使用-HAL库版本
 技术支持：www.openedv.com
 淘宝店铺： http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/

#include "Beep.h"



int main(void)
{
	//初始化HAL库
	HAL_Init();
	//设置时钟72Mhz
	Stm32_Clock_Init(RCC_PLL_MUL9);
	//初始化延时函数
	delay_init(72);
	//初始化外设（蜂鸣器端口）
	BEEP_Init();
	
	while(1)
	{
		//BEEP引脚拉高，不响
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_RESET);
		//BEEP = 1;
		delay_ms(300);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);
		//BEEP = 0;
		delay_ms(300);
	}
}
