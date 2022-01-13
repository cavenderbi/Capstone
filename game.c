// Include the gameboy functions. 
#include <gb/gb.h>
// Booleans are nice to have.
#include <stdbool.h>
#include <stdio.h>
// Include the sprites defined in their respective C folders. 
// Thanks to GBTD for letting me not have to write 8x8 sprites in hex by hand.
#include "heart.c"
#include "square.c"

void main() {
    uint8_t current_sprite = 0;

    set_sprite_data(0, 2, square);
    set_sprite_tile(0, current_sprite);

    move_sprite(0, 88, 78);

    SHOW_SPRITES;

    while (true) {
        current_sprite = !current_sprite;
        set_sprite_tile(0, current_sprite);
        delay(500);
    }
    
}