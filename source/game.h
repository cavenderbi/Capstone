#pragma once

// Include the gameboy functions. 
#include <gb/gb.h>
#include <gb/cgb.h>
// Booleans are nice to have.
#include <stdbool.h>
#include <stdio.h>
// Include the title screen. 
#include "title_screen.c"

// Include the sprites defined in their respective C folders. 
// Thanks to GBTD for letting me not have to write 8x8 sprites in hex by hand.
#include "../sprites/arrow.c"
#include "../sprites/test_projectile.c"
#include "../sprites/test_enemy.c"

// Include the tiles and tilemap for the HUD. 
#include "../sprites/hud.c"
#include "../tilemaps/hud.c"

#include "../sprites/test.c"
#include "../tilemaps/test.c"

#define FRAMES_ANIM_UPDATE 10

typedef enum Direction { UP, DOWN, LEFT, RIGHT, NONE } Direction;
// Using a player struct to clean up the code a bit.
struct Player {
    // x and y positions
    uint8_t x;
    uint8_t y;
    // player direction
    Direction dir;
    // health values
    uint8_t maxHealth;
    uint8_t health;
    // is player alive?
    bool alive;
} player;

struct Projectile {
    uint8_t x;
    uint8_t y;
    Direction dir;
    uint8_t speed;
    bool alive;
} projectile;

struct TestEnemy {
    UBYTE x;
    UBYTE y; 
    Direction dir;
    UBYTE health;
} testEnemy;

void initPlayer();
void initTestEnemy();
void shoot(uint8_t, uint8_t, Direction);
inline bool collision(UBYTE, UBYTE, Direction);
inline bool spritecollision(UBYTE, UBYTE, UBYTE, UBYTE, UBYTE, UBYTE, UBYTE, UBYTE);
void input();
void logic();
void draw();