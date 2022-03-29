#include "game.h"

void initPlayer() {
    player.x_pos = 88;
    player.y_pos = 78;
    player.dir = RIGHT;
    player.health = 12;
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
    static uint16_t prev_shot = UINT16_MAX;
    if (j & J_A) {
        if (sys_time - prev_shot > 30) {
            // Shoot sound? 
            NR10_REG = 0x15;
            NR11_REG = 0x96;
            NR12_REG = 0x73;
            NR13_REG = 0xBB;
            NR14_REG = 0x85;
            // Spawn the projectile.
            shoot(player.x_pos, player.y_pos, player.dir);
            // If the usage is >= 14, then it isn't valid and shouldn't be updated. 
            if (--player.usage <= 14 * NUM_SHOTS_PER_BAR && player.usage > 0)
                draw_HUD_usage(player.usage / NUM_SHOTS_PER_BAR);
            // If the player uses all of their power-up charge, they revert back to normal. 
            else
                draw_HUD_element(player.element = PWR_NONE);
            prev_shot = sys_time;
        }
    }
    /* static bool shot = true;
    if (j & J_A) {
        if (shot) {
            shot = false;
            shoot(player.x_pos, player.y_pos, player.dir);
        }
    } else shot = true; */

    // TODO: Remove this and use power-ups to enable different damage types. 
    static bool changed = true;
    if (j & J_B) {
        if (changed) {
            changed = false;
            // Get the next player element.
            draw_HUD_health(--player.health);
            draw_HUD_element(player.element = (player.element + 1) & 3);
        }
    } else changed = true;
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
    update_powerups(rooms[player.room_i][player.room_j].powerups, &player);
}

// Every ten frames, update the animation. 
inline void draw() {
    static uint8_t offset = 0; 
    // If the D-PAD is pressed, animate the sprite. 
    if (joypad() & (J_UP | J_DOWN | J_LEFT | J_RIGHT)) {
        offset = (sys_time / 12) & 1;
    }
        
    switch (player.dir) {
        case UP: 
            move_metasprite(wizard_walk_up_metasprites[offset], 0, 0, player.x_pos - camera.x_pos, player.y_pos - camera.y_pos);
            break;
        case DOWN:
            move_metasprite(wizard_walk_down_metasprites[offset], 4, 0, player.x_pos - camera.x_pos, player.y_pos - camera.y_pos);
            break;
        case LEFT:
            move_metasprite(wizard_walk_side_metasprites[offset], 8, 0, player.x_pos - camera.x_pos, player.y_pos - camera.y_pos);
            break;
        case RIGHT:
            move_metasprite_vflip(wizard_walk_side_metasprites[offset], 8, 0, player.x_pos - camera.x_pos, player.y_pos - camera.y_pos);
            break;
    }

    // Set the player's color palette based on the current damage type.
    switch (player.element) {
        case PWR_NONE:
            set_sprite_palette(0, 1, wizard_palettes);
            break;
        case PWR_FIRE: 
            set_sprite_palette(0, 1, wizard_palettes + 4);
            break;
        case PWR_FROST: 
            set_sprite_palette(0, 1, wizard_palettes + 8);
            break;
        case PWR_SHOCK: 
            set_sprite_palette(0, 1, wizard_palettes + 12);
            break;
    }

    // Wait until we're done drawing to the screen.
    wait_vbl_done();
}

inline void initSprites() {
    const palette_color_t palettes[] = {RGB_WHITE, RGB_LIGHTGRAY, RGB_DARKGRAY, RGB_BLACK, // GRAYSCALE
                                        0, RGB_RED, RGB_RED, RGB_DARKRED, // TEST ENEMY
                                        RGBHTML(0xd0d058), RGBHTML(0xa0a840), RGBHTML(0x708028), RGBHTML(0x405010), // DMG CLASSIC
                                        0, RGBHTML(0x7f9de0), RGBHTML(0x4e81db), RGBHTML(0x2c58ce) }; // MAGIC MISSILE
    // Load player color palettes. 
    set_sprite_palette(0, 1, wizard_palettes);
    // Load player sprites.
    set_sprite_data(0, 4, wizard_walk_up_tiles);
    set_sprite_data(4, 4, wizard_walk_down_tiles);
    set_sprite_data(8, 8, wizard_walk_side_tiles);

    set_sprite_palette(1, 4, palettes);

    set_sprite_data(16, 2, player_basic_proj_tiles);
    // Set projectile color palette. 
    for (int i = 4; i < 20; i++) 
        set_sprite_prop(i, 4);

    set_sprite_data(18, 1, test_enemy);
    for (int i = 20; i < 36; i++) 
        set_sprite_prop(i, 2);

    set_bkg_palette(0, 1, palettes);

    init_HUD();
    draw_HUD_health(player.health);
    draw_HUD_element(player.element);
    draw_HUD_usage(0);
    move_win(8, 128);
}

void main() {
    display_logo_splash();
    show_title();

    initPlayer();
    initEnemies(rooms[player.room_i][player.room_j].enemies);
    initProjs();

    initSprites();
    init_camera(testroom_big_data, 0x30, 7, testroom_big, testroom_bigWidth, testroom_bigHeight);

    spawnEnemy(60, 60, UP, 4, rooms[player.room_i][player.room_j].enemies);
    spawnEnemy(80, 60, UP, 8, rooms[player.room_i][player.room_j].enemies);
    spawnEnemy(120, 60, UP, 4, rooms[player.room_i][player.room_j].enemies);

    spawn_powerup(120, 120, PWR_FIRE, rooms[player.room_i][player.room_j].powerups);

    SHOW_SPRITES;
    SHOW_BKG;
    SHOW_WIN;
    DISPLAY_ON;

    while (true) {
        input();
        logic();
        draw();
    } 
}