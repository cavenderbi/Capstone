#ifndef _ROOMS_H
#define _ROOMS_H

//#include <rand.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "direction.h"
#include "enemy.h"
#include "player.h"

#include "../res/down_left_tilemap.h"
#include "../res/down_right_tilemap.h"
#include "../res/up_left_tilemap.h"
#include "../res/up_right_tilemap.h"

/*  Each room is defined by the enemies within it and the tilemap it draws. */
struct _room {
    /*  The list of enemies left in that room. Each room 
        has at max 16 enemies. */
    uint8_t * tilemap;
    Enemy enemies[8];
};
extern struct _room rooms[9][9];

void generate_rooms(Player *);

#endif