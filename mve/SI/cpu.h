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
    union
    {
        unsigned short pc;
        struct
        {
            unsigned char pclo,pchi;
        };
    
    };
    
    
    union
    {
        unsigned short sp;
        struct
        {
            unsigned char splo,sphi;  
        };
    };
     union
    {   
    unsigned short psw,bc,de,hl;

        struct
        {
            unsigned char a,flags,b,c,d,e,h,l;  
        }
          
    }reg;
    int cycles;
    unsigned short result;
    unsigned char irq;
    unsigned char irqpending;
    unsigned char aux;
    tCPU();
    ~tCPU();
    private:
};



#endif	/* _cpu_H */

