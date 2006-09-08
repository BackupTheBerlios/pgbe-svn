#include "video.h"
tVideo::tVideo()
{
	
}
tVideo::~tVideo()
{
}
UINT32 tVideo::initVideo()
{
	screen = SDL_SetVideoMode(XRES,YRES,0,SDL_DOUBLEBUF|SDL_HWSURFACE);
}
UINT32 tVideo::flipVideo()
{
	SDL_Flip(screen);
}