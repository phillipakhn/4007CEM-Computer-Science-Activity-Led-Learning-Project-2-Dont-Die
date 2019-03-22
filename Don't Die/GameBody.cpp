#include "GameBody.h"
#include <vector>

PlayerMovement* player; //Creates a pointer called player to the PlayerMovement class

/*Constructor function to setup the Textures passed by calling the LoadTexture function from TextureController.cpp
Input: const char* texturePanel, SDL_Renderer* render
Output: N/A#
References: <https://www.youtube.com/watch?v=agn8GqGrCj4&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx&index=7> [online] Date Accessed 03/03/2019*/
GameBody::GameBody(const char* texturePanel, SDL_Renderer* render)
{
	renderer = render;
	bodyTexture = TextureController::LoadTexture(texturePanel, render); // Calls the LoadTexture function in the TextureController class to load the given image.
	
	if (bodyTexture != NULL) // Checks to see if the texture has successfully loaded.
	{
		std::cout << texturePanel << " loaded" << std::endl;
	}
}

/*function to setup initialise a new player
Input: N/A
Output: N/A*/
void GameBody::playerSetup()
{
	std::cout << " Player Setup" << std::endl;
	player = new PlayerMovement();
}

/*Function to call the Movement function in PlayeyMovement.cpp using the given player class
Input: N/A
Output: N/A*/
void GameBody::updatePlayer()
{
	player->Movement();	
}

/*Getter function to return the vector containing the Axis and Map values from PlayerMovement.cpp
Input: N/A
Output: N/A*/
std::vector<int> GameBody::getPosition()
{
	return player->savePosition();
}

/*Getter function to return the xMapMovement from PlayerMovement.cpp
Input: N/A
Output: N/A*/
int GameBody::getMapMovementX()
{
	return player->getxMapMovement();
}

/*Getter function to return the yMapMovement from PlayerMovement.cpp
Input: N/A
Output: N/A*/
int GameBody::getMapMovementY()
{
	return player->getyMapMovement();
}

/*Function to Render the player's texture, and position to the engine screen.
Input:
Output:
References: <https://wiki.libsdl.org/SDL_RenderCopy> [online] Date Accessed 03/03/2019 & 
<https://www.youtube.com/watch?v=agn8GqGrCj4&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx&index=7> [online] Date Accessed 03/03/2019*/
void GameBody::characterRender()
{
	SDL_RenderCopy(renderer, bodyTexture, player->getScr(), player->getDest()); // the arguments are: renderer, the textue of the player, how much to render and the coordinates of where to render
}