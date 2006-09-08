// common.h
#ifndef COMMON_H
#define COMMON_H
#include "stdtypes.h"
typedef union 
{
	UINT16 w;
	struct
	{
		UINT8 l,h;
	}b;
}Z80Reg;
inline void endianSwapUINT8(unsigned short& x)
{
    x = (x>>8) | 
        (x<<8);
}

inline void endianSwapUINT32(unsigned int& x)
{
    x = (x>>24) | 
        ((x<<8) & 0x00FF0000) |
        ((x>>8) & 0x0000FF00) |
        (x<<24);
}

#define MAX_FRAMES 60
#define XRES 160*2
#define YRES 144*2
#define Z_FLAG 0x80
#define N_FLAG 0x40
#define H_FLAG 0x20
#define C_FLAG 0x10
#define BIG_END 1


#endif
