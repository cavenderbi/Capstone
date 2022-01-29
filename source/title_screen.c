#include <gb/gb.h>
#include <gb/cgb.h>
#include "../sprites/test_title_data.c"
#include "../tilemaps/test_title_map.c"
/*  Displays the tite screen and waits for the player to press start. */
void show_title() {
    // Load in the title screen tiles.
    set_bkg_data(0, 137, test_title_data);
    set_bkg_tiles(0, 0, 20, 18, test_title_map);

    SHOW_BKG;
    DISPLAY_ON;
    // Wait for the user to press start. 
    waitpad(J_START);
}

void fadeout() {
    for (uint8_t i = 0; i < 4; i++) { 
        switch (i) {
            case 0: 
                BGP_REG = 0xE4;
                break;
            case 1:
                BGP_REG = 0xF9;
                break;
            case 2:
                BGP_REG = 0xFE;
                break;
            case 3:
                BGP_REG = 0xFF;
                break;
        }
        for (uint8_t i = 0; i < 20; i++)
            wait_vbl_done();
    }
}

void fadein() {
    for (uint8_t i = 0; i < 3; i++) {
        switch (i) {
            case 0: 
                BGP_REG = 0xFE;
                break;
            case 1:
                BGP_REG = 0xF9;
                break;
            case 2:
                BGP_REG = 0xE4;
                break;
        }
        for (uint8_t i = 0; i < 20; i++)
            wait_vbl_done();
    }
}