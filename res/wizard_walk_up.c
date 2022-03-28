//AUTOGENERATED FILE FROM png2asset

#include <stdint.h>
#include <gbdk/platform.h>
#include <gbdk/metasprites.h>

BANKREF(wizard_walk_up)

const palette_color_t wizard_walk_up_palettes[4] = {
	RGB8(0, 0, 0), RGB8(241, 194, 125), RGB8(120, 120, 120), RGB8(0, 0, 0)
};

const uint8_t wizard_walk_up_tiles[64] = {
	0x00,0x00,0x03,0x03,0x04,0x07,0x0b,0x0f,0x0c,0x0f,0x08,0x0f,0x0a,0x0f,0x0c,0x0f,
	0x00,0x00,0xc0,0xc0,0x20,0xe0,0xd0,0xf0,0x30,0xf0,0x10,0xf0,0x10,0xf0,0x10,0xf0,
	0x0c,0x0f,0x14,0x1f,0x34,0x2f,0x3b,0x2f,0x10,0x1f,0x18,0x1f,0x1f,0x1f,0x0f,0x0f,
	0x38,0xf8,0x54,0xfc,0x94,0xfc,0x08,0xf8,0x08,0xf8,0x38,0xf8,0xfc,0xcc,0xf8,0xf8
};

const metasprite_t wizard_walk_up_metasprite0[] = {
	METASPR_ITEM(-8, -8, 0, 0), METASPR_ITEM(0, 8, 1, 0), METASPR_ITEM(8, -8, 2, 0), METASPR_ITEM(0, 8, 3, 0), METASPR_TERM
};

const metasprite_t wizard_walk_up_metasprite1[] = {
	METASPR_ITEM(-8, -8, 0, 0), METASPR_ITEM(0, 8, 1, 0), METASPR_ITEM(8, -8, 3, 32), METASPR_ITEM(0, 8, 2, 32), METASPR_TERM
};

const metasprite_t* const wizard_walk_up_metasprites[2] = {
	wizard_walk_up_metasprite0, wizard_walk_up_metasprite1
};
