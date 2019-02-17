#pragma once
#include "Game.h"

class TextureController {

public:
	static SDL_Texture* LoadTexture(const char* filename);
	static void Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest);
};

// Simple texture loader youtube 