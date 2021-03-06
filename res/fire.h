//AUTOGENERATED FILE FROM png2asset
#ifndef METASPRITE_fire_H
#define METASPRITE_fire_H

#include <stdint.h>
#include <gbdk/platform.h>
#include <gbdk/metasprites.h>

#define fire_TILE_ORIGIN 0
#define fire_TILE_H 8
#define fire_WIDTH 16
#define fire_HEIGHT 16
#define fire_TILE_COUNT 4
#define fire_MAP_ATTRIBUTES 0
#define fire_TILE_PALS fire_tile_pals

BANKREF_EXTERN(fire)

extern const palette_color_t fire_palettes[4];
extern const uint8_t fire_tiles[64];

extern const unsigned char fire_map[4];
extern const unsigned char* fire_tile_pals[4];

#endif