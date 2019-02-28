#include "TextureController.h"


SDL_Texture* TextureController::LoadTexture(const char* texture, SDL_Renderer* render)
{

	SDL_Surface* tempSurface = IMG_Load(texture);
	if (tempSurface == NULL)
	{
		std::cout << texture << " Image not working" << std::endl;
	}
	else
	{
		std::cout << texture << " loaded" << std::endl;
	}

	SDL_Texture* text = SDL_CreateTextureFromSurface(render,tempSurface);
	SDL_FreeSurface(tempSurface);

	return text;
}

// Simple texture loader youtube 