#ifndef _KEY_H
#define _KEY_H

#include "sys.h"

#define KEY0 PCin(8) //KEY0按键PA0
#define KEY1 PCin(9) //KEY1按键PC8
#define KEY2 PDin(2) //KEY2按键PC9
#define KEY_WK_UP PAin(0) //KEY_WK_UP按键PD2

#define KEY0_PRESS 1 //KEY0按下
#define KEY1_PRESS 2 //KEY1按下
#define KEY2_PRESS 3 //KEY2按下
#define KEY_WK_UP_PRESS 4 //KEY_WK_UP按下


void Key_Init(void);
u8 Key_Scan(u8 mode);




#endif

