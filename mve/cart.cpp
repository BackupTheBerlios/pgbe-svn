#include "cart.h"

tCart::tCart()
{
};
tCart::~tCart()
{
}
UINT8 tCart::loadROM(UINT8 *memory, const char *filename)
{
	char temp;
	cartROM.open(filename,ios::binary|ios::in);
	cartROM.seekg(0,ios::beg);
	
	for(UINT32 byteCount=0;byteCount!=0xFFFF;byteCount++)
	{
		cartROM.get(temp);
		memory[byteCount] = (UINT8) temp;
	}
	cout << "ROM loaded from " << filename <<endl;	
	cartROM.close();
	return (0);
}
void tCart::printProgramName()
{
	char name[0x10];
	for(int byteCount=0;byteCount!=0x0F;byteCount++)
	{
		name[byteCount] = (char) romMemory[0x134+byteCount];
	}
	cout << "The Program Name is: " << name << endl;
}