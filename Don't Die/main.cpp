#include "SDL.h"
#include "SDL_image.h"
#include "Game.h"
#include <chrono>
#include <thread>
#undef main

Game *game = nullptr;

int main(int argc, char *args[])
{
	game = new Game();

	bool fpsLimit = true;

	int fps = 150;
	if (fps == 0) {
		bool fpsLimit = false;
	}
	int frameTime = 1000 / (fps*1.08);

	game->init("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	
	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
		if (fpsLimit) {
			std::this_thread::sleep_for(std::chrono::milliseconds(frameTime)); 
			}
	}

	game->clean();

	return 0;
}