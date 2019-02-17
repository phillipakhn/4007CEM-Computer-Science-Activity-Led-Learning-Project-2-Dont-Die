#include "Map.h"
#include "TextureController.h"

int world[20][25] = {
	{1,2,0,1,2,1,2,1,1,1,3,2,1,1,3,0,3,3,0,3,1,3,2,3,0},
	{3,1,3,0,1,1,0,0,1,1,1,0,3,1,2,3,3,3,2,1,3,2,1,1,2},
	{0,0,0,0,3,3,3,2,3,1,3,0,3,2,0,0,1,2,1,3,2,1,2,2,3},
	{0,2,1,3,0,2,0,0,3,3,3,0,2,3,1,2,1,3,2,3,3,0,3,1,3},
	{1,0,2,3,3,0,1,3,2,3,1,3,3,1,3,2,3,0,2,3,0,2,2,3,0},
	{0,1,0,1,2,2,1,0,2,0,3,1,0,2,3,2,2,1,1,1,3,2,1,3,1},
	{0,0,0,1,1,1,3,3,0,0,0,2,0,2,1,3,2,0,0,1,3,1,3,0,2},
	{3,3,2,2,2,2,0,2,3,2,1,1,3,2,1,1,2,3,2,2,1,2,2,3,0},
	{1,2,3,1,2,3,3,2,3,3,1,3,1,2,2,3,1,1,3,3,0,1,1,1,3},
	{3,3,2,2,2,3,0,1,2,2,1,3,3,0,1,3,1,2,3,1,2,0,2,1,2},
	{0,1,3,0,3,0,3,2,0,1,2,0,0,1,1,0,1,1,1,1,0,0,0,2,2},
	{1,0,0,0,1,3,1,0,2,2,2,3,0,0,0,3,3,1,0,2,1,2,2,1,2},
	{3,1,0,3,1,3,1,3,3,0,2,3,2,1,0,2,1,3,1,0,2,2,3,3,3},
	{0,0,1,1,0,1,3,3,2,2,1,0,0,2,2,3,1,1,2,3,2,2,2,3,1},
	{0,1,2,2,2,1,2,2,2,0,1,1,1,2,2,2,3,0,0,2,2,3,0,3,3},
	{2,2,1,0,3,1,2,0,3,0,2,3,2,1,3,1,1,1,3,2,0,2,3,2,3},
	{2,1,1,3,1,0,3,0,1,2,2,1,2,1,0,0,0,3,3,1,1,3,3,3,1},
	{2,3,0,1,0,2,1,1,3,1,3,3,3,2,1,1,2,0,1,0,3,0,2,0,2},
	{1,0,1,0,3,3,2,0,0,2,1,1,0,2,0,0,3,3,1,0,3,1,1,2,0},
	{2,3,2,2,2,3,2,2,1,0,2,0,3,3,0,3,0,1,2,3,2,0,2,2,3}
};

Map::Map()
{
	grass = TextureController::LoadTexture("Images/grass.png");
	water = TextureController::LoadTexture("Images/water.png");
	tree = TextureController::LoadTexture("Images/tree.png");
	longGrass = TextureController::LoadTexture("Images/longGrass.png");

	LoadMap(world);

	src.x = src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;

	dest.x = dest.y = 0;
}


void Map::LoadMap(int arr[20][25]) {
	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 25; column++) {
			map[row][column] == arr[row][column];
		}
	}
}

void Map::DrawMap() {
	int type = 0;
	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 25; column++) {
			type = map[row][column];

			dest.x = column * 32;
			dest.y = row * 32;


			switch (type) {
			case 0:
				TextureController::Draw(grass, src, dest);
				break;
			case 1:
				TextureController::Draw(water, src, dest);
				break;
			case 2:
				TextureController::Draw(tree, src, dest);
				break;
			case 3:
				TextureController::Draw(longGrass, src, dest);
				break;
			default:
				break;
			}
		}
	}
}

Map::~Map()
{
}
