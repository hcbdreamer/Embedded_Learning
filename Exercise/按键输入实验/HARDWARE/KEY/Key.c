#include "Key.h"
#include "delay.h"


void Key_Init(void)
{
	 
	//��ʼ��IO��ʱ��(Key0��Key1��GPIOC,Key2��GPIOD,Key_WakeUp��GPIOA)
	//Key0��Key1��Key2����Ϊ�͵�ƽ��Key_WakeUp����Ϊ�ߵ�ƽ
	 __HAL_RCC_GPIOA_CLK_ENABLE();
	 __HAL_RCC_GPIOC_CLK_ENABLE();
	 __HAL_RCC_GPIOD_CLK_ENABLE();
	
	 GPIO_InitTypeDef GPIO_Initure;
	//��ʼ��GPIOA��GPIO_PIN_0��
	 GPIO_Initure.Pin = GPIO_PIN_0;
	 GPIO_Initure.Mode = GPIO_MODE_INPUT;
	 GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH;
	 GPIO_Initure.Pull = GPIO_PULLDOWN;//����
	 HAL_GPIO_Init(GPIOA,&GPIO_Initure); 
	 
	//��ʼ��GPIOC��GPIO_PIN_8�ڡ�GPIO_PIN_9��
	 GPIO_Initure.Pin = GPIO_PIN_8 | GPIO_PIN_9;
	 GPIO_Initure.Mode = GPIO_MODE_INPUT;
	 GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH;
	 GPIO_Initure.Pull = GPIO_PULLUP;//����
	 HAL_GPIO_Init(GPIOC,&GPIO_Initure); 
	 
    //��ʼ��GPIOD��GPIO_PIN_2��
	 GPIO_Initure.Pin = GPIO_PIN_2;
	 GPIO_Initure.Mode = GPIO_MODE_INPUT;
	 GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH;
	 GPIO_Initure.Pull = GPIO_PULLUP;//����
	 HAL_GPIO_Init(GPIOD,&GPIO_Initure);
}

//����ɨ�躯��
//mode:0,��֧����������1��֧��������
u8 Key_Scan(u8 mode)
{
	static u8 key_up = 1;
	if(mode)
		key_up = 1;
	if(key_up &&(KEY0 == 0 || KEY1 == 0 || KEY2 == 0 ||KEY_WK_UP ==1))
	{
		delay_ms(10); //��ʱ����
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

