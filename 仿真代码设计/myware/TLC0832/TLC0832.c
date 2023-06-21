#include "TLC0832.H"
void ADC0832_init(void)
{
    ADC0832_CS=1;//芯片不工作
    ADC0832_CLK=0;
    ADC0832_DIN=0;
}

unsigned char ADC0832_ReadAD(void)
{
    unsigned char i,AD_value1=0x00,AD_value2=0x00;
    ADC0832_CS=0;//芯片工作(初始cs信号为高电平)
    
    ADC0832_DIN=1;//起始信号S
    ADC0832_CLK=1;//上升沿将起始信号Start写入
    ADC0832_CLK=0;
    
//----------------通道地址设置----0通道（单端模式）---------------//    
    
    ADC0832_DIN=1;//mode状态位置1
    ADC0832_CLK=1;//将mode状态位写入
    ADC0832_CLK=0;
    
    ADC0832_DIN=0;//通道选择0通道
    ADC0832_CLK=1;//将通道选择位写入
    ADC0832_CLK=0;//第4个脉冲下降沿后，ADC0832_DIN端口失效,无作用
    
    ADC0832_DIN=1;//ADC0832_DIN转为改高阻状态（数据线拉高，等待下次接收数据）
    
//---------------------读取相对应的通道0的AD数据--------------------------//
    ADC0832_DOUT=1;//数据线拉高，等待接收数据
    
    for(i=0;i<8;i++)//MSB
    {
        ADC0832_CLK=1;
        ADC0832_CLK=0;
        if(ADC0832_DOUT){AD_value1=AD_value1 |(0x80>>i);}//优先读取最高位        MSB
    }
    
    for(i=0;i<8;i++)//LSB
    {
        if(ADC0832_DOUT){AD_value2=AD_value2 |(0x01<<i);}//优先读取最低位        LSB
        ADC0832_CLK=1;
        ADC0832_CLK=0;
    }    

    ADC0832_DOUT=1;//数据线拉高，等待接收数据
    ADC0832_CS=1;//芯片停止工作
		

    return (AD_value1==AD_value2)? AD_value1:0;//判断前后两次读取数据是否相同(前后两个字节数据校验)
}


