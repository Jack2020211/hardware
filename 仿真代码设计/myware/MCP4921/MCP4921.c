#include "MCP4921.H"
unsigned int V_u16;
float SET_V;
void set_DA_MCP4921(u16 num){
	
	 char i;
	if(num>=4096)
		num=4096;
	num|=0x7000;
	 LDAC=1;
	DA_CLK=0;
	DA_CS=0;
	for(i=15;i>=0;i--){
		DA_DATA=num&(0x01<<i);
		DA_CLK=0;
		_nop_();
		DA_CLK=1;
		_nop_();
	}
	_nop_();
	DA_CS=1;
  LDAC=0;
	 LDAC=1;
   
   
}
void Set_V(float V){
	SET_V=V;
	//set_DA_MCP4921(V*819);
	
	V_u16=V*828;//826;//819.2;//817.6;//5.00*2^12
	
	
}
void Set_I(unsigned int mA){
	float V=(float)mA*0.0025;//2.5/1000;
	Set_V(V);

	
}


