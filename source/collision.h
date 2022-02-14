#pragma once

#include <stdbool.h>
#include <gb/gb.h>
#include <types.h>

#include "direction.h"

inline bool sprite_sprite_collision(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
inline bool sprite_tile_collision(uint8_t, uint8_t, Direction);

