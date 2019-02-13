#pragma once
#include "Game.h"


class GameBody {

public:
	GameBody(const char* texturePanel, SDL_Renderer* render);
	~GameBody();

	void Update();
	void Render();
	
private:
	int xPosition;
	int yPosition;

	SDL_Texture* bodyTexture;
	SDL_Rect srcRectangle, destRectangle;
	SDL_Renderer* renderer;

};