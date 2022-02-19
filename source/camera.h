#pragma once 

#include <gb/gb.h>
#include <stdint.h>

#include "direction.h"

void init_camera(uint8_t * tiles, uint8_t tile_offset, uint8_t num_tiles, uint8_t * _tilemap, uint8_t _tilemap_width, uint8_t _tilemap_height);
void scroll_camera(Direction dir, uint8_t dist);
static void set_camera();
inline uint8_t get_camera_x_pos() { return camera.x_pos; }
inline uint8_t get_camera_y_pos() { return camera.y_pos; }
inline uint8_t get_tilemap_x_pos() { return tilemap.x_pos; }
inline uint8_t get_tilemap_x_pos() { return tilemap.y_pos; }