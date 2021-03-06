#include <iostream>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "common.h"
#include "cpu.h"
using namespace std;
int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Surface *screen;
	screen=SDL_SetVideoMode(800,600,0,SDL_HWSURFACE|SDL_DOUBLEBUF);
	int running=1;
	char *tmp;
	UINT32 mainMemory = (UINT32) malloc(0x2000);
	tCPU *cpu;
	cpu = new tCPU();
	cpu->mainMemory = &mainMemory;
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
