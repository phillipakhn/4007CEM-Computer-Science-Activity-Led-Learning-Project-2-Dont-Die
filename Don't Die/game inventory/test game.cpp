#include "game.hpp"

#define SDL_INIT_FLAGS (SDL_INIT_VIDEO | SDL_INIT_TIMER)

// Initialize variables to default values
Game::Game() : window(nullptr), renderer(nullptr), quit(false),
               tileset(nullptr)
{}

// Startup SDL and set game state
int Game::Startup()
{
	// Initialize SDL
	if(SDL_InitSubSystem(SDL_INIT_FLAGS) != 0) // initializing fails
		return 1;
	
	if((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) // initialize SDL_image fails
		return 2;
	
	// Create window
	window = SDL_CreateWindow("RPG", SDL_WINDOWPOS_UNDEFINED, 
	         SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if(window == nullptr) // create window fails
	{
		IMG_Quit();
		SDL_QuitSubSystem(SDL_INIT_FLAGS);
		SDL_Quit();
		return 3;
	}
	
	// Create renderer inside window
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == nullptr) // create renderer fails
	{
		IMG_Quit();
		SDL_DestroyWindow(window);
		SDL_QuitSubSystem(SDL_INIT_FLAGS);
		SDL_Quit();
		return 4;
	}
	
	// enable color blending
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	
	return 0;
}

void Game::EventLoop()
{
	while(SDL_PollEvent(&e))
	{
		switch(e.type)
		{
			case SDL_KEYDOWN:
			{
				switch(e.key.keysym.sym)
				{
					// Handle player direction set
					case SDLK_d:
						player.SetCurrentDirection(DIRECTION_RIGHT);
						break;
					case SDLK_w:
						player.SetCurrentDirection(DIRECTION_UP);
						break;
					case SDLK_a:
						player.SetCurrentDirection(DIRECTION_LEFT);
						break;
					case SDLK_s:
						player.SetCurrentDirection(DIRECTION_DOWN);
						break;
					// move inventory cursor
					case SDLK_j:
						player.MoveInvCursor(-1);
						break;
					case SDLK_k:
						player.MoveInvCursor(1);
						break;
					// use inventory item
					case SDLK_l:
					case SDLK_RETURN:
						player.UseInvCursor();
						break;
					default:
						break;
				}
			}
			break;
			case SDL_QUIT: // ALT + F4, Pressing top-right X button, etc.
				quit = true;
			break;
		}
	}
}

void Game::Update()
{
	player.Update();
	
	// Update viewport
	viewportX = (player.GetX() * TILESET_TILE_SIZE) - (WINDOW_WIDTH / 2.0);
	viewportY = (player.GetY() * TILESET_TILE_SIZE) - (WINDOW_HEIGHT / 2.0);
	
	// clamp viewport so it only shows map that actually exists and not outside
	// NOTE: If you comment this code you will see black borders around the map
	
	if(viewportX < 0.0)
		viewportX = 0.0;
	else if(viewportX > FIELD_WIDTH * TILESET_TILE_SIZE - WINDOW_WIDTH)
		viewportX = FIELD_WIDTH * TILESET_TILE_SIZE - WINDOW_WIDTH;
	
	if(viewportY < 0.0)
		viewportY = 0.0;
	else if(viewportY > FIELD_HEIGHT * TILESET_TILE_SIZE - WINDOW_HEIGHT)
		viewportY = FIELD_HEIGHT * TILESET_TILE_SIZE - WINDOW_HEIGHT;
	
	// check collision with each item
	for(std::vector<FloorItem>::iterator it = items.begin(); it != items.end() ;)
	{
		if(it->GetX() == player.GetX() && it->GetY() == player.GetY())
		{
			// try to add item to inventory, if succeed, delete this object
			if(player.TryAddToInv(it->GetId()))
			{
				it = items.erase(it); // this erases the current object and returns a new iterator to the next item
				continue; // continue to the next iteration of the loop without incrementing (see below)
			}
		}
		
		// increment iterator to the next item
		it++;
	}
}

void Game::Draw()
{
	// Set color to pitch black and clear screen
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	// Draw happens here between SDL_RenderClear and SDL_RenderPresent
	
	// Draw field
	field.Draw(viewportX, viewportY);
	
	// Draw items
	for(int i = 0; i < (int)items.size(); i++)
		items[i].Draw(viewportX, viewportY);

	// Draw the player
	player.Draw(viewportX, viewportY);

	SDL_RenderPresent(renderer);
}

void Game::Shutdown()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	IMG_Quit();
	SDL_QuitSubSystem(SDL_INIT_FLAGS);
	SDL_Quit();
}

// Load tileset, etc.
int Game::LoadTextures()
{
	// First, load the image file onto memory
	SDL_Surface* tssurf = IMG_Load("assets/tileset.png");
	if(!tssurf)
		return 1;
	// then create a texture with loaded data
	tileset = SDL_CreateTextureFromSurface(renderer, tssurf);
	// free the memory used to create the texture, since the texture creation copies the data anyway
	SDL_FreeSurface(tssurf);
	// exit if the texture wasnt created
	if(tileset == nullptr)
		return 2;
	
	// repeat the same procedure for the player
	SDL_Surface* playersurf = IMG_Load("assets/player.png");
	if(!playersurf)
		return 3;
	playerTexture = SDL_CreateTextureFromSurface(renderer, playersurf);
	SDL_FreeSurface(playersurf);
	if(playerTexture == nullptr)
		return 4;
	
	// repeat with health potion
	SDL_Surface* healthsurf = IMG_Load("assets/health.png");
	if(!healthsurf)
		return 5;
	healthTexture = SDL_CreateTextureFromSurface(renderer, healthsurf);
	SDL_FreeSurface(healthsurf);
	if(healthTexture == nullptr)
		return 6;
	
	// repeat with poison potion
	SDL_Surface* poisonsurf = IMG_Load("assets/poison.png");
	if(!poisonsurf)
		return 7;
	poisonTexture = SDL_CreateTextureFromSurface(renderer, poisonsurf);
	SDL_FreeSurface(poisonsurf);
	if(poisonTexture == nullptr)
		return 8;
	
	return 0;
}

// Starts game instance on the current thread
int Game::Run()
{
	int r = Startup();
	// If something goes wrong, exit immediately with error code
	if(r > 0)
		return r;

	r = LoadTextures();
	if(r > 0)
		quit = true;

	// Set draw stuff for the field
	field.SetRenderer(renderer);
	field.SetTilesetTexture(tileset);

	// Set draw stuff for the player
	player.SetRenderer(renderer);
	player.SetTexture(playerTexture);
	player.SetHealthTexture(healthTexture);
	player.SetPoisonTexture(poisonTexture);

	// Set position for player
	player.SetPosition(5.0, 5.0);
	
	// add items
	items.push_back(FloorItem(INVENTORY_HEALTH_ID, 1, 1));
	items.back().SetRenderer(renderer);
	items.back().SetHealthTexture(healthTexture);
	items.back().SetPoisonTexture(poisonTexture);
	
	items.push_back(FloorItem(INVENTORY_POISON_ID, 3, 1));
	items.back().SetRenderer(renderer);
	items.back().SetHealthTexture(healthTexture);
	items.back().SetPoisonTexture(poisonTexture);
	// NOTE: you can add more items in a loop

	// Main game loop
	while(!quit)
	{
		EventLoop();

		Update();
		Draw();
		
		// Delay game so its ran 60 times per second
		SDL_Delay(1000 / 60);
	}

	Shutdown();

	return 0;
}
