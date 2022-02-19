#pragma once

#include <stdint.h>

#include "direction.h"

typedef struct _entity {
    uint8_t health;
    uint16_t x_pos, y_pos;
    Direction dir;
} Entity;

void spawn_entity(Entity *, uint8_t, uint16_t, uint16_t, Direction);
void move_entity(Entity *, Direction, uint8_t);