#ifndef _CAMERA_INCLUDED
#define _CAMERA_INCLUDED

#include <gb/gb.h>
#include <stdint.h>

#include "enemy.h"
#include "player.h"
#include "powerup.h"

BANKREF_EXTERN(camera)

typedef struct {
    uint8_t x_pos, y_pos;
} Cam;

extern Cam cam;

void init_camera(const uint8_t * _tilemap, uint8_t, uint8_t);
void scroll_camera(Player *);

#endif