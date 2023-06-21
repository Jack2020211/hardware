#include "KEY.H"


void KEY_Init(void){
	P3_2=1;
	P3_3=1;
	P3_4=1;
	P3_4=1;
}
/**
  * @brief  获取独立按键键码
  * @param  无
  * @retval 按下按键的键码，范围：0~4，无按键按下时返回值为0
  */
unsigned char Key()
{
	static unsigned char KeyNumber=0;
	
	if(P3_2==0){delay_ms(20);while(P3_2==0);delay_ms(20);KeyNumber=1;}
	if(P3_3==0){delay_ms(20);while(P3_3==0);delay_ms(20);KeyNumber=2;}
	if(P3_4==0){delay_ms(20);while(P3_4==0);delay_ms(20);KeyNumber=3;}
	if(P3_5==0){delay_ms(20);while(P3_5==0);delay_ms(20);KeyNumber=4;}
	
	return KeyNumber;
}