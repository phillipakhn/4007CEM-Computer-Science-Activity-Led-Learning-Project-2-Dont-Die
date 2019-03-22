#include "field.hpp"

Field::Field()
{
	
}

void Field::SetRenderer(SDL_Renderer* r)
{
	renderer = r;
}

void Field::SetTilesetTexture(SDL_Texture* t)
{
	texture = t;
}

void Field::Draw(double vpx, double vpy)
{
	// Tile area we will draw
	static SDL_Rect srcRect = {0, 0, TILESET_TILE_SIZE, TILESET_TILE_SIZE};
	// Area where will we draw taken tile
	static SDL_Rect dstRect = {0, 0, TILESET_TILE_SIZE, TILESET_TILE_SIZE};
	
	for(int i = 0; i < FIELD_WIDTH; i++)
	{
		for(int j = 0; j < FIELD_HEIGHT; j++)
		{
			// get the absolute coordinate fo this tile
			int tile = FIELD_BG_1[j][i];
			
			// select from source texture the right tile
			srcRect.x = (tile % 16) * TILESET_TILE_SIZE;
			srcRect.y = (tile / 16) * TILESET_TILE_SIZE;
			
			// transform that position according to the viewport
			dstRect.x = i * TILESET_TILE_SIZE - vpx;
			dstRect.y = j * TILESET_TILE_SIZE - vpy;

			// finally draw that single tile
			SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
		}
	}
}
