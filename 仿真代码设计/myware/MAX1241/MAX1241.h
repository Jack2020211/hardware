#ifndef	_MAX1241_H_
#define	_MAX1241_H_
#include "public.h"
sbit AD_DATA=P1^2;
sbit AD_CLK=P1^0;
sbit AD_CS=P1^1;
u16 read_max1241();
float read_max1241_V();
#endif