#include <gb/gb.h>
#include <gb/cgb.h>
#include "../res/sketch_titlescreen.h"

/*  Displays the tite screen and waits for the player to press start. */
void show_title() {
    DISPLAY_OFF;
    
    set_bkg_palette(0, 1, sketch_titlescreen_palettes);
    set_bkg_data(0, sketch_titlescreen_TILE_COUNT, sketch_titlescreen_tiles);
    set_bkg_tiles(0, 0, 20, 18, sketch_titlescreen_map);

    SHOW_BKG;
    DISPLAY_ON;
    // Wait for the user to press start. 
    waitpad(J_START);
}