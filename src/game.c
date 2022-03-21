#include "game.h"

void initPlayer() {
    player.x_pos = 88;
    player.y_pos = 78;
    player.dir = RIGHT;
    player.health = 4;
}

// Reads the user input and responds apropriately. 
inline void input() {
    uint8_t j = joypad();
    if (j & J_UP) {
        player.dir = UP;
        if (sprite_tile_collision(player.x_pos, player.y_pos - 1, player.dir))
            player.y_pos--;
    } else if (j & J_DOWN) {
        player.dir = DOWN;
        if(sprite_tile_collision(player.x_pos, player.y_pos + 1, player.dir))
            player.y_pos++;
    } else if (j & J_LEFT) {
        player.dir = LEFT;
        if (sprite_tile_collision(player.x_pos - 1, player.y_pos, player.dir))
            player.x_pos--;
    } else if (j & J_RIGHT) {
        player.dir = RIGHT;
        if (sprite_tile_collision(player.x_pos + 1, player.y_pos, player.dir))
            player.x_pos++;
    }

    // If player presses A, shoot test projectile.
    static bool shot = true;
    if (j & J_A) {
        if (shot) {
            shot = false;
            shoot(player.x_pos, player.y_pos, player.dir);
        }
    } else shot = true;
}

// Controls other game functions such as moving projectiles. 
inline void logic() {
    //  Has player left the room?
    int minx = (20*8 * player.room_i) + 8, 
        miny = (16*8 * player.room_j) + 16, 
        maxx = minx + 20*8-7, //  18 tiles * 8 pixels per tile.
        maxy = miny + 16*8-7; //  14 tiles * 8 pixels per tile.
    if (player.x_pos > maxx || player.x_pos < minx || player.y_pos > maxy || player.y_pos < miny)
        scroll_camera(&player);

    updateProjs(rooms[player.room_i][player.room_j].enemies);
    updateEnemies(rooms[player.room_i][player.room_j].enemies);
}

// Every ten frames, update the animation. 
inline void draw(uint8_t anim_count) {
    switch (player.dir) {
        case UP:
            set_sprite_tile(0, anim_count);
            break;
        case DOWN:
            set_sprite_tile(0, anim_count + 4);
            break;
        case LEFT:
            set_sprite_tile(0, anim_count + 6);
            break;
        case RIGHT:
            set_sprite_tile(0, anim_count + 2);
            break;
    }
    // Move the player sprite. 
    move_sprite(0, player.x_pos - camera.x_pos, player.y_pos - camera.y_pos);
    // Wait until we're done drawing to the screen.
    wait_vbl_done();
}

inline void initSprites() {
    const uint16_t brick_palette[] = { RGB_WHITE, RGB_LIGHTGRAY, RGB_DARKGRAY, RGB_BLACK };
    const uint16_t heart_palette[] = { 0, RGB_PINK, RGB_RED, RGB_DARKRED };
    const uint16_t palette[] = { RGBHTML(0xd0d058), RGBHTML(0xa0a840), RGBHTML(0x708028), RGBHTML(0x405010) };
    set_sprite_palette(0, 1, palette);
    set_sprite_palette(1, 1, heart_palette);
    set_sprite_data(0, 8, arrow);
    set_sprite_tile(0, 0);
    set_sprite_prop(0, 1);

    set_sprite_data(8, 4, test_projectile);
    set_sprite_tile(1, 9);
    hide_sprite(1);

    set_sprite_data(13, 1, test_enemy);
    set_sprite_tile(17, 13);
/* 
    set_bkg_data(20, 7, testroom_big_data);
    set_bkg_submap(0, 0, 31, 31, testroom_big, BigWidth); */
    set_bkg_palette(0, 1, brick_palette);

    set_win_data(0, 20, hud_data);
    set_win_tiles(0, 0, hud_tilemapWidth, hud_tilemapHeight, hud_tilemap);
    move_win(8, 128);
}

void main() {
    show_title();
    display_logo_splash();

    initPlayer();
    initEnemies(rooms[player.room_i][player.room_j].enemies);
    initProjs();

    initSprites();
    init_camera(testroom_big_data, 20, 7, testroom_big, testroom_bigWidth, testroom_bigHeight);

    //Game roguelight;

    spawnEnemy(60, 60, UP, 4, rooms[player.room_i][player.room_j].enemies);
    spawnEnemy(80, 60, UP, 8, rooms[player.room_i][player.room_j].enemies);
    spawnEnemy(120, 60, UP, 4, rooms[player.room_i][player.room_j].enemies);

    SHOW_SPRITES;
    SHOW_BKG;
    SHOW_WIN;
    DISPLAY_ON;

    while (true) {
        input();
        logic();
        draw((sys_time & 0x10) > 0x8);
    }
}