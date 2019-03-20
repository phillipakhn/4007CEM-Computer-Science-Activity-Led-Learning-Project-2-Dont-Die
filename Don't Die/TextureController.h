#pragma once
#include "Game.h"

class TextureController {

public:
	static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* render);
};
// Simple texture loader youtube 