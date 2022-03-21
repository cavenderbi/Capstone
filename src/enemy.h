#ifndef _ENEMY_H
#define _ENEMY_H

#include "collision.h"
#include "direction.h"
#include "camera.h"

typedef struct {
    uint8_t x;
    uint8_t y;
    uint8_t health;
    Direction dir;
} Enemy;

void initEnemies(Enemy *);
void spawnEnemy(uint8_t, uint8_t, Direction, uint8_t, Enemy *);
void updateEnemies(Enemy *);
void hideEnemies();

#endif