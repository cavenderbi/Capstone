#pragma bank 1

#include "game.h"
#include <rand.h>

Player player;

BANKREF(main)
BANKREF_EXTERN(main)

// Reads the user input and responds appropriately. 
void input() BANKED {
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
        if (sys_time - prev_shot > 15) {
            // Spawn the projectile.
            shoot(player.x_pos, player.y_pos, player.dir, player.element);
            // If the usage is >= 14, then it isn't valid and shouldn't be updated. 
            if (--player.usage <= 14 * NUM_SHOTS_PER_BAR && player.usage > 0)
                draw_HUD_usage(player.usage / NUM_SHOTS_PER_BAR);
            // If the player uses all of their power-up charge, they revert back to normal. 
            else
                draw_HUD_element(player.element = PWR_NONE);
            prev_shot = sys_time;
        }
    }

    // TODO: Remove this and use enemies to deal damage. 
    static bool changed = true;
    if (j & J_B) {
        if (changed) {
            changed = false;
            // Get the next player element.
            draw_HUD_health(--player.health);
        }
    } else changed = true;
}

// Controls other game functions such as moving projectiles. 
void logic() BANKED {
    //  Has player left the room?
    int minx = (20*8 * player.room_i) + 8, 
        miny = (16*8 * player.room_j) + 16, 
        maxx = minx + 20*8-7, //  18 tiles * 8 pixels per tile.
        maxy = miny + 16*8-7; //  14 tiles * 8 pixels per tile.
    if (player.x_pos > maxx || player.x_pos < minx || player.y_pos > maxy || player.y_pos < miny) {
        SWITCH_ROM_MBC5(BANK(camera));
        scroll_camera(&player);
        SWITCH_ROM_MBC5(BANK(main));
    }
    updateProjs(rooms[player.room_i][player.room_j]->enemies);
    updateEnemies(rooms[player.room_i][player.room_j]->enemies, &player);
    update_powerups(rooms[player.room_i][player.room_j]->powerups, &player);
}

// Every ten frames, update the animation. 
void draw() BANKED {
    static uint8_t offset = 0; 
    // If the D-PAD is pressed, animate the sprite. 
    if (joypad() & (J_UP | J_DOWN | J_LEFT | J_RIGHT)) {
        offset = (sys_time / 12) & 1;
    }

    // Move the player's sprites.
    switch (player.dir) {
        case UP: 
            move_metasprite(wizard_walk_up_metasprites[offset], 0, 0, player.x_pos - (cam.x_pos * 8), player.y_pos - (cam.y_pos * 8));
            break;
        case DOWN:
            move_metasprite(wizard_walk_down_metasprites[offset], 4, 0, player.x_pos - (cam.x_pos * 8), player.y_pos - (cam.y_pos * 8));
            break;
        case LEFT:
            move_metasprite(wizard_walk_side_metasprites[offset], 8, 0, player.x_pos - (cam.x_pos * 8), player.y_pos - (cam.y_pos * 8));
            break;
        case RIGHT:
            move_metasprite_vflip(wizard_walk_side_metasprites[offset], 8, 0, player.x_pos - (cam.x_pos * 8), player.y_pos - (cam.y_pos * 8));
            break;
    }

    // Wait until we're done drawing to the screen.
    wait_vbl_done();
}

void initSprites() BANKED {
    const palette_color_t greyscale[4] = {RGB_WHITE, RGB_LIGHTGRAY, RGB_DARKGRAY, RGB_BLACK};
    const palette_color_t magic_missile_pal[4] = {0, RGBHTML(0x7f9de0), RGBHTML(0x4e81db), RGBHTML(0x2c58ce)};
    const palette_color_t test_enemy_pal[4] = {0, RGB_RED, RGB_RED, RGB_DARKRED};
    // 1 palette for the player. This will change based on the current damage type. 
    set_sprite_palette(0, 1, wizard_walk_down_palettes);
    // 3 palettes for different enemy types.
    set_sprite_palette(1, 1, knight_walk_side_palettes);
    // 4 palettes for the different damage types.
    set_sprite_palette(4, 1, magic_missile_pal);
    set_sprite_palette(5, 1, fire_palettes);
    set_sprite_palette(6, 1, frost_palettes);
    set_sprite_palette(7, 1, shock_palettes);

    // Load player sprites.
    set_sprite_data(0, 4, wizard_walk_up_tiles);
    set_sprite_data(4, 4, wizard_walk_down_tiles);
    set_sprite_data(8, 8, wizard_walk_side_tiles);

    set_sprite_data(16, player_basic_proj_TILE_COUNT, player_basic_proj_tiles);

    set_sprite_data(0x12, knight_walk_up_TILE_COUNT, knight_walk_up_tiles);
    set_sprite_data(0x1D, knight_walk_side_TILE_COUNT, knight_walk_side_tiles);
    set_sprite_data(0x16, knight_walk_down_TILE_COUNT, knight_walk_down_tiles);

    set_sprite_data(0x26, 1, powerorb_tiles);

    set_bkg_palette(0, 1, greyscale);

    init_HUD();
    draw_HUD_health(player.health);
    draw_HUD_usage(0);
    draw_HUD_element(player.element);
    move_win(7, 128);
}

/* void putbutton(uint8_t pad) BANKED {
    switch(pad) {
        case J_A:      puts("A"); break;
        case J_B:      puts("B"); break;
        case J_UP:     puts("^"); break;
        case J_DOWN:   puts("v"); break;
        case J_LEFT:   puts("<"); break;
        case J_RIGHT:  puts(">"); break;
        case J_SELECT: puts("s"); break;
        case J_START:  puts("S"); break;
    }
} */

void seed_rand() BANKED {
    DISPLAY_ON;
    SHOW_BKG;
    if (_cpu == CGB_TYPE) {
        VBK_REG = 1; 
        fill_rect(0, 0, 20, 18, 0);
        VBK_REG = 0;
    }
    // font_init();
    // font_load(font_italic);
    // gotoxy(0, 0);
    //puts("Getting seed.");
    //putbutton(waitpad(0xFF));
    waitpad(0xFF);
    waitpadup();
    uint16_t seed = DIV_REG;
    //putbutton(waitpad(0xFF));
    waitpad(0xFF);
    waitpadup();
    seed |= (uint16_t)DIV_REG << 8;
    initrand(seed);
    HIDE_BKG;
    DISPLAY_OFF;
}

void main() NONBANKED {
//  Initialize sound. 
    LCDC_REG = 0xD1;
    BGP_REG  = 0xE4;
    NR52_REG = 0x80;
    NR51_REG = 0xFF;
    NR50_REG = 0x77;
    
    SWITCH_ROM_MBC5(BANK(show_title));
    display_logo_splash();
    show_title();
    SWITCH_ROM_MBC5(BANK(main));

play_again: 
    seed_rand();
    generate_rooms(&player);
    player.health = 14;
    initSprites();

    SWITCH_ROM_MBC5(BANK(camera));
    init_camera(bricktileset_tiles, 0x21, bricktileset_TILE_COUNT, rooms[player.room_i][player.room_j]->tilemap, player.room_i, player.room_j);
    SWITCH_ROM_MBC5(BANK(main));

    SHOW_SPRITES;
    SHOW_BKG;
    SHOW_WIN;
    DISPLAY_ON;

    while (player.health > 0) {
        input();
        logic();
        draw();
    }
//  Free the memory used by the rooms. The last thing I need is my 8KB of WRAM being leaky.
    free_rooms();   
    
    show_deathscreen();
    goto play_again;    
}