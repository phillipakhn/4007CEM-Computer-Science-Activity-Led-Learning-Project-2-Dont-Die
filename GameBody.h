#pragma once
#include "Game.h"
#include <vector>

class GameBody {

public:
	GameBody(const char* texturePanel, SDL_Renderer* render,int xAxis ,int yAxis);
	~GameBody();

	void UpdateObject();
	void Render();
	void characterRender();
	int getMapMovementX();
	int getMapMovementY();
	std::vector<int> getPosition();
	static void updatePlayer();
	static void playerSetup();
	
private:
	int random;
	int xPosition;
	int yPosition;

	SDL_Texture* bodyTexture;
	SDL_Renderer* renderer;
};