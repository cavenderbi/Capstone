#pragma once

// Include the gameboy functions. 
#include <gb/gb.h>
#include <gb/cgb.h>
#include <gb/drawing.h>
// Booleans are nice to have.
#include <stdbool.h>
#include <stdio.h>
// Include the title screen. 
#include "title_screen.c"


#include "collision.c"
#include "direction.h"
#include "enemy.c"
#include "projectile.c"

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

#include "../tilemaps/testroom_tilemap2.c"
#include "../sprites/testroomtiles.c"

#define FRAMES_ANIM_UPDATE 10

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
} player;

void initPlayer();
inline void input();
inline void logic();
inline void draw(uint8_t);
