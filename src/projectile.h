#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "camera.h"
#include "collision.h"
#include "direction.h"
#include "rooms.h"

typedef struct {
    Direction dir;
    uint8_t x, y;
    bool valid;
} Projectile;
extern Projectile projectiles[16];

void initProjs();
void shoot(uint8_t, uint8_t, Direction);
void updateProjs(Enemy * enemies);

#endif