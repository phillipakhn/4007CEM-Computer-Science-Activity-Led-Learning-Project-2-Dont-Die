#ifndef __GAME_HPP__
#define __GAME_HPP__
#include <vector> // std::vector, a c++ standard container
#include <SDL.h>
#include <SDL_image.h>
#include "field.hpp"
#include "entities.hpp"

class Game
{
	// SDL variables
	SDL_Event e;
	SDL_Window* window;
	SDL_Renderer* renderer;
	
	bool quit; // Do we want to exit the game?
	
	SDL_Texture* tileset; // Texture of our tileset
	SDL_Texture* playerTexture; // Texture for our player
	SDL_Texture* healthTexture; // Texture for the health potion
	SDL_Texture* poisonTexture; // Texture for the poison potion
	
	double viewportX, viewportY; // used to control what part of the map we currently see (follows the player)
	
	// Game logic resources
	Field field; // Uses 'tileset' texture
	
	// Our main entity, the player
	Player player; // Uses 'playerTexture'
	
	// items
	std::vector<FloorItem> items;
	
	// Initialize SDL stuff
	int Startup();
	
	// Game main loop functions
	void EventLoop();
	void Update();
	void Draw();
	
	// Free resources that were initialized by Startup()
	void Shutdown();
	
	// Load textures
	int LoadTextures();
public:
	Game();
	int Run();
};

#endif // __GAME_HPP__
