#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
#include <SDL/SDL.h>
#include "common.h"
#include "stdtypes.h"
using namespace std;

class tVideo
{
	private:
	protected:
	public:
	SDL_Surface *screen;
	tVideo();
	~tVideo();
	UINT32 initVideo();
	UINT32 flipVideo();
	
};
#endif