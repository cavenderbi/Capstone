#include "title_screen.h"

/*  Displays the tite screen and waits for the player to press start. */
void show_title() {
    // Load in the title screen tiles.
    const uint16_t title_palette[] = { RGB_WHITE, RGB_TEAL, RGB_BLUE, RGB_DARKBLUE };
    set_bkg_palette(0, 1, title_palette);
    set_bkg_data(0, 137, test_title_data);
    set_bkg_tiles(0, 0, 20, 18, test_title_map);

    SHOW_BKG;
    DISPLAY_ON;
    // Wait for the user to press start. 
    waitpad(J_START);
}