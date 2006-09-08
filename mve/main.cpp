#include <iostream>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "common.h"
#include "cpu.h"
#include "cart.h"
using namespace std;
int main(int argc, char *argv[])
{
	UINT8 nintentoLogo[] = \
	{ 0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D, 0x00, 0x0B, 0x03, 0x73, 0x00, 0x83, 0x00, 0x0C, 0x00, 0x0D,\
  	0x00, 0x08, 0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E, 0xDC, 0xCC, 0x6E, 0xE6, 0xDD, 0xDD, 0xD9, 0x99, \
 	0xBB, 0xBB, 0x67, 0x63, 0x6E, 0x0E, 0xEC, 0xCC, 0xDD, 0xDC, 0x99, 0x9F, 0xBB, 0xB9, 0x33, 0x3E};
 	 
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
