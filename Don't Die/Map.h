#pragma once
#include "Game.h"


class Map
{
public:
	Map();
	~Map();

	//float zoom = 2;

	void LoadMap(int arr[32][32]);
	void DrawMap();


private:

	SDL_Rect src, dest;
	SDL_Texture* grass;
	SDL_Texture* water;
	SDL_Texture* tree;
	SDL_Texture* longGrass;

	int map[32][32];

};

