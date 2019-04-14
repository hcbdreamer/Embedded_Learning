#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "LED.h"
/************************************************
 ALIENTEK NANO��STM32F103������ʵ��0-2
 Template����ģ��-�����½�ʹ��-HAL��汾
 ����֧�֣�www.openedv.com
 �Ա����̣� http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/



/*�����ʵ��ٿؼĴ����汾
int main(void)
{
	//��ȻҪ�Կ⺯�����г�ʼ����ʹ���˿⺯���Ĳ������ݣ�
	HAL_Init();
	//ʱ�ӳ�ʼ��
	Stm32_Clock_Init(RCC_PLL_MUL9);
	//��ʱ��ʼ��
	delay_init(72);
	//LED�����ʼ��
	LED_Init();
	
	while(1)
	{
		//PC.0����ߵ�ƽ��LED0��
	    GPIOC->ODR |= 1<<0;
		//PC.3����ߵ�ƽ��LED3��
		GPIOC->ODR |= 1<<3;
		delay_ms(500);
		
		//PC.0����͵�ƽ��LED0��
        GPIOC->ODR &= ~(1<<0);
		//PC.3����͵�ƽ��LED3��
		GPIOC->ODR &= ~(1<<3);
		delay_ms(500);
			
	}
}
*/
//�����ʵ��λ������
int main(void)
{
	//��ȻҪ�Կ⺯�����г�ʼ����ʹ���˿⺯���Ĳ������ݣ�
	HAL_Init();
	//ʱ�ӳ�ʼ��
	Stm32_Clock_Init(RCC_PLL_MUL9);
	//��ʱ��ʼ��
	delay_init(72);
	//LED�����ʼ��
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

