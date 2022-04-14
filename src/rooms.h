#ifndef _ROOMS_H
#define _ROOMS_H

//#include <rand.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "direction.h"
#include "enemy.h"
#include "player.h"
#include "powerup.h"

#define ROWS 6
#define COLS 6

/*  Each room is defined by the enemies within it and the tilemap it draws. */
typedef struct {
    /*  The list of enemies left in that room. Each room 
        has at max 16 enemies. */
    const uint8_t * tilemap;
    Enemy enemies[8];
    PowerUP powerups[8];
} Room;
extern Room * rooms[ROWS][COLS];

void generate_rooms(Player *);
void free_rooms();

#endif