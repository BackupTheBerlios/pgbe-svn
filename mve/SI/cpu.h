// 
// File:   cpu.h
// Author: pixman
//
// Created on 22. Januar 2007, 19:58
//

#ifndef _cpu_H
#define	_cpu_H
#include <iostream>
#include <string>
using namespace std;


class tCPU
{
    public:
    unsigned short pc;
    union
    {
        unsigned char pclo,pchi;
    };
    unsigned short sp;
    union
    {
        unsigned char splo,sphi;
    };
    unsigned short psw,bc,de,hl;
    union
    {
        unsigned char flags;
        unsigned char a,c,b,e,d,l,h;
    }reg;
    tCPU();
    ~tCPU();
    private:
};



#endif	/* _cpu_H */

