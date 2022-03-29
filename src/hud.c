#include <stdint.h>
#include <gb/cgb.h>
#include <gb/gb.h>
#include "dmgtype.h"

// Heart icons.
#include "../res/hearts.h"
// Element icons.
#include "../res/fire.h"
#include "../res/frost.h"
#include "../res/shock.h"
// Timer icons. 
#include "../res/bar.h"

void init_HUD() {
    set_win_data(00, hearts_TILE_COUNT, hearts_tiles);
    set_win_data(03, fire_TILE_COUNT  , fire_tiles);
    set_win_data(07, frost_TILE_COUNT , frost_tiles);
    set_win_data(11, shock_TILE_COUNT , shock_tiles);
    set_win_data(15, bar_TILE_COUNT   , bar_tiles);
    VBK_REG = 1;
    fill_win_rect(01, 0, 7, 2, 1);
    fill_win_rect( 9, 0, 12, 2, 2);
    VBK_REG = 0;
    set_bkg_palette(1, 1, hearts_palettes);
    set_bkg_palette(2, 1, bar_palettes);
    fill_win_rect(0, 0, 20, 2, 2);
}
void draw_HUD_health(uint8_t health) {
    // Draw health hearts. 
    fill_win_rect(1, 0, 7, 2, 1);
    if (health <= 14 && health != 0) {
        fill_win_rect(1, 0, (health <= 7) ? health : 7, 1, 0);
        if (health > 7)
            fill_win_rect(1, 1, health - 7, 1, 0);
    }
}
void draw_HUD_element(PWR_TYPE element) {
    // Draw element icon.
    switch(element) {
        case PWR_NONE:
            fill_win_rect(10, 0, 12, 2, 2);
            break;
        case PWR_FIRE:
            set_bkg_palette(2, 1, fire_palettes);
            set_win_based_tiles(10, 0, 2, 2, fire_map, 3);
            break;
        case PWR_FROST:
            set_bkg_palette(2, 1, frost_palettes);
            set_win_based_tiles(10, 0, 2, 2, frost_map, 7);
            break;
        case PWR_SHOCK:
            set_bkg_palette(2, 1, shock_palettes);
            set_win_based_tiles(10, 0, 2, 2, shock_map, 11);
            break;
    }    

}

void draw_HUD_usage(uint8_t usage) {
    // Draw power-up timer.
    // Begin bar. 
    if (usage > 1) {
        set_win_tile_xy(12, 0, 0x0F);
        set_win_tile_xy(12, 1, 0x18);
    } else if (usage == 1) {
        set_win_tile_xy(12, 0, 0x12);
        set_win_tile_xy(12, 1, 0x1B);
        return;
    } else {
        set_win_tile_xy(12, 0, 0x15);
        set_win_tile_xy(12, 1, 0x1E);
        return;
    }  
    // Middle of bar.
    fill_win_rect(13, 0, 5, 1, 0x16);
    fill_win_rect(13, 1, 5, 1, 0x1F);
    if (usage > 2) {
        fill_win_rect(13, 0, (usage-1)/2, 1, 0x10);
        fill_win_rect(13, 1, (usage-1)/2, 1, 0x19);
        if (usage & 1) {
            set_win_tile_xy(12 + usage/2, 0, 0x13);
            set_win_tile_xy(12 + usage/2, 1, 0x1C);
        }
    }
    // End bar.
    if (usage == 14) {
        set_win_tile_xy(18, 0, 0x11);
        set_win_tile_xy(18, 1, 0x1A);
    } else if (usage == 13) {
        set_win_tile_xy(18, 0, 0x14);
        set_win_tile_xy(18, 1, 0x1D);
    } else {
        set_win_tile_xy(18, 0, 0x17);
        set_win_tile_xy(18, 1, 0x20);
    }
}