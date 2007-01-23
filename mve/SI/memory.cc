#include "memory.h"

tMemory::tMemory()
{
    mem = new unsigned char[0x4000];
    cout << "Memory [0x4000 Bytes] allocated/created."<<endl;
}
tMemory::~tMemory()
{
    cout << "Memory destroyed."<<endl;
    delete[] mem;
}