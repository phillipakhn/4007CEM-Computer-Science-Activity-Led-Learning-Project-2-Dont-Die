#ifndef __COMMON_HPP__
#define __COMMON_HPP__

// size of the window
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

// size in pixels of grid
#define TILESET_TILE_SIZE 32

// size of the field, this multiplied by the tile size makes the entire area
#define FIELD_WIDTH 40
#define FIELD_HEIGHT 30

// directions that the player can move in
#define DIRECTION_STOP 0
#define DIRECTION_RIGHT 1
#define DIRECTION_UP 2
#define DIRECTION_LEFT 3
#define DIRECTION_DOWN 4

// number of steps needed to move to a adjacent square
#define MOVE_STEPS 5

// health
#define HEALTH_BAR_WIDTH 200
#define HEALTH_BAR_HEIGHT 16
#define HEALTH_MAX 100
#define HEALTH_CURE_AMOUNT 20 // amount of health restored by a single "health potion"
#define HEALTH_DAMAGE_AMOUNT 15 // amount of damage done by a single "poison potion"

// inventory
#define INVENTORY_SIZE 10
#define INVENTORY_HEALTH_ID 1
#define INVENTORY_POISON_ID 2

#endif // __COMMON_HPP__
