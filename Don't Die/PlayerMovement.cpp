#include "PlayerMovement.h"
#include "Database.h"
#include <vector>

const int LEVEL_WIDTH = 720;
const int LEVEL_HEIGHT = 510;

std::vector<int> Axis;

//Screen dimension constants

PlayerMovement::PlayerMovement()
{
	srcRectangle.h = 32;
	srcRectangle.w = 32;
	srcRectangle.x = 0;
	srcRectangle.y = 0;

	Axis = Position();
	std::cout << Axis[0] << " " << Axis[1] << std::endl;
	xAxisPos = Axis[0];
	yAxisPos = Axis[1];
	std::cout << Axis[2] << " " << Axis[3] << std::endl;
	xMapMovement = Axis[2];
	yMapMovement = Axis[3];

	if (xAxisPos >= LEVEL_WIDTH / 2 && xAxisPos <= 400)
	{
		destRectangle.x = xAxisPos;
	}
	else
	{
		destRectangle.x = xAxisPos;
	}

	if (yAxisPos >= LEVEL_HEIGHT / 2 && yAxisPos <= 300 )
	{
		destRectangle.y = yAxisPos;
	}
	else
	{
		destRectangle.y = yAxisPos;
	}
	
	destRectangle.w = srcRectangle.w * 2;
	destRectangle.h = srcRectangle.h * 2;

	yMovementM = 0;
	yMovementP = 0;
	xMovementM = 0;
	xMovementP = 0;
}

void PlayerMovement::Movement()
{
	const Uint8* Key = SDL_GetKeyboardState(NULL); //http://lazyfoo.net/tutorials/SDL/18_key_states/index.php
		if ((Key[SDL_SCANCODE_UP] || Key[SDL_SCANCODE_W]) && yAxisPos != 0)
		{
			if (yAxisPos >= LEVEL_HEIGHT / 2 && yAxisPos <= 300 && yMapMovement > 0)
			{
				yMovementP -= 1;
				yMovementM -= 1;
				if (yMovementP == -5) // stable player movement 
				{
					yAxisPos -= 1;
					yMovementP = 0;
				}
				if (yMovementM == -3) // stable map movement
				{
					yMapMovement -= 1;
					yMovementM = 0;
				}
			}
			else
			{
				yAxisPos -= 1;
				destRectangle.y = yAxisPos;
			}
		}
		else if ((Key[SDL_SCANCODE_DOWN] || Key[SDL_SCANCODE_S]) && yAxisPos != 510)
		{
			if (yAxisPos >= LEVEL_HEIGHT / 2 && yAxisPos <= 350 && yMapMovement != 45)
			{
				yMovementP += 1;
				yMovementM += 1;
				if (yMovementP == 5) // stable player movement 
				{
					yAxisPos += 1;
					yMovementP = 0;
				}
				if (yMovementM == 3) // stable map movement
				{
					yMapMovement += 1;
					yMovementM = 0;
				}
			}
			else
			{
				yAxisPos += 1;
				destRectangle.y = yAxisPos;
			}
		}
		else if ((Key[SDL_SCANCODE_LEFT] || Key[SDL_SCANCODE_A]) && xAxisPos != 20)
		{
			if (xAxisPos >= LEVEL_WIDTH / 2 && xAxisPos <= 400 && xMapMovement != 0)
			{
				xMovementP -= 1;
				xMovementM -= 1;
				if (xMovementP == -5) // stable player movement 
				{
					xAxisPos -= 1;
					xMovementP = 0;
				}
				if (xMovementM == -3) // stable map movement
				{
					xMapMovement -= 1;
					xMovementM = 0;
				}
			}
			else
			{
				xAxisPos -= 1;
				destRectangle.x = xAxisPos;
			}
		}
		else if ((Key[SDL_SCANCODE_RIGHT] || Key[SDL_SCANCODE_D]) && xAxisPos != 720)
		{
			if (xAxisPos >= LEVEL_WIDTH / 2 && xAxisPos <= 400 && xMapMovement != 39)
			{
				xMovementP += 1;
				xMovementM += 1;
				if (xMovementP == 5) // stable player movement 
				{
					xAxisPos += 1;
					xMovementP = 0;
				}
				if (xMovementM == 3) // stable map movement
				{
					xMapMovement += 1;
					xMovementM = 0;
				}
			}
			else
			{
				xAxisPos += 1;
				destRectangle.x = xAxisPos;
			}
		}
}

std::vector<int> PlayerMovement::savePosition()
{
	std::vector<int> setPosition = { xAxisPos,yAxisPos,xMapMovement, yMapMovement};
	return setPosition;
}

int PlayerMovement::getxMapMovement()
{
	return xMapMovement;
}

int PlayerMovement::getyMapMovement()
{
	return yMapMovement;
}

SDL_Rect* PlayerMovement::getDest()
{
	return &destRectangle;
}

SDL_Rect* PlayerMovement::getScr()
{
	return &srcRectangle;
}