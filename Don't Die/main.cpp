#include "SDL.h"
#include "SDL_image.h"
#include "Game.h"
#undef main
#include <chrono>
#include <thread>
#include "Database.h"

Game *game = nullptr;

int main(int argc, char *args[])
{
	game = new Game();

	game->init("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	
	bool fpsLimit = true;

	int fps = 60;
	if (fps == 0)
	{
		bool fpsLimit = false;
	}
	int fpsTime = 1000 / fps;

	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
		if (fpsLimit)
		{
			std::this_thread::sleep_for(std::chrono::microseconds(fpsTime));
		}
	}
	game->clean();

	return 0;
}