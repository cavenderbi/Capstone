// Include the gameboy functions. 
#include <gb/gb.h>
#include <gb/cgb.h>
#include <gbdk/font.h>
// Booleans are nice to have.
#include <stdbool.h>
#include <stdio.h>
// Include the title screen. 
#include "title_screen.c"

// Include the sprites defined in their respective C folders. 
// Thanks to GBTD for letting me not have to write 8x8 sprites in hex by hand.
#include "../sprites/arrow.c"

// Include the tiles and tilemap for the HUD. 
#include "../sprites/hud.c"
#include "../tilemaps/hud.c"

#include "../sprites/test.c"
#include "../tilemaps/test.c"

enum Direction { UP, DOWN, LEFT, RIGHT, NONE } dir = NONE;

// Reads the user input and responds apropriately. 
void input() {
    unsigned char j = joypad();
    if (j & J_UP) {
        dir = UP;
        scroll_sprite(0, 0, -1);
    } else if (j & J_DOWN) {
        dir = DOWN;
        scroll_sprite(0, 0, 1);
    } else if (j & J_LEFT) {
        dir = LEFT;
        scroll_sprite(0, -1, 0);
    } else if (j & J_RIGHT) {
        dir = RIGHT;
        scroll_sprite(0, 1, 0);
    }
    
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
    // Only animate every 10 frames. 
    frame_count++;
    if (frame_count >= FRAMES_ANIM_UPDATE) {
        frame_count = 0;
        anim_count = !anim_count;
    }
    switch (dir) {
        case UP:
            dir = NONE;
            set_sprite_tile(0, anim_count);
            break;
        case DOWN:
            dir = NONE;
            set_sprite_tile(0, anim_count + 4);
            break;
        case LEFT:
            dir = NONE;
            set_sprite_tile(0, anim_count + 6);
            break;
        case RIGHT:
            dir = NONE;
            set_sprite_tile(0, anim_count + 2);
            break;
    }
    // Wait until we're done drawing to the screen.
    wait_vbl_done();
}

void main() {
    show_title();

    unsigned char arrow_palette[] =  {0, RGB_RED, RGB_BLUE, RGB_BLACK};
    set_sprite_palette(0, 8, arrow_palette);
    set_sprite_data(0, 8, arrow);
    set_sprite_tile(0, 0);

    move_sprite(0, 88, 78);

    set_bkg_data(21, 9, test_data);
    set_bkg_tiles(0, 0, test_tilemapWidth, test_tilemapHeight, test_tilemap);

    set_win_data(0, 20, hud_data);
    set_win_tiles(0, 0, hud_tilemapWidth, hud_tilemapHeight, hud_tilemap);
    move_win(8, 128);

    SHOW_SPRITES;
    SHOW_WIN;
    DISPLAY_ON;
    
    while (true) {
        input();
        logic();
        draw();
    }
}