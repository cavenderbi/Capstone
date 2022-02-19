#pragma once

#include "collision.h"
#include "direction.h"

const int max_projs = 16;

typedef struct {
    Direction dir;
    uint8_t x, y;
    bool valid;
} Projectile;
struct {
    Projectile array[16];
    uint8_t count;
} projectiles;

void initProjs();
void shoot(uint8_t, uint8_t, Direction);
void updateProjs();
