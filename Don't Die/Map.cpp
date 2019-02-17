#include "Map.h"
#include "TextureController.h"
#include "GenerateMap.h"

int world[20][25] = {  //matrix for the world but will be read from a database in the future
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
			world[row][column] == arr[row][column];
		}
	}
}

void Map::DrawMap() {
	int type = 0;
	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 25; column++) {

			type = world[row][column];

			dest.x = column * 32;
			dest.y = row * 32;

			//std::cout << type << std::endl;

			

			switch (type) {
			case 0: //renders the grass texture
				TextureController::Draw(grass, src, dest);
				//std::cout << "Grass Rendered" << std::endl;
				break;
			case 1: //renders the water
				TextureController::Draw(water, src, dest);
				//std::cout << "Water Rendered" << std::endl;
				break;
			case 2: //renders any trees
				TextureController::Draw(tree, src, dest);
				//std::cout << "Tree Rendered" << std::endl;
				break;
			case 3: //renders the long grass
				TextureController::Draw(longGrass, src, dest);
				//std::cout << "Long Grass Rendered" << std::endl;
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
