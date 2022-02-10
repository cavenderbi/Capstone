#pragma once

#include "collision.h"
#include "direction.h"
#include "node.h"

#include <malloc.h>

typedef struct {
    Direction dir;
    int x, y; 
    bool alive;
} Projectile;
// Head of the list of projectiles.
struct Node * proj_head;

void shoot(uint8_t, uint8_t, Direction);
void update_projs();
