#ifndef	_TLC0832_H_
#define	_TLC0832_H_
#include "public.h"
sbit ADC0832_CS=P1^3;
sbit ADC0832_CLK=P1^4;
sbit ADC0832_DOUT=P1^5;
sbit ADC0832_DIN=P1^6;
void ADC0832_init(void);
//u8 ADC_read_data();
unsigned char ADC0832_ReadAD(void);
#endif