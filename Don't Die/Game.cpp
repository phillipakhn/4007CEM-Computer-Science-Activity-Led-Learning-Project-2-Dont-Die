#include "Game.h"
#include "TextureController.h"
#include <iostream>
#include "GameBody.h"
#include "Map.h"
#include "Database.h"

GameBody* character; //Initialise a pointer to GameBody class called character

Map* map; //Initialise a pointer to Map class called map

SDL_Renderer* Game::renderer = nullptr; //Initialise a null pointer to Game class

std::vector<int> gameState; //Initialise vector called gameState

Game::Game() //Constructor
{}
Game::~Game()//Deconstructor
{}

/*Function to set up the SDL2 engine and initialise instances of classes
Input: const char *title, int xpos, int ypos, int width, int height, bool fullscreen
Output: N/A
References: <https://www.youtube.com/watch?v=44tO977slsU&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx&index=3> [Online] Date Accessed 01/03/2019*/
void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	
	if (fullscreen) //If fullcreen is true
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) //If the SDL2 is working
	{
		std::cout << "Subsystems Initialised" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags); // Create and SDL2 engine window
		if (window) //If the window has been created 
		{
			std::cout << "Window Created" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0); //Create a renderer with the window just made
		if (renderer)//If the renderer has been created
		{	
			SDL_SetRenderDrawColor(renderer,255,255,255,255); //Set the colour of the renderer which in this case is white			
			std::cout << "Renderer Created" << std::endl;
		}
		gameRunning = true;
	}
	else
	{
		gameRunning = false; //If SDL2 has not been initialised properly
	}
	character = new GameBody("Images/Wilson.png", renderer); //Creates a new instance of GameBody called character
	map = new Map(renderer); //Creates a new instance of Map called map
	GameBody::playerSetup(); //Calls the function playerSetup in GameBody.cpp to initialise the player values
}

/*Function to check if the game is running
Input: N/A
Output: N/A
References: <https://www.youtube.com/watch?v=44tO977slsU&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx&index=3> [Online] Date Accessed 01/03/2019*/
void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT: //If SDL Quit is true gameRunning is set to false to close the game
		gameRunning = false;
		break;
	default: //If SDL Quit is not true break
		break;
	}
}

/*Function to call updatePlayer in GameBody.cpp each time it is called from main function in main.cpp
Input: N/A
Output: N/A*/
void Game::update()
{
	GameBody::updatePlayer();
}

/*Function called from main function in main.cpp to call each of the SDL2 Render functions needed to render everything to the engine window.
Input: N/A
Output: N/A
References: <https://www.youtube.com/watch?v=44tO977slsU&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx&index=3> [Online] Date Accessed 01/03/2019*/
void Game::render()
{
	SDL_RenderClear(renderer); // Clears the renderer
	map->DrawMap(character->getMapMovementX(),character->getMapMovementY(), true); //Renders the map by calling DrawMap in Map.cpp, passing arguments from the getter functions in GameBody.cpp 
	character->characterRender(); //Calls characterRender function in GameBody.cpp to render the character instance.
	SDL_RenderPresent(renderer); //Updates the screen with any rendering performed since the previous call.
}

/*Function to Update the Database, close SDL and quit the engine.
Input: N/A
Output: N/A
References: <https://www.youtube.com/watch?v=44tO977slsU&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx&index=3> [Online] Date Accessed 01/03/2019*/
void Game::clean()
{
	gameState = character->getPosition(); // Call the getPosition function in "Database.cpp" and sets the returned vector gameState.
	sqlUpdate(gameState[0], gameState[1]); // Calls the sqlUpdate function and passes the 1st (xAxis) and 2nd (yAxis) values of the gameState vector
	sqlUpdateMap(gameState[2], gameState[3]); // Calls the sqlUpdateMap function and passes the 3rd (xMap) and 4th (yMap) values of the gameState vector
	SDL_DestroyWindow(window); // Destroys the engine window
	SDL_DestroyRenderer(renderer); // Destroys the SDL2 renderer
	SDL_Quit(); // Quits the engine
	std::cout << "Game Cleaned" << std::endl;
}