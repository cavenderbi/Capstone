#pragma once

#include "collision.h"
#include "direction.h"
//#include "node.h"

//#include <malloc.h>

typedef struct {
    Direction dir;
    int x, y;
} Projectile;
// Head of the list of projectiles.
/* struct Node * proj_head;
int new_index = 0;

void shoot(uint8_t, uint8_t, Direction);
void update_projs(); */
