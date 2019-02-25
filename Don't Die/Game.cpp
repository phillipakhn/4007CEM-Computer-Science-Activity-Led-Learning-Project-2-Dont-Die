#include "Game.h"
#include "TextureController.h"
#include <iostream>
#include "GameBody.h"
#include "Map.h"

using namespace std;

GameBody* character;

Map* map;

SDL_Renderer* Game::renderer = nullptr;



//SDL_Texture* playerTexture;
//SDL_Rect srcR, destR;

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
		cout << "Subsystems Initialised" << endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			cout << "Window Created" << endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{	
			SDL_SetRenderDrawColor(renderer,255,255,255,255);			
			cout << "Renderer Created" << endl;
		}
		gameRunning = true;
	}
	else
	{
		gameRunning = false; //If SDL has not been initailsed properly
	}

	//playerTexture = TextureController::LoadTexture("Images/Don'tStarve.png", renderer); // Simple texture loader youtube
	//character = new GameBody("Images/Wilson.png");
	map = new Map();
	//std::cout << Map::getRectangle() << std::endl;
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
	//character->Update();
}

void Game::render()
{
	SDL_RenderClear(renderer);

	//float zoom = 2;

	map->DrawMap();

	//SDL_RenderCopy(renderer, playerTexture, NULL, &destR); // 1st Null is how much of the texture to render, 2nd is where to place it.
	//character->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game Cleaned" << endl;
}