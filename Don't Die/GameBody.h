#pragma once
#include "Game.h"


class GameBody {

public:
	GameBody(const char* texturePanel);
	~GameBody();

	void Update();
	void Render();
	
private:
	int xPosition;
	int yPosition;

	SDL_Texture* bodyTexture;
	SDL_Rect srcRectangle, destRectangle;

};