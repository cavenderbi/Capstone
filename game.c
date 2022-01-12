// Include the gameboy functions. 
#include <gb/gb.h>
// Booleans are nice to have.
#include <stdbool.h>
#include <stdio.h>
// Include the sprites defined in their respective C folders. 
// Thanks to GBTD for letting me not have to write 8x8 sprites in hex by hand.
#include "heart.h"
// Function that handles the input of the game.
void input() {
    // Does nothing atm...
    ;
}
// Function that handles the logic of the game after the input is read. 
void logic() {
    //Does nothing atm...
    ;
}
// Function that draws the current game state to the screen. 
void draw() {
    // Draw a sprite in the middle of the screen.

    // Load the heart sprite into memory. 
    set_sprite_data(0, 1, heart);
    set_sprite_tile(0, 0);

    // Move the sprite to the center of the screen. 
    move_sprite(0, SCREENWIDTH/2, SCREENHEIGHT/2);

    SHOW_SPRITES;
}

void main() {
    draw();
}