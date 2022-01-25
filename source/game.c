// Include the gameboy functions. 
#include <gb/gb.h>
// Booleans are nice to have.
#include <stdbool.h>
#include <stdio.h>
// Include the sprites defined in their respective C folders. 
// Thanks to GBTD for letting me not have to write 8x8 sprites in hex by hand.
#include "../sprites/heart.c"
#include "../sprites/walk.c"

enum direction { UP, DOWN, LEFT, RIGHT } dir;
uint8_t x, y;

void input() {
    uint8_t j = joypad();

    if (j & J_UP)
        scroll_sprite(0, 0, -1);
    else if (j & J_DOWN)
        scroll_sprite(0, 0, 1);
    else if (j & J_LEFT)
        scroll_sprite(0, -1, 0);
    else if (j & J_RIGHT)
        scroll_sprite(0, 1, 0);

}

void logic() {
    ;
}

// Every ten frames, update the animation. 
#define FRAMES_ANIM_UPDATE 10
void draw() {
    unsigned char anim_tiles[2] = {0, 1};
    static int frame_count = 0;
    static int anim_count = 0;

    frame_count++;
    if (frame_count >= FRAMES_ANIM_UPDATE) {
        frame_count = 0;
        anim_count = !anim_count;
        set_sprite_tile(0, anim_tiles[anim_count]);
    }
}

void main() {
    set_sprite_data(0, 2, heart);
    set_sprite_tile(0, 0);

    move_sprite(0, 88, 78);

    SHOW_SPRITES;

    while (true) {
        input();
        logic();
        draw();
        wait_vbl_done();
    }
    
}