//AUTOGENERATED FILE FROM png2asset

#include <stdint.h>
#include <gbdk/platform.h>
#include <gbdk/metasprites.h>

BANKREF(knight_walk_up)

const palette_color_t knight_walk_up_palettes[4] = {
	RGB8(0, 0, 0), RGB8(164, 164, 164), RGB8(93, 93, 93), RGB8(0, 0, 0)
};

const uint8_t knight_walk_up_tiles[128] = {
	0x1f,0x1f,0x23,0x3c,0x27,0x38,0x27,0x38,0x23,0x3c,0x23,0x3c,0x5f,0x7f,0x50,0x7f,0x50,0x7f,0x30,0x3f,0x1e,0x1f,0x33,0x3f,0x1f,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,
	0xe0,0xe0,0x10,0xf0,0x90,0x70,0x90,0x70,0x10,0xf0,0x10,0xf0,0xe8,0xf8,0x14,0xfc,0x14,0xfc,0x08,0xf8,0x30,0xf0,0xf8,0xf8,0xf0,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,
	0x0f,0x0f,0x11,0x1e,0x13,0x1c,0x13,0x1c,0x11,0x1e,0x11,0x1e,0x2f,0x3f,0x50,0x7f,0x50,0x7f,0x20,0x3f,0x18,0x1f,0x3f,0x3f,0x1f,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,
	0xf0,0xf0,0x88,0x78,0xc8,0x38,0xc8,0x38,0x88,0x78,0x88,0x78,0xf4,0xfc,0x14,0xfc,0x14,0xfc,0x18,0xf8,0xf0,0xf0,0x98,0xf8,0xf0,0xf0,0x00,0x00,0x00,0x00,0x00,0x00
};

const metasprite_t knight_walk_up_metasprite0[] = {
	METASPR_ITEM(-16, -8, 0, 0), METASPR_ITEM(0, 8, 2, 0), METASPR_ITEM(16, -8, 4, 0), METASPR_ITEM(0, 8, 6, 0), METASPR_TERM
};

const metasprite_t* const knight_walk_up_metasprites[1] = {
	knight_walk_up_metasprite0
};
