#pragma once
#pragma once
#include "Game.h"

class drawTiles
{
public:
	drawTiles();
	~drawTiles();
	static void Draw(SDL_Texture * texture, SDL_Rect src, SDL_Rect dest);
};
