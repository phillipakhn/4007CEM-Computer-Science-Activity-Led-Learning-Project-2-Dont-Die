#pragma once
#include "Game.h"

class Map
{
public:
	Map(SDL_Renderer * render);
	~Map();

	//float zoom = 2;

	void LoadMap(int arr[64][64]);
	void DrawMap(int xmoved, int ymoved, bool night);
	//static SDL_Rect* getRectangle();

private:

	int xmoved;
	int ymoved;
	bool night;

	SDL_Rect scr, dest;
	SDL_Texture* grass;
	SDL_Texture* darkGrass;
	SDL_Texture* water;
	SDL_Texture* darkWater;
	SDL_Texture* tree;
	SDL_Texture* darkTree;
	SDL_Texture* longGrass;
	SDL_Texture* darkLongGrass;
	SDL_Texture* fire;
	SDL_Texture* fireGrass;
	SDL_Texture* fireTree;
	SDL_Texture* fadedFire;

	int map[32][32];
};