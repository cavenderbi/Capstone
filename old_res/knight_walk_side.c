//AUTOGENERATED FILE FROM png2asset

#include <stdint.h>
#include <gbdk/platform.h>
#include <gbdk/metasprites.h>

BANKREF(knight_walk_side)

const palette_color_t knight_walk_side_palettes[4] = {
	RGB8(0, 0, 0), RGB8(164, 164, 164), RGB8(93, 93, 93), RGB8(0, 0, 0)
};

const uint8_t knight_walk_side_tiles[128] = {
	0x1f,0x1f,0x20,0x3f,0x20,0x3f,0x20,0x3f,0x3c,0x3f,0x20,0x3f,0x13,0x1f,0x1f,0x1f,
	0xe0,0xe0,0x30,0xd0,0x70,0x90,0x70,0x90,0x30,0xd0,0x30,0xd0,0xe0,0xe0,0xa0,0xe0,
	0x0b,0x0e,0x0b,0x0e,0x0b,0x0f,0x0f,0x0e,0x1f,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,
	0xd0,0x70,0xd0,0x70,0xe0,0xe0,0xe0,0x20,0xf0,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,
	0x1f,0x1f,0x20,0x3f,0x20,0x3f,0x20,0x3f,0x3c,0x3f,0x20,0x3f,0x13,0x1f,0x1e,0x1f,
	0xe0,0xe0,0x30,0xd0,0x70,0x90,0x70,0x90,0x30,0xd0,0x30,0xd0,0xe0,0xe0,0x20,0xe0,
	0x0f,0x09,0x0f,0x09,0x1e,0x1f,0x3f,0x21,0x3f,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,
	0x30,0xf0,0x38,0xe8,0x38,0xe8,0xf8,0xc8,0xf8,0xf8,0x00,0x00,0x00,0x00,0x00,0x00
};

const metasprite_t knight_walk_side_metasprite0[] = {
	METASPR_ITEM(-8, -8, 0, 1), METASPR_ITEM(0, 8, 1, 1), METASPR_ITEM(8, -8, 2, 1), METASPR_ITEM(0, 8, 3, 1), METASPR_TERM
};

const metasprite_t knight_walk_side_metasprite1[] = {
	METASPR_ITEM(-8, -8, 4, 1), METASPR_ITEM(0, 8, 5, 1), METASPR_ITEM(8, -8, 6, 1), METASPR_ITEM(0, 8, 7, 1), METASPR_TERM
};

const metasprite_t* const knight_walk_side_metasprites[2] = {
	knight_walk_side_metasprite0, knight_walk_side_metasprite1
};