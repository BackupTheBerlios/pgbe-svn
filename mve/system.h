// 
// File:   system.h
// Author: pixman
//
// Created on 19. Januar 2007, 22:04
//
#include <iostream>
#include <cstdlib>
#include <string>
#define STRING_MAX 400

#ifndef SYSTEM_H
#define	SYSTEM_H

using namespace std;
class tSystem
{
    private:    
    protected:
    public:
       string description[STRING_MAX];
       tSystem();
       ~tSystem();
};
  
#endif	/* SYSTEM_H */
