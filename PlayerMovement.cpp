#include "PlayerMovement.h"

const int LEVEL_WIDTH = 1280;
const int LEVEL_HEIGHT = 960;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

PlayerMovement::PlayerMovement()
{
	srcRectangle.h = 32;
	srcRectangle.w = 32;
	srcRectangle.x = 0;
	srcRectangle.y = 0;

	destRectangle.x = 0;
	destRectangle.y = 0;
	destRectangle.w = srcRectangle.w * 2;
	destRectangle.h = srcRectangle.h * 2;
	xPlayerPos = 0;
	yPlayerPos = 0;

}

void PlayerMovement::Movement()
{
	//destRectangle.x = xPosition;
	//destRectangle.y = yPosition;
	
	//destRectangle.x = 0;
	//destRectangle.y = 0;

	const Uint8* Key = SDL_GetKeyboardState(NULL); //http://lazyfoo.net/tutorials/SDL/18_key_states/index.php

	if (Key[SDL_SCANCODE_UP] || Key[SDL_SCANCODE_W])
	{
		yPlayerPos -= 1;
	}
	else if (Key[SDL_SCANCODE_DOWN] || Key[SDL_SCANCODE_S])
	{
		yPlayerPos += 1;
	}
	else if (Key[SDL_SCANCODE_LEFT] || Key[SDL_SCANCODE_A])
	{
		xPlayerPos -= 1;
	}
	else if (Key[SDL_SCANCODE_RIGHT] || Key[SDL_SCANCODE_D])
	{
		xPlayerPos += 1;
	}

	if (xPlayerPos > SCREEN_WIDTH / 2 && yPlayerPos > SCREEN_HEIGHT / 2)
	{
		destRectangle.x = SCREEN_WIDTH / 2;
		destRectangle.y = SCREEN_HEIGHT / 2;
	}
	else if (xPlayerPos > SCREEN_WIDTH / 2)
	{
		destRectangle.x = SCREEN_WIDTH / 2;
		destRectangle.y = yPlayerPos;
	}
	else if (yPlayerPos > SCREEN_HEIGHT / 2)
	{
		destRectangle.x = xPlayerPos;
		destRectangle.y = SCREEN_HEIGHT / 2;
	}
	else
	{
		destRectangle.x = xPlayerPos;
		destRectangle.y = yPlayerPos;
	}
	//std::cout << xPlayerPos << std::endl;
}


SDL_Rect* PlayerMovement::getDest()
{
	return &destRectangle;
}

SDL_Rect* PlayerMovement::getScr()
{
	return &srcRectangle;
}
