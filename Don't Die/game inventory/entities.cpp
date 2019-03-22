#include "entities.hpp"

#include "common.hpp"

#include <cmath> // for std::round



void Player::SetCurrentDirection(int dir)
{
	// change current direction, only if we are stopped
	if(direction == DIRECTION_STOP)
		direction = dir;
}

void Player::MoveInvCursor(int val)
{
	inventory_selected += val;
	
	// clamp selection
	if(inventory_selected < 0)
		inventory_selected = 0;
	else if(inventory_selected > INVENTORY_SIZE - 1)
		inventory_selected = INVENTORY_SIZE - 1;
}

void Player::UseInvCursor()
{
	// different behaviour depending on the item
	switch(inventory[inventory_selected])
	{
		case INVENTORY_HEALTH_ID:
			inventory[inventory_selected] = 0; // "remove" the item from inventory
			health += HEALTH_CURE_AMOUNT;
			break;
		case INVENTORY_POISON_ID:
			inventory[inventory_selected] = 0;
			health -= HEALTH_DAMAGE_AMOUNT;
			break;
		default:
			break;
	}
	
	// clamp health
	if(health > HEALTH_MAX)
		health = HEALTH_MAX;
	else if(health < 0)
		health = 0;
}

bool Player::TryAddToInv(int id)
{
	for(int i = 0; i < INVENTORY_SIZE; i++)
	{
		if(inventory[i] == 0) // if we found an empty slot
		{
			// add item and return true
			inventory[i] = id;
			return true;
		}
	}
	
	// we didnt find any spot to place the object in
	return false;
}

const double Player::GetX()
{
	return x;
}

const double Player::GetY()
{
	return y;
}

// Health and Poison potion
FloorItem::FloorItem(int ID, int X, int Y)
{
	id = ID;
	// NOTE: values cannot have a decimal part, this is to ensure the player can grab them
	x = X;
	y = Y;
}

void FloorItem::SetHealthTexture(SDL_Texture* t)
{
	healthTexture = t;
}

void FloorItem::SetPoisonTexture(SDL_Texture* t)
{
	poisonTexture = t;
}

void FloorItem::Draw(double vpx, double vpy)
{
	// location where we will draw the item
	// the positioning is the same as with the player
	SDL_Rect dstRect = {(int)(x * TILESET_TILE_SIZE - vpx), (int)(y * TILESET_TILE_SIZE - vpy), TILESET_TILE_SIZE, TILESET_TILE_SIZE};
	
	switch(id)
	{
		case INVENTORY_HEALTH_ID:
			SDL_RenderCopy(renderer, healthTexture, nullptr, &dstRect);
			break;
		case INVENTORY_POISON_ID:
			SDL_RenderCopy(renderer, poisonTexture, nullptr, &dstRect);
			break;
		default: // try to draw default texture in case ID is invalid
			SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
			break;
	}
}

const int FloorItem::GetId()
{
	return id;
}

const double FloorItem::GetX()
{
	return x;
}

const double FloorItem::GetY()
{
	return y;
}