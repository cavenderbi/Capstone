#pragma once

#include <stdint.h>

#include "direction.h"
#include "dmgtype.h"

// Using a player struct to clean up the code a bit.
typedef struct {
    uint16_t x_pos, y_pos;
    uint8_t room_i, room_j;
    uint8_t health;
    Direction dir;
    PWR_TYPE element;
} Player;
