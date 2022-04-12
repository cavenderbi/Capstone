#include <gb/gb.h>
#include <gb/cgb.h>
#include <stdio.h>
#include <rand.h>
//#include "../res/buttonscreen.h"

inline void seed_rand() {
    DISPLAY_ON;
    SHOW_BKG;
    // These next 5 lines should be replaced by an inital set_bkg_data and set_bkg_tiles.
    /*
    font_init();
    font_load(font_italic);
    gotoxy(0, 0);
    puts("Getting seed.");
    puts("Push any key. (1)");
    */
    /* set_bkg_palette(0 ,1 , buttonscreen_palettes);
    set_bkg_data(0, 1, buttonscreen_tiles);
    set_bkg_tiles(0, 0, 20, 18, buttonscreen_map); */
    waitpad(0xFF);  // This function returns the key pressed. Maybe make a variable that stores it, so you can display it to the player.

    // DON'T TOUCH THE NEXT 2.
    waitpadup();
    uint16_t seed = DIV_REG;
    // DON'T TOUCH THE PREVIOUS 2.
    
    puts("Push any key. (2)");  // Replace this with something to display which button the player pressed.
    waitpad(0xFF);  // This function returns the key pressed. Maybe reuse that variable that stores it, so you can display it to the player.
    // Put something here to display the player's second button.

    // DON'T TOUCH ANYTHING BELOW THIS POINT.
    waitpadup();
    seed |= (uint16_t)DIV_REG << 8;
    initrand(seed);
    HIDE_BKG;
    DISPLAY_OFF;
}