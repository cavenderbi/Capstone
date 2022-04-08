#include <gb/gb.h>
#include <gb/cgb.h>
#include "../res/deathscreen.h"

/*  Displays the tite screen and waits for the player to press start. */
void show_title() {
    DISPLAY_OFF;
    
    set_bkg_palette(0, 1, deathscreen_palettes);
    set_bkg_data(0, deathscreen_TILE_COUNT, deathscreen_tiles);
    set_bkg_tiles(0, 0, 20, 18, deathscreen_metasprites);

    SHOW_BKG;
    DISPLAY_ON;
    // Wait for the user to press start. 
    waitpad(J_START);
}