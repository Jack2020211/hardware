#ifndef __KEY_H__
#define __KEY_H__
#include "public.h"
sbit P3_2=P3^2;
sbit P3_3=P3^3;
sbit P3_4=P3^4;
sbit P3_5=P3^5;
//用户调用函数：
unsigned char Key(void);
void KEY_Init(void);
#endif