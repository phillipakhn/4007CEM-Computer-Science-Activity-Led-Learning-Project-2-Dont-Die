#include "GameBody.h"
#include <vector>

unsigned int nextMoveTime;
unsigned int lastTime;

PlayerMovement* player;

GameBody::GameBody(const char* texturePanel, SDL_Renderer* render,int xAxis, int yAxis )
{
	renderer = render;
	bodyTexture = TextureController::LoadTexture(texturePanel, render);
	
	xPosition = xAxis;
	yPosition = yAxis;
	
	if (bodyTexture != NULL)
	{
		std::cout << texturePanel << " loaded" << std::endl;
	}
}

void GameBody::playerSetup()
{
	std::cout << " Player Setup" << std::endl;
	player = new PlayerMovement();
	lastTime = 0;
}

void GameBody::updatePlayer()
{
	player->Movement();	
}

std::vector<int> GameBody::getPosition()
{
	return player->savePosition();
}

int GameBody::getMapMovementX()
{
	return player->getxMapMovement();
}

int GameBody::getMapMovementY()
{
	return player->getyMapMovement();
}

void GameBody::characterRender()
{
	SDL_RenderCopy(renderer, bodyTexture, player->getScr(), player->getDest());
}