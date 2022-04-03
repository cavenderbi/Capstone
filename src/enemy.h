#ifndef _ENEMY_H
#define _ENEMY_H

#include "collision.h"
#include "direction.h"
#include "camera.h"
#include "player.h"
#include <gb/metasprites.h>

typedef struct {
    uint8_t x_pos;
    uint8_t y_pos;
    uint8_t health;
    Direction dir;
    metasprite_t * ms; 
} Enemy;

void initEnemies(Enemy *);
void spawnEnemy(uint8_t, uint8_t, Direction, uint8_t, Enemy *);
void updateEnemies(Enemy *, Player *);
void hideEnemies();

#endif