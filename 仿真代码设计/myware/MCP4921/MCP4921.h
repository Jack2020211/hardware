#include "public.h"
sbit DA_CLK=P2^1;
sbit DA_DATA=P2^2;
sbit DA_CS=P2^0;
sbit LDAC=P2^3;

void set_DA_MCP4921(u16 num);
void Set_V(float V);//单位V
void Set_I(unsigned int mA);//单位mA