#include <iostream>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "common.h"
#include "cpu.h"
#include "cart.h"
#include "video.h"
#include "main.h"
using namespace std;
bool tCPU::running=1;
int main(int argc, char *argv[])
{ 	 

	SDL_Init(SDL_INIT_VIDEO);
	tVideo *vid;
	vid = new tVideo();
	vid->initVideo();
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
SDL_keysym keysym;
float startTime;
float curTime;
float neededTime;
float checkTime;
int fps=0;
int temp;

UINT32 cycleFrame = 70224;
for(int i=0;i!=XRES;i++)
{
	for(int j=0;j!=YRES;j++)
	{
		vid->drawPixel(i,j,i,j,i);
	}
}

while(tCPU::running)
{
	startTime = SDL_GetTicks();
		while(SDL_PollEvent(&event)) 
		{
		switch(event.type)
		{
			case SDL_KEYDOWN:
                            
				keysym=event.key.keysym;
				switch(keysym.sym)
				{
					case SDLK_ESCAPE:
                                              cout << "Read something: " << cpu->readMemory(0x4000) <<endl;

					tCPU::running = 0;
					break;
					case SDLK_f:
					// Windows- & Linux-specific
					vid->toggleFullScreen();
					break;
					default:
					break;
				}
					
			break;
			case SDL_QUIT:
				tCPU::running = 0;
				break;
		
		}
	
		}
		vid->flipVideo();
		
	if (cpu->cycleCount >= cycleFrame)
		{
			checkTime = SDL_GetTicks();
			cout <<"Check: " << checkTime << endl;
			neededTime = SDL_GetTicks();
			cout << "Needed: " << neededTime <<endl;
			while(neededTime-checkTime >= 16)
			{
				
			}
				vid->flipVideo();
				cout << "Updated"<<endl;
				cpu->cycleCount = 0;
			//cout << (neededTime-checkTime) << endl;
		}
		cpu->ADC_HLss(0x0102);
		
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
cpu->getStatus();
delete vid;
delete cpu;
delete cart;
atexit(SDL_Quit);
}
