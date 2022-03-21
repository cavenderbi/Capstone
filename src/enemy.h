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

extern Enemy enemies[16];

void initTestEnemy();

void initEnemies();
void spawnEnemy(uint8_t, uint8_t, Direction, uint8_t);
void updateEnemies();
void hideEnemies();

#endif