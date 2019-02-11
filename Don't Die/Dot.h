#pragma once
#include "SDL.h"
#include "Tiles.h"

class Dot
{
public:
	Dot();
	~Dot();

	


private:
	SDL_Rect box;
	int xVel, yVel;

	//Dot();

	void handle_input();

	void move(Tiles *tiles[]);

	void show();

	void set_camera();

};

