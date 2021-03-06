//AUTOGENERATED FILE FROM png2asset
#ifndef METASPRITE_bar_H
#define METASPRITE_bar_H

#include <stdint.h>
#include <gbdk/platform.h>
#include <gbdk/metasprites.h>

#define bar_TILE_ORIGIN 0
#define bar_TILE_H 8
#define bar_WIDTH 72
#define bar_HEIGHT 16
#define bar_TILE_COUNT 18
#define bar_MAP_ATTRIBUTES 0
#define bar_TILE_PALS bar_tile_pals

BANKREF_EXTERN(bar)

extern const palette_color_t bar_palettes[4];
extern const uint8_t bar_tiles[288];

extern const unsigned char bar_map[18];
extern const unsigned char* bar_tile_pals[18];

#endif