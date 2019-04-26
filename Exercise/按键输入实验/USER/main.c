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
#include "LED.h"
#include "Key.h"



int main(void)
{
	//定义按键标识符
	u8 key = 0;
	//初始化HAL库
	HAL_Init();
	//设置时钟72Mhz
	Stm32_Clock_Init(RCC_PLL_MUL9);
	//初始化延时函数
	delay_init(72);
	//初始化外设（蜂鸣器端口）
	BEEP_Init();
	LED_Init();
	Key_Init();
	
	while(1)
	{
		key = Key_Scan(0);
		switch(key)
		{
			case KEY0_PRESS:
				LED5 = !LED5;
			    break;
			case KEY1_PRESS:
				LED6 = !LED6;
			    break;
			case KEY2_PRESS:
				BEEP = !BEEP;
			    break;
			case KEY_WK_UP_PRESS:
				LED5 = !LED5;
			    LED6 = !LED6;
			    break;
			default:
				delay_ms(10);
		}
				
	}
}


