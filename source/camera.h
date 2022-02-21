#pragma once 

#include <gb/gb.h>
#include <stdint.h>

#include "direction.h"

struct _cam {
    uint16_t x_pos, y_pos;
} camera, old_camera;

struct _tilemap {
    uint8_t x_pos, y_pos;
} map, old_map;

static uint8_t * tilemap;
static uint8_t tilemap_height;
static uint8_t tilemap_width;

#define CAMERA_MAX_X ((tilemap_width - 20) * 8)
#define CAMERA_MAX_Y ((tilemap_width - 18) * 8)

#define MIN(A, B) A < B ? A : B

void init_camera(uint8_t * tiles, uint8_t tile_offset, uint8_t num_tiles, uint8_t * _tilemap, uint8_t _tilemap_width, uint8_t _tilemap_height);
void scroll_camera(Direction dir);
static void set_camera();
inline uint8_t get_camera_x_pos() { return camera.x_pos; }
inline uint8_t get_camera_y_pos() { return camera.y_pos; }
inline uint8_t get_tilemap_x_pos() { return map.x_pos; }
inline uint8_t get_tilemap_y_pos() { return map.y_pos; }