#ifndef _KEY_H
#define _KEY_H

#include "sys.h"

#define KEY0 PCin(8) //KEY0����PA0
#define KEY1 PCin(9) //KEY1����PC8
#define KEY2 PDin(2) //KEY2����PC9
#define KEY_WK_UP PAin(0) //KEY_WK_UP����PD2

#define KEY0_PRESS 1 //KEY0����
#define KEY1_PRESS 2 //KEY1����
#define KEY2_PRESS 3 //KEY2����
#define KEY_WK_UP_PRESS 4 //KEY_WK_UP����


void Key_Init(void);
u8 Key_Scan(u8 mode);




#endif

