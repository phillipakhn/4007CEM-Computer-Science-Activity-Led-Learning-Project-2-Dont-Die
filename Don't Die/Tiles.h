#pragma once
#include "SDL.h"

class Tiles
{
public:
	Tiles();
	~Tiles();

	Tiles(int x, int y, int tileType);
	void show();
	int get_type;
	SDL_Rect get_box();

private:
	SDL_Rect box;
	int type;


};



