#pragma once

// Game Strings
#define GAME_TITLE "GEC Mario"

// Dimesions
#define SCREEN_WIDTH					512
#define SCREEN_HEIGHT					410

#define TILE_WIDTH						32
#define TILE_HEIGHT						32
#define MAP_HEIGHT						13
#define MAP_WIDTH						17

// Movement Constants
#define MOVEMENT_SPEED					0.03
#define MOVEMENT_SPEED_INCREASE_RIGHT	200.0f
#define MOVEMENT_SPEED_INCREASE_LEFT	-200.0f
#define MAX_MOVEMENT_SPEED				80.0f

#define PLAYER_GRAVITY					250
#define JUMP_FORCE_DECREMENT			380.0f
#define INITIAL_JUMP_FORCE				530
#define COLLISION_FORCE					2.5f

#define INJURED_TIME					2.5f
#define INITIAL_JUMP_FORCE_SMALL		250
#define ENEMY_TIMER						20000.0f
#define PLAYER_ANIMATION_DELAY			0.05
#define ANIMATION_DELAY					0.15

// Others
#define SCREENSHAKE_DURATION			0.25f
#define MUSIC_TIMER						30000.0f
#define START_TIMER						32000.0f
#define POWBLOCK_HIT_TIMER				1000.0f