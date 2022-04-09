//AUTOGENERATED FILE FROM png2asset
#ifndef METASPRITE_deathscreen_H
#define METASPRITE_deathscreen_H

#include <stdint.h>
#include <gbdk/platform.h>
#include <gbdk/metasprites.h>

#define deathscreen_TILE_ORIGIN 0
#define deathscreen_TILE_H 8
#define deathscreen_WIDTH 160
#define deathscreen_HEIGHT 144
#define deathscreen_TILE_COUNT 106
#define deathscreen_MAP_ATTRIBUTES 0
#define deathscreen_TILE_PALS deathscreen_tile_pals

BANKREF_EXTERN(deathscreen)

extern const palette_color_t deathscreen_palettes[4];
extern const uint8_t deathscreen_tiles[1696];

extern const unsigned char deathscreen_map[360];
extern const unsigned char* deathscreen_tile_pals[106];

#endif