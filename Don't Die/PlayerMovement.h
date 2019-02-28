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
	int xMapPos;
	int yMapPos;
	SDL_Rect srcRectangle, destRectangle;
};