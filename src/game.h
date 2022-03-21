#ifndef _GAME_H
#define _GAME_H

// Include the gameboy functions. 
#include <gb/gb.h>
#include <gb/cgb.h>
#include <gb/drawing.h>
// Booleans are nice to have.
#include <stdbool.h>
#include <stdio.h>
// Include the title screen. 
#include "logo_splash.h"
#include "title_screen.h"
#include "camera.h"
#include "collision.h"
#include "direction.h"
#include "enemy.h"
#include "projectile.h"
#include "player.h"
#include "sprites.h"
#include "rooms.h"

#define FRAMES_ANIM_UPDATE 10

Player player;

void initPlayer();
inline void input();
inline void logic();
inline void draw(uint8_t);

#endif