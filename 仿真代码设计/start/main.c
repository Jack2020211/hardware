#include "public.h"
#include "LCD1602.H"
#include "MAX1241.H"
#include "MCP4921.H"
#include "Tim.h"
#include "KEY.H"
//#include "Filter.H"
#include "TLC0832.H"
//sbit LED=P2^4;
extern unsigned int V_u16;
extern float SET_V;
u16 I_mA,I_mA_now;
u8 flag1;

	

void main(){
	//////
	I_mA=0;
	Tim0_init();
	LCD_Init();
	KEY_Init();
	ADC0832_init();
//	LED=1;
	LCD_ShowString(1,9,"mA");	
	LCD_ShowChar(1,16,'V');
	LCD_ShowChar(2,16,0xf4);
	LCD_ShowString(2,12,"R");
	LCD_ShowString(1,1,"SET:");
	LCD_ShowString(2,1,"NOW:");
	LCD_ShowString(2,9,"mA");
	
	while(1){
	
		
		
	if(P3_2==0){
		//+++++++
	delay_ms(30);
		I_mA++;
		if(I_mA>2000)I_mA=0;
		flag1=1;
	delay_ms(300);
	while(!P3_2){
		I_mA+=2;
		if(I_mA>2000)I_mA=0;
		flag1=1;
		delay_ms(20);
	}
	
		//--------
	}
	if(P3_3==0){
	delay_ms(30);
		I_mA--;
		if(I_mA>2000)I_mA=2000;
		flag1=1;
	delay_ms(300);
	while(!P3_3){
		I_mA-=2;
		if(I_mA>2000)I_mA=2000;
		flag1=1;
		delay_ms(20);
	}
	}
	if(P3_4==0){delay_ms(20);I_mA=0;flag1=1;delay_ms(20);}
	if(P3_5==0){delay_ms(20);I_mA=1000;flag1=1;delay_ms(20);}

		}


}



 void Timer0_Rountine() interrupt 1
{  
	static u8 flag_lcd=0,u8_R_V;
  static float V,d_V;
	
	TR0=0;
	TL0 = 0xF0;		//设置定时初始值
	TH0 = 0xD8;		//设置定时初始值
	TR0=1;
	flag_lcd++;


	
	
	
	if(flag1)
		{
			Set_I(I_mA);flag1=0;
			set_DA_MCP4921(V_u16);
			LCD_ShowNum(1,5,I_mA,4);
			
		
	}
		
	
	if(flag_lcd==50){
			V=read_max1241_V();
		//		V=kalmanFilter(V);
			I_mA_now=V*400;
			d_V=(SET_V-V);
			if(d_V>0)
				V_u16+=1;	
			else
				V_u16-=1;		
			set_DA_MCP4921(V_u16);
			u8_R_V = ADC0832_ReadAD();
			
			

			Show_float(1,12,(float)u8_R_V*0.0393);
			
			
			LCD_ShowNum(2,13,(float)u8_R_V*39.3/I_mA,3);
			
			LCD_ShowNum(2,5,I_mA_now,4);
			
			flag_lcd=0;	
	}

}