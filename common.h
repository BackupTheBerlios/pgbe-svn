// common.h
#ifndef COMMON_H
#define COMMON_H
#include "stdtypes.h"
typedef union 
{
	short int w;
	struct
	{
		UINT8 l,h;
	}b;
}Z80Reg;
#define MAX_FRAMES 60
#define Z_FLAG 0x80
#define N_FLAG 0x40
#define H_FLAG 0x20
#define C_FLAG 0x10
#endif