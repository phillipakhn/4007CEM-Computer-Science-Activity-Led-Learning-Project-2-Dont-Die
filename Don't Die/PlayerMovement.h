#pragma once
#include "Game.h"
#include <vector>

class PlayerMovement {

public:
	PlayerMovement();
	~PlayerMovement();

	void Movement();

	SDL_Rect* getDest();
	SDL_Rect* getScr();
	int getxMapMovement();
	int getyMapMovement();
	int xMapMovement;
	int yMapMovement;
	std::vector<int> savePosition();

private:
	int yMovementP;
	int yMovementM;
	int xMovementP;
	int xMovementM;
	int	xAxisPos;
	int yAxisPos;
	SDL_Rect srcRectangle, destRectangle;
};