//AUTOGENERATED FILE FROM png2asset
#ifndef METASPRITE_titlescreen_H
#define METASPRITE_titlescreen_H

#include <stdint.h>
#include <gbdk/platform.h>
#include <gbdk/metasprites.h>

#define titlescreen_TILE_ORIGIN 0
#define titlescreen_TILE_H 8
#define titlescreen_WIDTH 160
#define titlescreen_HEIGHT 144
#define titlescreen_TILE_COUNT 219
#define titlescreen_PALETTE_COUNT 7
#define titlescreen_MAP_ATTRIBUTES titlescreen_map_attributes
#define titlescreen_TILE_PALS 0

BANKREF_EXTERN(titlescreen)

extern const palette_color_t titlescreen_palettes[28];
extern const uint8_t titlescreen_tiles[3504];

extern const unsigned char titlescreen_map[360];
extern const unsigned char titlescreen_map_attributes[360];

#endif