#include "GameBody.h"
#include "TextureController.h"


GameBody::GameBody(const char* texturePanel, SDL_Renderer* render)
{
	renderer = render;
	bodyTexture = TextureController::LoadTexture(texturePanel, render);
	if (bodyTexture != NULL)
	{
		std::cout << "Texture loaded" << std::endl;
	}
}

void GameBody::Update()
{
	xPosition = 0;
	yPosition = 0;

	srcRectangle.h = 32;
	srcRectangle.w = 32;
	srcRectangle.x = 0;
	srcRectangle.y = 0;

	destRectangle.x = xPosition;
	destRectangle.y = yPosition;
	destRectangle.w = srcRectangle.w * 2;
	destRectangle.h = srcRectangle.h * 2;
}

void GameBody::Render()
{
	SDL_RenderCopy(renderer, bodyTexture, NULL, NULL);
}