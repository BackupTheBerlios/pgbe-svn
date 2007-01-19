#include "cpu.h"
/*
Game Boy Memory Map!
MEMORY ADDRESS (in Hex)  	CONTENTS
FFFF - FFFF 	Interrupt Enable Flag (see below)
FF80 - FFFE 	Zero Page (127 bytes)
FF00 - FF7F 	Hardware Registers (see Hardware section)
FEA0 - FEFF 	Unusable Memory
FE00 - FE9F 	Object Attribute Memory (OAM)
E000 - FDFF 	Echo RAM (Reserved - Not Usable)
D000 - DFFF 	Internal RAM - Banks 1 - 7 (CGB is switchable as it has 32k Internal RAM)
C000 - CFFF 	Internal RAM - Bank 0 (fixed)
A000 - BFFF 	Switchable 8k Game Cartridge RAM
9C00 - 9FFF 	Background Display Data 2, Tile Indices/Attributes (bank switched)
9800 - 9BFF 	Background Display Data 1, Tile Indices/Attributes (bank switched)
8000 - 97FF 	Bank 0 and 1 Character Data (bank switched)
4000 - 7FFF 	User Program Area - Bank 1 to n (switchable)
0150 - 3FFF 	User Program Area - Bank 0 (fixed)
0100 - 014F 	Cartridge Header (see Cart. Header section)
0000 - 00FF 	Interrupt vectors and RST # vectors
*/
tCPU::tCPU()
{
	setActive(1);
	cout << "CPU gestartet."<<endl;
	// initCPU();
}
tCPU::~tCPU()
{
	cout << "CPU beendet."<<endl;
}

char tCPU::readMemory(int address)
{
    if((address < 0x8000)&& address >=0x0000)
        {  
            return (videoMemory[address]);
        }
    //cout << "Returned " << videoMemory[address] << " from " << hex << address << dec "." << endl;
 }

void tCPU::setAF(UINT8 h,UINT8 l)
{
			AF.b.l = l;
			AF.b.h = h;
}
Z80Reg tCPU::getAF()
{
	return AF;
}
void tCPU::setBC(UINT8 h,UINT8 l)
{
			BC.b.l = l;
			BC.b.h = h;
}
Z80Reg tCPU::getBC()
{
	return BC;
}
void tCPU::setDE(UINT8 h,UINT8 l)
{
			DE.b.l = l;
			DE.b.h = h;
}
Z80Reg tCPU::getDE()
{
	return DE;
}
void tCPU::setHL(UINT8 h,UINT8 l)
{
			HL.b.l = l;
			HL.b.h = h;
}
Z80Reg tCPU::getHL()
{
	return HL;
}
int tCPU::initCPU()
{
	memset(mainMemory,0,0x2000);
	AF.w = BC.w = DE.w = HL.w = 0;
	PSW = 0x0;
	PC.w = 0x0100;
	return(0);
}
int tCPU::getStatus()
{
	cycleCount = 8;
	cout << "Cycle Clount: " << cycleCount << endl;
	cout << "AF: " << AF.w << " BC: " << BC.w << " DE: " << DE.w << " HL: "<< HL.w << endl;
	return(0);
}
int tCPU::resetCPU()
{
	return(0);
}
int tCPU::stopCPU()
{
	active=0;
	return(0);
}
bool tCPU::setActive(bool Value)
{
	active = Value;
}
bool tCPU::getActive()
{
	return active;
}
void tCPU::execCycles(int cycles)
{
	cycleCount += cycles;
}
/*
	Z80 CPU instructions
*/
void tCPU::ADC_HLss (UINT16 Value)
{
	mainMemory[HL.w] += mainMemory[Value];
	execCycles(15);
}
void tCPU::ADC_As (UINT8 Value)
{
	AF.b.h += mainMemory[Value];
	//execCycles(15);
}

void tCPU::ADD_An (UINT8 Value)
{
	AF.b.h += Value;
	execCycles(7);
}
// 0x00
void tCPU::NOP()
{
	execCycles(4);
}
// 0x01
void tCPU::LD_BCnn(UINT16 Value) 
{
	BC.w = Value;
	execCycles(10);
}
void tCPU::LD_BCA()
{
	mainMemory[BC.w] = AF.b.h;
	execCycles(7);
}