#ifndef __FIELD_HPP__
#define __FIELD_HPP__
#include <SDL.h>

#include "common.hpp"
#include "field_data.hpp"

class Field
{
	SDL_Renderer* renderer;
	SDL_Texture* texture;
public:
	Field();
	void SetRenderer(SDL_Renderer* r);
	void SetTilesetTexture(SDL_Texture* t);
	
	void Draw(double vpx, double vpy);
};

#endif // __FIELD_HPP__
