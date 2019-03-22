#include "SDL.h"
#include "SDL_image.h"
#include "Game.h"
#undef main
#include <chrono>
#include <thread>
#include "Database.h"

Game *game = nullptr; // Creates a null pointer called game to the Game class

/*Main function that initialises the engine and calls the functions needed to update and close the game
Input: N/A
Output: int 0
References: <https://www.youtube.com/watch?v=44tO977slsU&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx&index=3> [online] Date Accessed 01/03/2019*/
int main()
{
	game = new Game();

	game->init("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false); // Creates the engine by calling init function in Game.cpp
	
	bool fpsLimit = true;

	int fps = 60;
	if (fps == 0) 
	{
		bool fpsLimit = false;
	}
	int fpsTime = 1000 / fps;

	while (game->running()) // Called every tick to update the game.
	{
		game->handleEvents();
		game->update(); 
		game->render(); 
		if (fpsLimit)
		{
			std::this_thread::sleep_for(std::chrono::microseconds(fpsTime));
		}
	}
	game->clean(); // Called when the engine is closed.

	return 0;
}