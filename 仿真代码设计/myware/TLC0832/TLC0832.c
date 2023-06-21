#include "TLC0832.H"
void ADC0832_init(void)
{
    ADC0832_CS=1;//оƬ������
    ADC0832_CLK=0;
    ADC0832_DIN=0;
}

unsigned char ADC0832_ReadAD(void)
{
    unsigned char i,AD_value1=0x00,AD_value2=0x00;
    ADC0832_CS=0;//оƬ����(��ʼcs�ź�Ϊ�ߵ�ƽ)
    
    ADC0832_DIN=1;//��ʼ�ź�S
    ADC0832_CLK=1;//�����ؽ���ʼ�ź�Startд��
    ADC0832_CLK=0;
    
//----------------ͨ����ַ����----0ͨ��������ģʽ��---------------//    
    
    ADC0832_DIN=1;//mode״̬λ��1
    ADC0832_CLK=1;//��mode״̬λд��
    ADC0832_CLK=0;
    
    ADC0832_DIN=0;//ͨ��ѡ��0ͨ��
    ADC0832_CLK=1;//��ͨ��ѡ��λд��
    ADC0832_CLK=0;//��4�������½��غ�ADC0832_DIN�˿�ʧЧ,������
    
    ADC0832_DIN=1;//ADC0832_DINתΪ�ĸ���״̬�����������ߣ��ȴ��´ν������ݣ�
    
//---------------------��ȡ���Ӧ��ͨ��0��AD����--------------------------//
    ADC0832_DOUT=1;//���������ߣ��ȴ���������
    
    for(i=0;i<8;i++)//MSB
    {
        ADC0832_CLK=1;
        ADC0832_CLK=0;
        if(ADC0832_DOUT){AD_value1=AD_value1 |(0x80>>i);}//���ȶ�ȡ���λ        MSB
    }
    
    for(i=0;i<8;i++)//LSB
    {
        if(ADC0832_DOUT){AD_value2=AD_value2 |(0x01<<i);}//���ȶ�ȡ���λ        LSB
        ADC0832_CLK=1;
        ADC0832_CLK=0;
    }    

    ADC0832_DOUT=1;//���������ߣ��ȴ���������
    ADC0832_CS=1;//оƬֹͣ����
		

    return (AD_value1==AD_value2)? AD_value1:0;//�ж�ǰ�����ζ�ȡ�����Ƿ���ͬ(ǰ�������ֽ�����У��)
}


