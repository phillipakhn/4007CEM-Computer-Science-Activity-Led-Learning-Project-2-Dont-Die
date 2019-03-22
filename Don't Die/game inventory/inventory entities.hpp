#ifndef __ENTITIES_HPP__
#define __ENTITIES_HPP__
#include <SDL.h>
#include "common.hpp"

class Entity
{
protected:
	double x, y;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
public:
	Entity();
	void SetRenderer(SDL_Renderer* r);
	void SetTexture(SDL_Texture* t);
	
	virtual void Update(); // virtual means it can be replaced by a inheriting class (there is more to it)
	virtual void Draw(double vpx, double vpy);
};

// NOTE: we are inheriting from entity, as does FloorItem
class Player : public Entity
{
	int direction; // direction we are currently moving in (not facing direction)
	int moveStep; // number of steps remaining to complete movement to a different square
	
	int health; // health we currently have
	int inventory[INVENTORY_SIZE]; // inventory items
	int inventory_selected; // currently selected item
	
	SDL_Texture* healthTexture;
	SDL_Texture* poisonTexture;
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

#endif // __ENTITIES_HPP__
