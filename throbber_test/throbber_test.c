#include "loadorb.h"
#include "loadorb_invert.h"

#include "gb/gb.h"
#include "gb/cgb.h"
#include "gb/metasprites.h"

const unsigned char blk_sqr[] =
{
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
};

void main() {
    // Load in sprite data.
    set_sprite_data(0, sizeof(loadorb_tiles) >> 3, loadorb_tiles);
    SHOW_SPRITES;
    DISPLAY_ON;
    // Animate.
    set_bkg_data(0, sizeof(blk_sqr) >> 3, blk_sqr);
    fill_rect(0, 0, 20, 18, 0);
    while (1) {
        move_metasprite(loadorb_metasprites[(sys_time / 8) % 8], 0, 0, 160-8-1, 144-1);
    }
}