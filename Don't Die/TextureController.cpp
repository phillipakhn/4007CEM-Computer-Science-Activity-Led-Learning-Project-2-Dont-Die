#include "TextureController.h"

/*Function to set and image to an SDL2 texture
Input: const char* texture, SDL_Renderer* render
Output: SDL_Texture* text
References: <https://www.youtube.com/watch?v=RqvpkZ7I1aU> [online] Date Accessed 01/03/2019*/
SDL_Texture* TextureController::LoadTexture(const char* texture, SDL_Renderer* render)
{
	SDL_Surface* tempSurface = IMG_Load(texture); // Sets the image file to a temporary surface to be converted to a texture later.
	if (tempSurface == NULL) // Checks to see if the image is converted to a surface successfully.
	{
		std::cout << texture << " Image not working" << std::endl;
	}
	else
	{
		std::cout << texture << " loaded" << std::endl;
	}
	SDL_Texture* text = SDL_CreateTextureFromSurface(render,tempSurface); // Creates a SDL2 texture from the temporary surface using the render
	SDL_FreeSurface(tempSurface); // Frees up the temporary surface for another image to be loaded.
	return text; // Returns the texture
}
