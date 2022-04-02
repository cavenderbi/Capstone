//AUTOGENERATED FILE FROM png2asset

#include <stdint.h>
#include <gbdk/platform.h>
#include <gbdk/metasprites.h>

BANKREF(test_goombah)

const palette_color_t test_goombah_palettes[4] = {
	RGB8(0, 0, 0), RGB8(255, 204, 142), RGB8(255, 115, 0), RGB8(0, 0, 0)
};

const uint8_t test_goombah_tiles[48] = {
	0x00,0x03,0x00,0x07,0x00,0x0f,0x00,0x1f,0x18,0x3f,0x0c,0x77,0x0f,0x77,0x0e,0xf5,
	0x0e,0xf1,0x00,0xff,0x07,0x78,0x0f,0x00,0x3f,0x30,0x7f,0x7c,0x7f,0x7e,0x3e,0x3e,
	0x70,0x8f,0x00,0xff,0xe0,0x1e,0xf0,0x00,0xf0,0x00,0xf8,0x18,0xf8,0x38,0x70,0x70
};

const metasprite_t test_goombah_metasprite0[] = {
	METASPR_ITEM(-8, -8, 0, 0), METASPR_ITEM(0, 8, 0, 32), METASPR_ITEM(8, -8, 1, 0), METASPR_ITEM(0, 8, 2, 0), METASPR_TERM
};

const metasprite_t test_goombah_metasprite1[] = {
	METASPR_ITEM(-8, -8, 0, 0), METASPR_ITEM(0, 8, 0, 32), METASPR_ITEM(8, -8, 2, 32), METASPR_ITEM(0, 8, 1, 32), METASPR_TERM
};

const metasprite_t* const test_goombah_metasprites[2] = {
	test_goombah_metasprite0, test_goombah_metasprite1
};
