#include "Tiles.h"
#include "Dot.h"

//Tile constants
const int TILE_WIDTH = 80;
const int TILE_HEIGHT = 80;
const int TOTAL_TILES = 192;
const int TILE_SPRITES = 12;

//The different tile sprites
const int TILE_RED = 0;
const int TILE_GREEN = 1;
const int TILE_BLUE = 2;
const int TILE_CENTER = 3;
const int TILE_TOP = 4;
const int TILE_TOPRIGHT = 5;
const int TILE_RIGHT = 6;
const int TILE_BOTTOMRIGHT = 7;
const int TILE_BOTTOM = 8;
const int TILE_BOTTOMLEFT = 9;
const int TILE_LEFT = 10;
const int TILE_TOPLEFT = 11;


Tiles::Tiles(int x, int y, int tileType)
{
	box.x = x;
	box.y = y;

	box.w = TILE_WIDTH;
	box.h = TILE_HEIGHT;

	type = tileType;

}

void Tiles::show() {
	/*if (check_collision(camera, box) == True) {
		apply_surface(box.x - camera.x, box.y - camera.y, tileSheet, screen, &clips[type]);
	}*/
}


Tiles::~Tiles()
{
}