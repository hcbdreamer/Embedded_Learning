#include "LED.h"
#include "stm32f103xb.h"


void LED_Init(void){
	
	//����ʱ��ʹ�ܣ�ʹ�����е�4λ
	RCC->APB2ENR |= 1<<4;
	GPIOC->CRL &= 0x00000000;
	GPIOC->CRL |= 0x33333333;//PC0~7�������
	//PC.0~7 ����ߵ�ƽ
	GPIOC->ODR |= (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7);
	
}
