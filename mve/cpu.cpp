#include "cpu.h"
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

void tCPU::setAF(UINT8 h,UINT8 l)
{

			AF.b.l = l;
			AF.b.h = h;

}
Z80Reg tCPU::getAF()
{
	return AF;
}
int tCPU::initCPU()
{
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