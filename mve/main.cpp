#include <iostream>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "common.h"
#include "cpu.h"
#include "cart.h"
using namespace std;
int main(int argc, char *argv[])
{ 	 
	bool draw=false;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Surface *screen;
	screen=SDL_SetVideoMode(XRES,YRES,0,SDL_HWSURFACE|SDL_DOUBLEBUF);
	int running=1;
	char *tmp;
	UINT32 *mainMemory;
/*	mainMemory = (UINT32*) malloc(0x2000);
	romMemory = (UINT32*) malloc(0xFFFF);*/
	tCPU *cpu;
	cpu = new tCPU();
	tCart *cart;
	cart = new tCart();
	cpu->mainMemory = (UINT32*) malloc(0x2000);//mainMemory;
	cart->ROMSize = cart->checkROMsize("mario1.gb"); // Allocate memory & set the ROMSize value
	//cart->romMemory = (UINT8*) malloc(0x10000);
	cpu->initCPU();
	cart->loadROM("mario1.gb");
	cart->printProgramName();
	cout << "Z80 Engine started."<<endl;
	//cpu->AF.b.l = 0x40;
	cpu->setAF(0x20,0x40);
	cout << "A von AF = " << hex << (int) cpu->AF.b.l<<endl;
	cout << "F von AF = " << hex << (int) cpu->AF.b.h<<endl;
	cout << "AF = " << hex << cpu->AF.w<< endl;
SDL_Event event;
float startTime;
float curTime;
int fps=0;
int temp;

int lostCycles=0;
int freeCycles=0;
int lastCycle=0;

while(running)
{
	startTime = SDL_GetTicks();
		while(SDL_PollEvent(&event)) 
		{
		switch(event.type)
		{
			case SDL_KEYDOWN:
				running = 0;
				break;
			case SDL_QUIT:
				running = 0;
				break;
		
		}
	
		}
		SDL_Flip(screen);
		//cpu->ADC_HL(0x0102);
	curTime = SDL_GetTicks();
	fps++;
	if((curTime-startTime) >= 1000/MAX_FRAMES) 
	{ 
		temp = fps; 
		fps = 0; 
		startTime = curTime;
	}
//	cout << "Current FPS is at: "<<dec<< temp << endl;
	
}
atexit(SDL_Quit);
}
