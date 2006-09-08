#ifndef CART_H
#define CART_H
#include <iostream>
#include <fstream>
#include "stdtypes.h"
using namespace std;

class tCart
{
	private:
	protected:
	ifstream cartROM;
	public:
	tCart();
	~tCart();
	UINT8 loadROM(UINT8 *memory, const char *filename);
};
#endif