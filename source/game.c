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

const char blankmap[1] = {0x00};
typedef enum Direction { UP, DOWN, LEFT, RIGHT, NONE } Direction;
// Using a player struct to clean up the code a bit.
struct Player {
    // x and y positions
    uint8_t x;
    uint8_t y;
    // player direction
    Direction dir;
    // health values
    uint8_t maxHealth;
    uint8_t health;
    // is player alive?
    bool alive;
} player;

void initPlayer() {
    player.x = 88;
    player.y = 78;
    player.dir = NONE;
    player.maxHealth = 4;
    player.health = 4;
    player.alive = true;
}

// Reads the user input and responds apropriately. 
void input() {
    unsigned char j = joypad();
    if (j & J_UP) {
        if(canplayermove(player.x, player.y-1)) {
            player.dir = UP;
            player.y--;
        }
    } else if (j & J_DOWN) {
        if(canplayermove(player.x, player.y+1)) {
            player.dir = DOWN;
            player.y++;
        }
    } else if (j & J_LEFT) {
        if(canplayermove(player.x-1, player.y)) {
            player.dir = LEFT;
            player.x--;
        }
    } else if (j & J_RIGHT) {
        if(canplayermove(player.x+1, player.y)) {
            player.dir = RIGHT;
            player.x++;
        }
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
    switch (player.dir) {
        case UP:
            player.dir = NONE;
            set_sprite_tile(0, anim_count);
            break;
        case DOWN:
            player.dir = NONE;
            set_sprite_tile(0, anim_count + 4);
            break;
        case LEFT:
            player.dir = NONE;
            set_sprite_tile(0, anim_count + 6);
            break;
        case RIGHT:
            player.dir = NONE;
            set_sprite_tile(0, anim_count + 2);
            break;
    }
    move_sprite(0, player.x, player.y);
    // Wait until we're done drawing to the screen.
    wait_vbl_done();
}

uint8_t canplayermove(uint8_t newplayerx, uint8_t newplayery){
    uint16_t indexTLx, indexTLy, tileindexTL;
    uint8_t result;

    indexTLx = newplayerx / 8;
    indexTLx = newplayerx / 8;
    tileindexTL = 20 * indexTLy + indexTLx;

    result = test_title_map[tileindexTL] == blankmap[0];

    return result;
}

void main() {
    show_title();
    fadeout();

    unsigned char arrow_palette[] =  {0, RGB_RED, RGB_LIGHTGRAY, RGB_BLACK};
    set_sprite_palette(0, 8, arrow_palette);
    set_sprite_data(0, 8, arrow);
    set_sprite_tile(0, 0);

    initPlayer();
    move_sprite(0, player.x, player.y);

    unsigned char background_palette[] = {RGB_WHITE, RGB_LIGHTGRAY, RGB_DARKGRAY, RGB_BLACK};
    set_bkg_palette(0,29,background_palette);
    set_bkg_data(21, 9, test_data);
    set_bkg_tiles(0, 0, test_tilemapWidth, test_tilemapHeight, test_tilemap);

    set_win_data(0, 20, hud_data);
    set_win_tiles(0, 0, hud_tilemapWidth, hud_tilemapHeight, hud_tilemap);
    move_win(8, 128);

    SHOW_SPRITES;
    SHOW_BKG;
    SHOW_WIN;
    DISPLAY_ON;

    fadein();
    
    while (true) {
        input();
        logic();
        draw();
    }
}