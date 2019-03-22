#ifndef _ENTITIES_HPP_
#define _ENTITIES_HPP_
#include <SDL.h>
#include "common.hpp"


public:
	Player();

	void SetHealthTexture(SDL_Texture* t);
	void SetPoisonTexture(SDL_Texture* t);

	virtual void Update();
	virtual void Draw(double vpx, double vpy);
	
	void SetPosition(double x, double y); // set position of the player in the map
	void SetCurrentDirection(int dir); // set direction to move to (movement is actually checked on Update())
	void MoveInvCursor(int val); // move the inventory cursor relatively
	void UseInvCursor(); // Use item in the inventory
	bool TryAddToInv(int id); // Try to add a new item to the inventory, returns true if succesfully added
	
	const double GetX();
	const double GetY();
};

class FloorItem : public Entity
{
	int id; // this object ID
	SDL_Texture* healthTexture;
	SDL_Texture* poisonTexture;
public:
	FloorItem(int ID, int X, int Y);
	
	void SetHealthTexture(SDL_Texture* t);
	void SetPoisonTexture(SDL_Texture* t);

	virtual void Draw(double vpx, double vpy);

	const int GetId();

	const double GetX();
	const double GetY();
};