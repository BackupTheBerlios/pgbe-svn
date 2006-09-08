#include "cart.h"

tCart::tCart()
{
};
tCart::~tCart()
{
}
UINT16 tCart::checkROMsize(const char *filename)
{
	char temp;
	cartROM.open(filename,ios::binary|ios::in);
	cartROM.seekg(0x148,ios::beg);
	cartROM.get(temp);
	switch ((UINT16)temp)
	{
		case 0:
		cout << "32KB"<<endl;
		romMemory = (UINT8*) malloc(0x8000);
		break;
		case 1:
		cout << "64KB"<<endl;
		romMemory = (UINT8*) malloc(0x10000);
		break;
		case 2:
		cout << "128KB"<<endl;
		romMemory = (UINT8*) malloc(0x20000);
		break;
		case 3:
		cout << "256KB"<<endl;
		romMemory = (UINT8*) malloc(0x40000);
		break;
		case 4:
		cout << "512KB"<<endl;
		romMemory = (UINT8*) malloc(0x80000);
		break;
		default:
		cout << "Couldn't find a correct value for the ROM Size" << endl;
		break;
	}
	cartROM.close();
	return (UINT16)temp;
}
UINT8 tCart::loadROM(const char *filename)
{
	
	char temp;
	cartROM.open(filename,ios::binary|ios::in);
	cartROM.seekg(0,ios::beg);
	
	for(UINT32 byteCount=0;byteCount!=0xFFFF;byteCount++)
	{
		cartROM.get(temp);
		romMemory[byteCount] = (UINT8) temp;
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
		name[byteCount] =  romMemory[0x134+byteCount];
	}
	cout << "The Program Name is: " << name << endl;
}