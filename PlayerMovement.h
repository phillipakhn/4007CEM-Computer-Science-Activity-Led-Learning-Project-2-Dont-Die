#pragma once
#include "Game.h"

class PlayerMovement {

public:
	PlayerMovement();
	~PlayerMovement();

	void Movement();

	SDL_Rect* getDest();
	SDL_Rect* getScr();



private:
	int xPlayerPos;
	int yPlayerPos;
	SDL_Rect srcRectangle, destRectangle;
};