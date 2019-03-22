#pragma once
#include "Game.h"
#include <vector>

class GameBody {

public:
	GameBody(const char* texturePanel, SDL_Renderer* render);
	~GameBody();

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