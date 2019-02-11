#include "Tiles.h"
#include "Dot.h"



Tiles::Tiles(int x, int y, int tileType)
{
	box.x = x;
	box.y = y;

	box.w = TILE_WIDTH;
	box.h = TILE.HEIGHT;

	type = tileType;

}


Tiles::~Tiles()
{
}
