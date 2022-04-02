#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include <stdint.h>

#include "camera.h"
#include "collision.h"
#include "direction.h"
#include "rooms.h"
#include "dmgtype.h"

typedef struct {
    Direction dir;
    uint8_t x, y;
    uint8_t dmg;
    bool valid;
    PWR_TYPE type;

} Projectile;
extern Projectile projectiles[4];

void initProjs();
void shoot(uint8_t, uint8_t, Direction, PWR_TYPE);
void updateProjs(Enemy *);

#endif