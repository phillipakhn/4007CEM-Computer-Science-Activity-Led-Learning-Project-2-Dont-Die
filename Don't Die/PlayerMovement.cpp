#include "PlayerMovement.h"
#include "Database.h"
#include <vector>

//Screen dimension constants
const int LEVEL_WIDTH = 720;
const int LEVEL_HEIGHT = 510;

std::vector<int> Axis;

/*Constructor function set setup the variables to equal the values from the database
Input: N/A
Output: N/A
References: <https://www.youtube.com/watch?v=agn8GqGrCj4&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx&index=7> [online] Date Accessed 03/03/2019*/
PlayerMovement::PlayerMovement()
{
	srcRectangle.h = 32; // Setting the rectangle values
	srcRectangle.w = 32;
	srcRectangle.x = 0;
	srcRectangle.y = 0;

	Axis = Position(); // Calling the Position function in Database.cpp to return the vector containing the Axis and Map values.
	std::cout << Axis[0] << " " << Axis[1] << std::endl;
	xAxisPos = Axis[0]; // Sets the 1st (xAxis) value to xAxisPos
	yAxisPos = Axis[1]; // Sets the 2nd (yAxis) value to xAxisPos
	std::cout << Axis[2] << " " << Axis[3] << std::endl;
	xMapMovement = Axis[2]; // Sets the 3rd (xMap) value to xMapMovement
	yMapMovement = Axis[3]; // Sets the 4th (yMap) value to yMapMovement
	//This means that the player axis and map axis will be set to the values stored in the database

	destRectangle.x = xAxisPos; // Sets the destRectangle x position of the player to equal the x Axis of the player
	destRectangle.y = yAxisPos; // Sets the destRectangle y position of the player to equal the y Axis of the player
	destRectangle.w = srcRectangle.w * 2; // Sets the destRectangle w to double the scrRectangle w
	destRectangle.h = srcRectangle.h * 2; // Sets the destRectangle h to double the scrRectangle h

	yMovementM = 0;
	yMovementP = 0;
	xMovementM = 0;
	xMovementP = 0;
}
/*Function to move the player and the map via keyboard
Input: N/A
Output: N/A
References: <http://lazyfoo.net/tutorials/SDL/18_key_states/index.php> [online] Date Accessed 01/03/2019*/
void PlayerMovement::Movement()
{
	// IMPORTANT MESSAGE: The y axis is in reverse because x=0 y=0 is the top left of the engine so when y axis is increase it moves down the engine not up.

	const Uint8* Key = SDL_GetKeyboardState(NULL); // Sets key to be the current keyboard state 
		if ((Key[SDL_SCANCODE_UP] || Key[SDL_SCANCODE_W]) && yAxisPos != 0) // If Up arrow or W key is pressed and player is not at the top of the map
		{
			if (yAxisPos >= LEVEL_HEIGHT / 2 && yAxisPos <= 300 && yMapMovement > 0) /*If the yAxisPos is between the middle of the level height and 300 and the 
				yMapMovement is not 0. This is to stop the player from moving on the screen and move the map instead to show movement, however the yAxisPos still
				changes to allow the player be in the correct place once out of the range. Also prevents the yMapMovement from going below 0 which would create an error*/
			{
				yMovementP -= 1; // Decrements every call
				yMovementM -= 1; // Decrements every call
				if (yMovementP == -5) // stables player movement by only moving the yAxisPos every 5 calls  
				{
					yAxisPos -= 1; // Moves the yAxisPos by decreasing the y Axis by 1
					yMovementP = 0; // Sets the player stabler back to 0
				}
				if (yMovementM == -3) // stables map movement by only moving the map every 3 calls
				{
					yMapMovement -= 1; // Moves the map up on the screen by moving the yMap by -1
					yMovementM = 0; // Sets the player stabler back to 0
				}
			}
			else // If the yAxisPos is not in the range which means the map should not move but the player can move
			{
				yAxisPos -= 1;// Moves the player up on screen by decreasing the y Axis by 1
				destRectangle.y = yAxisPos; //Sets the destRectangle y to equal the yAxisPos to render the player y position to the screen 
			}
		}
		else if ((Key[SDL_SCANCODE_DOWN] || Key[SDL_SCANCODE_S]) && yAxisPos != 510)// If Down arrow or S key is pressed and player is not at the bottom of the map
		{
			if (yAxisPos >= LEVEL_HEIGHT / 2 && yAxisPos <= 350 && yMapMovement != 45) /*Same as line 53 but range is different and doesn't execute if the 
				yMapMovement is 45 because the map only has y value from 0 to 44*/
			{
				yMovementP += 1;  //Lines 80 to 96 are the same as 57 to 73 but increases the values instead of decreases.
				yMovementM += 1; 
				if (yMovementP == 5) 
				{
					yAxisPos += 1;
					yMovementP = 0;
				}
				if (yMovementM == 3) 
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
		else if ((Key[SDL_SCANCODE_LEFT] || Key[SDL_SCANCODE_A]) && xAxisPos != 20)// If Left arrow or A key is pressed and player is not at the far left of the map
		{
			if (xAxisPos >= LEVEL_WIDTH / 2 && xAxisPos <= 400 && xMapMovement > 0) /*If xAxisPos is between middle of level and 400 and xMapMovement is bigger than 0. 
				The reasons are the same as line 53.*/
			{
				xMovementP -= 1;//Lines 104 to 120 are the same as 57 to 73 but for x values.
				xMovementM -= 1;
				if (xMovementP == -5) 
				{
					xAxisPos -= 1;
					xMovementP = 0;
				}
				if (xMovementM == -3) 
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
		else if ((Key[SDL_SCANCODE_RIGHT] || Key[SDL_SCANCODE_D]) && xAxisPos != 720)// If Right arrow or D key is pressed and player is not at the far right of the map
		{
			if (xAxisPos >= LEVEL_WIDTH / 2 && xAxisPos <= 400 && xMapMovement != 39)/*Same as line 102 but range is different and doesn't execute if the 
				xMapMovement is 39 because the map only has yx value from 0 to 39*/
			{
				xMovementP += 1;//Lines 127 to 143 are the same as 57 to 73 but for x values and increasing the values not decreasing.
				xMovementM += 1;
				if (xMovementP == 5) 
				{
					xAxisPos += 1;
					xMovementP = 0;
				}
				if (xMovementM == 3) 
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
/*Getter function to return the vector containing Axis values and Map values
Input: N/A
Output: Vector "setPosition"*/
std::vector<int> PlayerMovement::savePosition()
{
	std::vector<int> setPosition = { xAxisPos,yAxisPos,xMapMovement, yMapMovement}; //Creates a vector to contain the Axis values and the Map values
	return setPosition;
}

/*Getter function to return xMapMovement
Input: N/A
Output: int xMapMovement*/
int PlayerMovement::getxMapMovement()
{
	return xMapMovement;
}

/*Getter function to return xyapMovement
Input: N/A
Output: int yMapMovement*/
int PlayerMovement::getyMapMovement()
{
	return yMapMovement;
}

/*Getter function to return a pointer to the address of destRectangle
Input: N/A
Output: SDL_Rect pointer to address of destRectangle 
References: <https://www.youtube.com/watch?v=agn8GqGrCj4&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx&index=7> [online] Date Accessed 03/03/2019*/
SDL_Rect* PlayerMovement::getDest()
{
	return &destRectangle;
}

/*Getter function to return a pointer to the address of scrRectangle
Input: N/A
Output: SDL_Rect pointer to address of scrRectangle
References: <https://www.youtube.com/watch?v=agn8GqGrCj4&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx&index=7> [online] Date Accessed 03/03/2019*/
SDL_Rect* PlayerMovement::getScr()
{
	return &srcRectangle;
}