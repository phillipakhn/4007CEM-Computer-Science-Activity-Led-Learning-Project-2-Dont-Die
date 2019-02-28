#include "GameBody.h"


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

/*void GameBody::UpdateObject()
{
	srcRectangle.h = 32;
	srcRectangle.w = 32;
	srcRectangle.x = 0;
	srcRectangle.y = 0;

	destRectangle.x = xPosition;
	destRectangle.y = yPosition;
	destRectangle.w = srcRectangle.w * 2;
	destRectangle.h = srcRectangle.h * 2;
}*/

/*void GameBody::Render()
{
	SDL_RenderCopy(renderer, bodyTexture, &srcRectangle, &destRectangle); // 1st Null is how much of the texture to render, 2nd is where to place it.
}*/

void GameBody::playerSetup()
{
	std::cout << " Player Setup" << std::endl;
	player = new PlayerMovement();
}

void GameBody::updatePlayer()
{
	player->Movement();
}

void GameBody::characterRender()
{
	SDL_RenderCopy(renderer, bodyTexture, player->getScr(), player->getDest());
}