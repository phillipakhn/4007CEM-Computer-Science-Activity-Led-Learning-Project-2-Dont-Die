#include "mapMove.h"



mapMove::mapMove(int movedx, int movedy)
{
	SDL_Event event;
	SDL_WaitEvent(&event);

	switch (event.type)
	{
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_LEFT:  
			movedx--; 
			break;
		case SDLK_RIGHT: 
			movedx++; 
			break;
		case SDLK_UP:    
			movedy--; 
			break;
		case SDLK_DOWN: 
			movedy++; 
			break;
		}
		break;
	}
}


mapMove::~mapMove()
{
}
