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
	/*UINT8 ZPSflag;
	UINT8 CFlag;*/
	Z80Reg SP;
	Z80Reg PC;
        Z80Reg result;
	UINT16 RAMSize;
	UINT32 *mainMemory;
	UINT32 *videoMemory;
	//UINT8 *romMemory;
	UINT32 cycleCount;
	bool active;
	static bool running;
        char readMemory(int address);
	void setAF(UINT8 h, UINT8 l);
	Z80Reg getAF();
	void setBC(UINT8 h, UINT8 l);
	Z80Reg getBC();
	void setDE(UINT8 h, UINT8 l);
	Z80Reg getDE();
	void setHL(UINT8 h, UINT8 l);
	Z80Reg getHL();
	
	int initCPU();
	int getStatus();
	int resetCPU();
	int stopCPU();
	bool setActive(bool Value);
	bool getActive();
	void execCycles(int cycles);
	void ADC_HLss(UINT16 Value);
	void ADC_As(UINT8 Value);
	void ADD_An(UINT8 Value);
	void LD_BCnn(UINT16 Value);
	void LD_BCA();
	void NOP();
};
#endif
