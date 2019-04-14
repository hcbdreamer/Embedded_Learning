#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "LED.h"
/************************************************
 ALIENTEK NANO板STM32F103开发板实验0-2
 Template工程模板-调试章节使用-HAL库版本
 技术支持：www.openedv.com
 淘宝店铺： http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/



/*跑马灯实验操控寄存器版本
int main(void)
{
	//仍然要对库函数进行初始化（使用了库函数的部分内容）
	HAL_Init();
	//时钟初始化
	Stm32_Clock_Init(RCC_PLL_MUL9);
	//延时初始化
	delay_init(72);
	//LED外设初始化
	LED_Init();
	
	while(1)
	{
		//PC.0输出高电平，LED0灭
	    GPIOC->ODR |= 1<<0;
		//PC.3输出高电平，LED3灭
		GPIOC->ODR |= 1<<3;
		delay_ms(500);
		
		//PC.0输出低电平，LED0亮
        GPIOC->ODR &= ~(1<<0);
		//PC.3输出低电平，LED3亮
		GPIOC->ODR &= ~(1<<3);
		delay_ms(500);
			
	}
}
*/
//跑马灯实验位带操作
int main(void)
{
	//仍然要对库函数进行初始化（使用了库函数的部分内容）
	HAL_Init();
	//时钟初始化
	Stm32_Clock_Init(RCC_PLL_MUL9);
	//延时初始化
	delay_init(72);
	//LED外设初始化
	LED_Init();
	
	while(1)
	{
		LED0 = 0;
		LED1 = 1;
		delay_ms(500);
		
		LED0 = 1;
		LED1 = 0;
		
		delay_ms(500);
	}
}

