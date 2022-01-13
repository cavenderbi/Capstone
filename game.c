// Include the gameboy functions. 
#include <gb/gb.h>
// Booleans are nice to have.
#include <stdbool.h>
#include <stdio.h>
// Include the sprites defined in their respective C folders. 
// Thanks to GBTD for letting me not have to write 8x8 sprites in hex by hand.
//#include "heart.h"
extern unsigned char heart[] =
{
  0x66,0x66,0x99,0xFF,0x81,0xFF,0x81,0xFF,
  0x42,0x7E,0x24,0x3C,0x18,0x18,0x00,0x00
};
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
    move_sprite(0, SCREENWIDTH/2+4, SCREENHEIGHT/2+4);

    SHOW_SPRITES;
}

void main() {
    draw();
}