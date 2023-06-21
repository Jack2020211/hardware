#include "MAX1241.H"
u16 read_max1241()
{
	u16 voltage=0;		 //���12λ������
	u8 cont12=12;	     //12λ
	AD_CS=1;
	AD_CLK=0;
	AD_CS=0;
	while(AD_DATA==0);       //ת������
	AD_CLK=1;
	AD_CLK=0;
	while(cont12--)
	{
		AD_CLK=1;              //SCLK�����������ȶ�������
		voltage<<=1;    
		if(AD_DATA==1)
			voltage+=1;
		AD_CLK=0;
	}	 
	AD_CS=1;
	return voltage;
}
float read_max1241_V(){
	float V;
	u16 tt;
	tt=read_max1241();
	V=(float)tt/816;//816;//813.5;//5.015*2^12
	return V;
	
}