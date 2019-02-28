#pragma once
#include "Game.h"


class GameBody {

public:
	GameBody(const char* texturePanel, SDL_Renderer* render,int xAxis ,int yAxis);
	~GameBody();

	void UpdateObject();
	void Render();
	void mapRender();
	void characterRender();
	static void updatePlayer();
	static void playerSetup();
	
	
private:

	int random;
	//int xCharacterPos;
	//int yCharacterPos;
	int xPosition;
	int yPosition;

	SDL_Texture* bodyTexture;
	//SDL_Rect srcRectangle, destRectangle;
	SDL_Renderer* renderer;

};