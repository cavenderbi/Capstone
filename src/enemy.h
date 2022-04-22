#ifndef _ENEMY_H
#define _ENEMY_H

#include "collision.h"
#include "direction.h"
#include "camera.h"
#include "player.h"
#include <gb/metasprites.h>

typedef struct {
    uint16_t x_pos;
    uint16_t y_pos;
    uint8_t health;
    Direction dir;
} Enemy;

void spawnEnemy(uint16_t, uint16_t, Direction, uint8_t, Enemy *);
void updateEnemies(Enemy *, Player *);

#endif