#include "SDL.h"
#include "SDL_image.h"
#include "Game.h"
#include "mapMove.h"
#include <chrono>
#include <thread>
#undef main

Game *game = nullptr;

int main(int argc, char *args[])
{
	game = new Game();

	bool fpsLimit = true;

	int fps = 40;
	if (fps == 0) {
		bool fpsLimit = false;
	}
	int frameTime = 1000 / (fps*1.08);

	game->init("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	int movedx = 0;
	int movedy = 0;
	bool night = false;
	int time = 0;
	float daynight = 30;

//mapMove *movedx = nullptr;
	//mapMove *movedy = nullptr;
	
	while (game->running())
	{
		if (time >= fps * daynight) {
			night = true;
		}
		if (time >= fps * (daynight*2)) {
			time = 0;
			night = false;
		}
		
		SDL_Event event;
		SDL_PollEvent(&event);

		switch (event.type)
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_LEFT:
				if (movedx-1 != -1) {
					movedx--;
				}
				break;
			case SDLK_RIGHT:
				if (movedx + 1 != 40) {
					movedx++;
				}
				break;
			case SDLK_UP:
				if (movedy - 1 != -1) {
					movedy--;
				}
				break;
			case SDLK_DOWN:
				if (movedy + 1 != 45) {
					movedy++;
				} 
				break;
			}
			break;
		}


		game->handleEvents();
		game->update();
		game->render(movedx, movedy, night);
		time++;
		if (fpsLimit) {
			std::this_thread::sleep_for(std::chrono::milliseconds(frameTime)); 
			}
	}

	game->clean();

	return 0;
}