#include <gb/gb.h>
#include <gb/cgb.h>
#include "../res/titlescreen.h"

/*  Displays the tite screen and waits for the player to press start. */
BANKREF(show_title)
void show_title() {
    DISPLAY_OFF;
    
    set_bkg_palette(0, titlescreen_PALETTE_COUNT, titlescreen_palettes);
    set_bkg_data(0, titlescreen_TILE_COUNT, titlescreen_tiles);
    set_bkg_tiles(0, 0, 20, 18, titlescreen_map);

    /* VBK_REG = 1; 
    set_bkg_tiles(0, 0, 20, 18, titlescreen_tile_pals);
    VBK_REG = 0; */

    SHOW_BKG;
    DISPLAY_ON;
    // Wait for the user to press start. 
    waitpad(J_START);
}