// Include the gameboy functions. 
#include <gb/gb.h>
// Booleans are nice to have.
#include <stdbool.h>
#include <stdio.h>
// Include the sprites defined in their respective C folders. 
// Thanks to GBTD for letting me not have to write 8x8 sprites in hex by hand.
#include "../sprites/heart.c"
#include "../sprites/square.c"

void main() {
    uint8_t current_sprite = 0;

    set_sprite_data(0, 2, square);
    set_sprite_tile(0, current_sprite);

    move_sprite(0, 88, 78);

    SHOW_SPRITES;

    while (true) {
        uint8_t j = joypad();
        if (j & J_UP)
            scroll_sprite(0, 0, -2);
        if (j & J_DOWN)
            scroll_sprite(0, 0, 2);
        if (j & J_LEFT)
            scroll_sprite(0, -2, 0);
        if (j & J_RIGHT)
            scroll_sprite(0, 2, 0);

        if (j & J_A) {
            current_sprite = !current_sprite;
            set_sprite_tile(0, current_sprite);
        }
        
        delay(200);
    }
    
}