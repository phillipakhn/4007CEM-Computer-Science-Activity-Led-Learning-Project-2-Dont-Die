#ifndef Game_h
#define Game_h
#include "SDL_image.h"
#include "SDL.h"
#include <iostream>
#include "PlayerMovement.h"
#include "TextureController.h"
#include "GameBody.h"

class Game {

public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen); 
	void handleEvents();
	void update(); // update all game objects 
	void render(); 
	void clean(); // Clear game objects from memory onced finshed with them
	bool running() { return gameRunning;} // let the main function know the game is running

private:
	bool gameRunning; 
	SDL_Window *window; 
	SDL_Renderer *renderer;
};
#endif /* Game_h*/