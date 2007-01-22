#include "cpu.h"
tCPU::tCPU()
{
    cout << "New Intel 8080 CPU created." << endl;
    tCPU::pc = 0x100;
}