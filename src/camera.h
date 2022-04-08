#ifndef _CAMERA_INCLUDED
#define _CAMERA_INCLUDED

#include <gb/gb.h>
#include <stdint.h>

#include "enemy.h"
#include "player.h"
#include "powerup.h"

typedef struct {
    uint8_t x_pos, y_pos;
} Cam;

extern Cam cam;

void init_camera(const uint8_t * tiles, uint8_t tile_offset, uint8_t num_tiles, const uint8_t * _tilemap);
void scroll_camera(Player *);

#endif