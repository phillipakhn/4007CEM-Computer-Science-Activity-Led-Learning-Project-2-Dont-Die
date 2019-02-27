#include "GameBody.h"
#include "TextureController.h"


GameBody::GameBody(const char* texturePanel)
{
	bodyTexture = TextureController::LoadTexture(texturePanel);
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
	//SDL_RenderCopy(Game::renderer, bodyTexture, &src, &dest);
	//TextureController::Draw(bodyTexture, SDL_Rect src, SDL_Rect dest);
	SDL_RenderCopy(Game::renderer, bodyTexture, NULL, NULL);
}