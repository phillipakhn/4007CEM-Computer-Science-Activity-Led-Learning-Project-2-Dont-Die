#include "Game.h"
#include "TextureController.h"
#include <iostream>
#include "GameBody.h"
#include "Map.h"
#include "Database.h"

GameBody* character;

Map* map;

SDL_Renderer* Game::renderer = nullptr;

std::vector<int> gameState;

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialised" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window Created" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{	
			SDL_SetRenderDrawColor(renderer,255,255,255,255);			
			std::cout << "Renderer Created" << std::endl;
		}
		gameRunning = true;
	}
	else
	{
		gameRunning = false; //If SDL has not been initailsed properly
	}

	// Simple texture loader youtube
	character = new GameBody("Images/Wilson.png", renderer, 0, 0);
	map = new Map(renderer);
	GameBody::playerSetup();
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		gameRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	GameBody::updatePlayer();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap(character->getMapMovementX(),character->getMapMovementY(), true);
	character->characterRender();

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	gameState = character->getPosition();
	sqlUpdate(gameState[0], gameState[1]);
	sqlUpdateMap(gameState[2], gameState[3]);

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}