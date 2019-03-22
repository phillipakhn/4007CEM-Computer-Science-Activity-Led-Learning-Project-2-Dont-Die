#include "entities.hpp"

#include "common.hpp"

#include <cmath> // for std::round

// Entity implementation
Entity::Entity()
{
	
}

void Entity::SetRenderer(SDL_Renderer* r)
{
	renderer = r;
}

void Entity::SetTexture(SDL_Texture* t)
{
	texture = t;
}

void Entity::Update()
{}

void Entity::Draw(double vpx, double vpy)
{}

// Player implementation
Player::Player()
{
	direction = DIRECTION_STOP;
	moveStep = 0;
	health = 30;
	
	// Set inventory to empty
	for(int i = 0; i < INVENTORY_SIZE; i++)
		inventory[i] = 0;
	
	inventory_selected = 0;
	
	// Add some default items
	inventory[2] = 1;
	inventory[3] = 2;
	inventory[4] = 1;
	inventory[5] = 1;
	inventory[6] = 2;
	
	healthTexture = nullptr;
	poisonTexture = nullptr;
}

void Player::SetHealthTexture(SDL_Texture* t)
{
	healthTexture = t;
}

void Player::SetPoisonTexture(SDL_Texture* t)
{
	poisonTexture = t;
}

void Player::Update()
{
	// We are currently not moving
	if(moveStep == 0)
	{
		// If direction was changed by user we need to check if adjacent square is passable
		// in order to start movement, in this case we just check map boundings
		if(direction == DIRECTION_RIGHT && x + 1.0 <= FIELD_WIDTH - 1.0)
			moveStep = MOVE_STEPS;
		else if(direction == DIRECTION_UP && y - 1.0 >= 0.0)
			moveStep = MOVE_STEPS;
		else if(direction == DIRECTION_LEFT && x - 1.0 >= 0.0)
			moveStep = MOVE_STEPS;
		else if(direction == DIRECTION_DOWN && y + 1.0 <= FIELD_HEIGHT - 1.0)
			moveStep = MOVE_STEPS;
		else // We didnt find any suitable movement, stop
			direction = DIRECTION_STOP;
	}
	else if(moveStep > 0) // If we are moving, decrease movement counter and actually move
	{
		moveStep--;
		
		// if this is the last step
		if(moveStep == 0)
		{
			// round our coordinates
			x = std::round(x);
			y = std::round(y);
			
			// set direction to stop
			direction = DIRECTION_STOP;
			
			// exit prematurely to avoid any further movement
			return;
		}
		
		// perform move step in the selected direction
		if(direction == DIRECTION_RIGHT)
			x += 1.0 / MOVE_STEPS;
		else if(direction == DIRECTION_UP)
			y -= 1.0 / MOVE_STEPS;
		else if(direction == DIRECTION_LEFT)
			x -= 1.0 / MOVE_STEPS;
		else if(direction == DIRECTION_DOWN)
			y += 1.0 / MOVE_STEPS;
	}
}

void Player::Draw(double vpx, double vpy)
{
	// location where we will draw the player
	// the location is multiplied and then rounded by using the cast operator
	SDL_Rect dstRect = {(int)(x * TILESET_TILE_SIZE - vpx), (int)(y * TILESET_TILE_SIZE - vpy), TILESET_TILE_SIZE, TILESET_TILE_SIZE};
	SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
	
	// draw healthbar
	dstRect.x = 16;
	dstRect.y = WINDOW_HEIGHT - 64;
	dstRect.w = HEALTH_BAR_WIDTH;
	dstRect.h = 16;
	
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // red
	SDL_RenderFillRect(renderer, &dstRect); // draw red part of the healthbar
	
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // green
	dstRect.w = ((double)health / HEALTH_MAX) * HEALTH_BAR_WIDTH;
	SDL_RenderFillRect(renderer, &dstRect); // draw green part of the healthbar
	
	// draw inventory items
	dstRect.x = 16;
	dstRect.y = WINDOW_HEIGHT - 32;
	dstRect.w = 16;
	dstRect.h = 16;
	for(int i = 0; i < INVENTORY_SIZE; i++)
	{
		SDL_SetRenderDrawColor(renderer, 64, 64, 64, 255); // dark-grey
		SDL_RenderFillRect(renderer, &dstRect);

		switch(inventory[i])
		{
			case INVENTORY_HEALTH_ID:
				SDL_RenderCopy(renderer, healthTexture, nullptr, &dstRect);
			break;
			case INVENTORY_POISON_ID:
				SDL_RenderCopy(renderer, poisonTexture, nullptr, &dstRect);
			break;
		}

		if(inventory_selected == i)
		{
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 128); // light green, to highlight selection
			SDL_RenderFillRect(renderer, &dstRect);
		}

		dstRect.x += dstRect.w + 4;
	}
}

void Player::SetPosition(double X, double Y)
{
	x = X;
	y = Y;
}

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
