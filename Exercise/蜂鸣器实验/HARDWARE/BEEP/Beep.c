
//ʹ��ʱ�ӵĿ⺯���ڸ�ͷ�ļ���
//#include "stm32f1xx_hal.h"
#include "Beep.h"




//��������ʼ��
void BEEP_Init(void)
{
	//���ʹ��ָ�룬ָ����Ҫ��ʼ����Ԥ�����ڴ棨malloc������stm32�У��ɹ�������ڴ������޵ģ�����ʹ��
	GPIO_InitTypeDef GPIO_Initure;
	//��������PB8�ڣ���Ҫ�ȳ�ʼ��GPIOB��ʱ��
     __HAL_RCC_GPIOB_CLK_ENABLE();
	
	GPIO_Initure.Mode =  GPIO_MODE_OUTPUT_PP;//����ģʽΪ�������
	GPIO_Initure.Pin = GPIO_PIN_8;//PB8
	GPIO_Initure.Pull = GPIO_PULLUP;//����
	GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH;//����
	HAL_GPIO_Init(GPIOB,&GPIO_Initure); //��ʼ����������ӦIO��

	//���÷�������ʼ״̬
	//HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);	//��������Ӧ����GPIOB8���ߣ�
	
}

