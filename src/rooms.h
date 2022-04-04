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

/*  Each room is defined by the enemies within it and the tilemap it draws. */
typedef struct {
    /*  The list of enemies left in that room. Each room 
        has at max 16 enemies. */
    uint8_t * tilemap;
    Enemy enemies[8];
    PowerUP powerups[8];
} Room;
extern Room * rooms[4][4];

void generate_rooms(Player *);

#endif