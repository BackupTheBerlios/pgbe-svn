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