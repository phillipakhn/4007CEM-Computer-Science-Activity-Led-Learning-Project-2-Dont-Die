#include "TextureController.h"


SDL_Texture* TextureController::LoadTexture(const char* texture)
{

	SDL_Surface* tempSurface = IMG_Load(texture);
	if (tempSurface == NULL)
	{
		std::cout << "Image not working" << std::endl;

	}

	SDL_Texture* text = SDL_CreateTextureFromSurface(Game::renderer,tempSurface);
	SDL_FreeSurface(tempSurface);

	return text;
}

void TextureController::Draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
	//std::cout << "Render" << std::endl;
}

// Simple texture loader youtube