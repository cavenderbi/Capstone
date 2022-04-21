#include <gb/gb.h>
#include <gb/cgb.h>

#include "../res/test_logo.h"

void display_logo_splash() {
    DISPLAY_OFF;

    set_bkg_palette(0, test_logo_PALETTE_COUNT, test_logo_palettes);
    set_bkg_data(0, test_logo_TILE_COUNT, test_logo_tiles);
    set_bkg_tiles(0, 0, 20, 18, test_logo_map);

    SHOW_BKG;
    DISPLAY_ON;

    delay(2 * 1000);
}