#pragma once

#include "collision.h"
#include "direction.h"
#include "vector.h"

typedef struct {
    Direction dir;
    int x, y;
} Projectile;
Vector proj_vector;

void initProjs();
void shoot(uint8_t, uint8_t, Direction);
void updateProjs();
void drawProjs();
