#include "Map.h"
#include "TextureController.h"
#include "GenerateMap.h"

int world[32][32] = {  //matrix for the world but will be read from a database in the future
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,3,0,3,0,2,2,0,1,2,0,1,0,3,0,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1},
	{1,2,0,0,1,0,2,3,2,3,3,0,2,2,0,0,2,0,0,1,0,0,2,0,0,0,2,0,3,0,0,1},
	{1,2,0,0,2,2,2,0,0,3,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,2,1},
	{1,0,0,0,0,3,2,0,2,2,3,2,3,2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,1},
	{1,2,0,0,0,0,3,3,0,0,0,2,0,0,0,2,2,0,0,0,0,2,2,3,0,0,2,2,0,2,0,1},
	{1,0,2,3,2,0,0,0,2,0,0,0,1,2,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1},
	{1,0,0,3,0,3,0,2,0,0,0,0,2,0,0,3,2,2,0,0,0,0,2,2,0,0,2,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,0,1,0,0,0,0,0,2,0,0,2,0,2,3,0,0,2,2,2,3,0,1},
	{1,0,3,0,0,2,0,1,0,0,0,3,0,0,2,3,1,2,0,3,2,0,2,0,0,2,2,0,0,1,0,1},
	{1,0,2,3,0,0,0,1,0,0,0,0,0,3,2,0,2,0,0,0,0,2,0,2,2,0,0,0,1,0,0,1},
	{1,2,0,1,0,0,0,0,2,2,1,0,0,0,0,0,3,3,3,0,0,2,2,0,0,0,3,3,1,3,0,1},
	{1,0,2,2,0,0,0,0,2,2,3,2,2,3,0,0,0,1,0,0,0,0,0,3,2,0,0,1,0,3,2,1},
	{1,0,0,0,0,2,0,3,0,0,0,0,0,1,0,0,0,0,3,2,0,3,3,2,1,3,3,2,0,3,0,1},
	{1,0,0,1,0,0,2,0,0,0,3,2,2,0,0,0,0,0,2,0,0,3,2,0,0,3,0,3,2,2,3,1},
	{1,1,0,2,0,3,0,0,0,0,3,0,3,0,0,0,3,2,2,0,2,0,0,2,0,0,0,0,0,0,1,1},
	{1,2,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,3,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,2,0,0,0,0,3,0,3,0,0,0,2,0,3,0,0,0,0,2,0,0,1,1,0,0,2,0,0,1},
	{1,0,3,0,0,2,0,0,2,2,3,2,0,0,0,2,0,0,2,0,0,0,0,0,2,0,2,3,0,0,2,1},
	{1,3,3,3,0,0,3,3,3,2,0,2,0,3,0,0,2,2,0,0,0,0,0,1,0,0,0,3,2,2,0,1},
	{1,0,0,0,0,0,2,2,0,0,0,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,3,0,0,1},
	{1,0,0,0,2,3,0,0,3,2,0,0,0,3,0,2,0,0,0,0,0,2,0,0,0,0,2,2,2,1,0,1},
	{1,0,1,0,2,2,0,0,1,2,0,3,0,0,0,1,0,2,0,0,3,2,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,0,0,0,0,0,3,0,0,2,2,3,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,2,2,1},
	{1,0,2,3,0,0,2,2,0,0,0,0,0,0,2,0,0,1,0,2,2,2,0,0,3,1,3,0,0,0,0,1},
	{1,0,3,0,2,2,0,2,0,2,0,0,0,0,0,1,1,0,2,0,0,0,2,0,2,0,2,0,0,0,0,1},
	{1,0,2,2,0,2,0,0,0,0,0,3,3,2,2,0,2,2,0,0,3,3,0,2,0,2,2,0,0,0,2,1},
	{1,2,2,0,2,0,0,0,3,3,0,0,0,2,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,2,0,1},
	{1,3,2,2,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,3,2,0,2,0,3,0,0,0,2,0,0,1},
	{1,0,0,2,0,1,1,0,0,0,0,0,2,0,0,0,0,0,2,0,3,2,0,0,0,3,2,1,0,0,0,1},
	{1,0,0,3,1,3,1,0,0,0,0,0,0,0,0,2,0,3,3,1,0,0,0,0,0,2,0,0,3,0,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

Map::Map()
{
	grass = TextureController::LoadTexture("Images/grass.png");
	water = TextureController::LoadTexture("Images/water.png");
	tree = TextureController::LoadTexture("Images/tree.png");
	longGrass = TextureController::LoadTexture("Images/longGrass.png");

	LoadMap(world);

	float zoom = 0.7;
	int zoomSize = 32 * zoom;

	src.x = src.y = 0;
	src.w = dest.w = zoomSize;
	src.h = dest.h = zoomSize;

	dest.x = dest.y = 0;
}


void Map::LoadMap(int arr[32][32]) {
	for (int row = 0; row < 32; row++) {
		for (int column = 0; column < 32; column++) {
			world[row][column] == arr[row][column];
		}
	}
}

void Map::DrawMap() {
	int type = 0;
	int xmoved = 0; //MOVE ELSEWHERE
	int ymoved = 0; //MOVE ELSEWHERE
	for (int row = ymoved; row < (32+ymoved); row++) { 
		for (int column = xmoved; column < (32+xmoved); column++) {

			type = world[row][column];

			float zoom = 0.7;
			int zoomSize = 32 * zoom;

			dest.x = (column - xmoved) * zoomSize; //zoomSize;
			dest.y = (row-ymoved) * zoomSize;

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
