#ifndef _COLLISION_H
#define _COLLISION_H

#include <stdbool.h>
#include <gb/gb.h>
#include <types.h>

#include "direction.h"

bool sprite_sprite_collision(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
bool sprite_tile_collision(uint16_t, uint16_t, Direction);

#endif