#ifndef CPU_H
#define CPU_H
#include <iostream>
#include "common.h"

using namespace std;
class tCPU
{
	private:
	
	protected:
	//Z80Reg AF,BC,DE,HL;
	
	
	UINT16 irqAddress;
	UINT32 irqEnabled;
	UINT32 irqPending;
	
	public:	
	tCPU();
	~tCPU();
	Z80Reg AF,BC,DE,HL, IX, IY;
	UINT8 PSW;
	UINT16 SP;
	UINT16 PC;
	UINT32 *mainMemory;
	UINT32 cycleCount;
	bool active;
	
	void setAF(UINT8 h, UINT8 l);
	Z80Reg getAF();
	int initCPU();
	int resetCPU();
	int stopCPU();
	bool setActive(bool Value);
	bool getActive();
	void execCycles(int cycles);
	void ADC_HLss(UINT16 Value);
	void ADC_As(UINT8 Value);
	void ADD_An(UINT8 Value);
};
#endif