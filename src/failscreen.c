#include <gb/gb.h>
#include <gb/cgb.h>
#include "../res/deathscreen.h"

/*  Displays the tite screen and waits for the player to press start. */
void show_deathscreen() {
    DISPLAY_OFF;
    
    set_bkg_palette(0, 1, deathscreen_palettes);
    set_bkg_data(0, deathscreen_TILE_COUNT, deathscreen_tiles);
    //set_bkg_tiles(0, 0, 20, 18, deathscreen_metasprites); 
    // You'll want to run png2asset with the -map and -noflip flags.
    // Metasprites are for sprites, you want a map.
    // This doesn't compile, so I commented it out. 

    SHOW_BKG;
    DISPLAY_ON;
    // Wait for the user to press start. 
    waitpad(J_START);
}