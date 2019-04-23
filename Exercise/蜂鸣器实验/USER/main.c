#include "sys.h"
#include "delay.h"
#include "usart.h"

/************************************************
 ALIENTEK NANO��STM32F103������ʵ��0-2
 Template����ģ��-�����½�ʹ��-HAL��汾
 ����֧�֣�www.openedv.com
 �Ա����̣� http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

#include "Beep.h"



int main(void)
{
	//��ʼ��HAL��
	HAL_Init();
	//����ʱ��72Mhz
	Stm32_Clock_Init(RCC_PLL_MUL9);
	//��ʼ����ʱ����
	delay_init(72);
	//��ʼ�����裨�������˿ڣ�
	BEEP_Init();
	
	while(1)
	{
		//BEEP�������ߣ�����
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_RESET);
		//BEEP = 1;
		delay_ms(300);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);
		//BEEP = 0;
		delay_ms(300);
	}
}
