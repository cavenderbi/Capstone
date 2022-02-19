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
#include "entity.h"
#include "enemy.c"
#include "projectile.c"
#include "sprites.h"

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

typedef struct {
    Entity player, enemies[16];
    struct _map {
        uint8_t x_pos, y_pos;
    } map, old_map;
    struct _camera {
        uint16_t x_pos, y_pos;
    } camera, old_camera;
} Game;
int i = sizeof(Game);

void initPlayer();
inline void input();
inline void logic();
inline void draw(uint8_t);
