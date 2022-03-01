#include "logo_splash.h"

void display_logo_splash() {
    DISPLAY_OFF;

    set_bkg_data(0, 75, test_logo_data);
    set_bkg_tiles(0, 0, 20, 18, test_logo_map);

    SHOW_BKG;
    DISPLAY_ON;

    delay(2 * 1000);
}