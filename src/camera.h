#ifndef _CAMERA_INCLUDED
#define _CAMERA_INCLUDED

#include <gb/gb.h>
#include <stdint.h>

#include "enemy.h"
#include "player.h"
#include "rooms.h"

typedef struct _cam {
    uint16_t x_pos, y_pos;
} Cam;

typedef struct _tilemap {
    uint8_t x_pos, y_pos;
} Map;

extern Cam camera, old_camera;
extern Map map, old_map;
//extern uint8_t * tilemap, tilemap_width, tilemap_height;

#define CAMERA_MAX_X ((tilemap_width - 20) * 8)
#define CAMERA_MAX_Y ((tilemap_width - 18) * 8)

#define MIN(A, B) A < B ? A : B

void init_camera(uint8_t * tiles, uint8_t tile_offset, uint8_t num_tiles, uint8_t * _tilemap, uint8_t _tilemap_width, uint8_t _tilemap_height);
void scroll_camera(Player *);
static void set_camera();
inline uint8_t get_camera_x_pos();
inline uint8_t get_camera_y_pos();
inline uint8_t get_tilemap_x_pos();
inline uint8_t get_tilemap_y_pos();

#endif