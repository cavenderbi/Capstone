#include "logo_splash.h"

void display_logo_splash() {
    DISPLAY_OFF;

    const palette_color_t pal[] = { RGB_WHITE, RGB_WHITE, RGB_WHITE, RGB_BLACK };
    set_bkg_palette(0, 1, pal);
    set_bkg_data(0, 75, test_logo_data);
    set_bkg_tiles(0, 0, 20, 18, test_logo_map);

    SHOW_BKG;
    DISPLAY_ON;

    delay(2 * 1000);
}