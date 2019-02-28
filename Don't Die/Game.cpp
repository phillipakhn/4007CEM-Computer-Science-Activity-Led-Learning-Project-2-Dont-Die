#include "Game.h"
#include "TextureController.h"
#include <iostream>
#include "GameBody.h"
#include "Map.h"


GameBody* character;

Map* map;

SDL_Renderer* Game::renderer = nullptr;

GameBody* background;

//PlayerMovement* player;

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
	character = new GameBody("Images/Wilson32.png", renderer, 0, 0);
	//background = new GameBody("Images/Background.png", renderer, 0, 0);
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
	//background->UpdateObject();
	//character->UpdateCharacter();
	//map->(renderer);
	

	GameBody::updatePlayer();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap(0, 0, false);
	//background->mapRender();
	character->characterRender();

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}