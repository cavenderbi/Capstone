// Include the gameboy functions. 
#include <gb/gb.h>
#include <gb/cgb.h>
#include <gbdk/font.h>
// Booleans are nice to have.
#include <stdbool.h>
#include <stdio.h>
// Include the sprites defined in their respective C folders. 
// Thanks to GBTD for letting me not have to write 8x8 sprites in hex by hand.
#include "../sprites/heart.c"
#include "../sprites/walk.c"

// Include the tiles and tilemap for the HUD. 
#include "../sprites/hud.c"
#include "../tilemaps/hud.c"

// Reads the user input and responds apropriately. 
void input() {
    unsigned char j = joypad();
    if (j & J_UP)
        scroll_sprite(0, 0, -1);
    if (j & J_DOWN)
        scroll_sprite(0, 0, 1);
    if (j & J_LEFT)
        scroll_sprite(0, -1, 0);
    if (j & J_RIGHT)
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
    // Only animate every 10 frames. 
    frame_count++;
    if (frame_count >= FRAMES_ANIM_UPDATE) {
        frame_count = 0;
        anim_count = !anim_count;
        set_sprite_tile(0, anim_tiles[anim_count]);
    }
    // Wait until we're done drawing to the screen.
    wait_vbl_done();
}

void main() {
    unsigned char heart_palette[] =  {0, RGB_PINK, RGB_RED, RGB_DARKRED};
    set_sprite_palette(0, 1, heart_palette);
    set_sprite_data(0, 2, heart);
    set_sprite_tile(0, 0);

    move_sprite(0, 88, 78);

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