#include "Tim.h"

//1ms 定时器
void Tim0_init() //T0  10ms
{		
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0xF0;		//设置定时初始值
	TH0 = 0xD8;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	
	ET0=1;       //打开中断
	EA=1;
	PT0=1;
	TR0 = 1;		//定时器0开始计时
}








/*
函数声明  定时20ms   用于电机与pwm波的调节

*/
//void Tim1_init()
//{
//	TMOD &= 0x0F;		//设置定时器模式
//	TMOD |= 0x10;		//设置定时器模式
//   TL0 = 0xD7;		//设置定时初值
//	  TH0 = 0xFD;		//设置定时初值
//	TF1 = 0;		//清除TF1标志
//	TR1 = 1;		//定时器1开始计时
//	ET0=1;       //打开中断
//	EA=1;
//	PT0=1;
//}

void Tim1_init()
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL1 = 0x66;		//设置定时初始值
	TH1 = 0xFC;		//设置定时初始值
	TF1 = 0;		//清除TF0标志
	
	ET1=1;       //打开中断
	EA=1;
	PT1=1;
	TR1 = 1;		//定时器1开始计时
}
/*

void Timer1_Rountine() interrupt 3
{
	TL1 = 0x00;		//设置定时初值
	TH1 = 0xB8;		//设置定时初值
}


*/
