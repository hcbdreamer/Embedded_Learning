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
#include "LED.h"
#include "Key.h"



int main(void)
{
	//���尴����ʶ��
	u8 key = 0;
	//��ʼ��HAL��
	HAL_Init();
	//����ʱ��72Mhz
	Stm32_Clock_Init(RCC_PLL_MUL9);
	//��ʼ����ʱ����
	delay_init(72);
	//��ʼ�����裨�������˿ڣ�
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


