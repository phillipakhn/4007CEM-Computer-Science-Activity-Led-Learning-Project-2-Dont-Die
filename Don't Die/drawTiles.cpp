#include "drawTiles.h"



drawTiles::~drawTiles()
{
}

void drawTiles::Draw(SDL_Texture * texture, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(Game::renderer, texture, &src, &dest);
}