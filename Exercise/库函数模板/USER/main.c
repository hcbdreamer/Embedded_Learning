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


/***注意：本工程和教程中的新建工程3.4小节对应***/


int main(void)
{
	u8 t=0;
	
    HAL_Init();                    	//初始化HAL库    
    Stm32_Clock_Init(RCC_PLL_MUL9); //设置时钟,72M
    delay_init(72);                 //初始化延时函数
    uart_init(115200);              //初始化USART
	while(1)
	{
		printf("t:%d\r\n",t);
		delay_ms(500);
		t++;
	}
}
