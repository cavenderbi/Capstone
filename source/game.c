#include "game.h"

void initPlayer() {
    player.x = 88;
    player.y = 78;
    player.dir = RIGHT;
    player.maxHealth = 4;
    player.health = 4;
    player.alive = true;
}

void initTestEnemy() {
    testEnemy.x = 60;
    testEnemy.y = 60;
    testEnemy.dir = UP;
    testEnemy.health = 4;
}

// Shoots a projectile from the given x/y location. 
void shoot(uint8_t x, uint8_t y, Direction dir) {
    projectile.x = x;
    projectile.y = y;
    projectile.dir = dir;
    projectile.alive = true;
    move_sprite(1, x, y);
}

// Returns false when the player collides with the background tiles.
inline bool collision(UBYTE x, UBYTE y, Direction dir) {
    if (dir == DOWN || dir == RIGHT) {
        x += 7;
        y += 7;
    }
    return get_bkg_tile_xy((x - 8) / 8, ((y - 16) / 8)) == 0x14;
}

// Returns true when two sprites collide with each other.
inline bool spritecollision(UBYTE x1, UBYTE y1, UBYTE w1, UBYTE h1, UBYTE x2, UBYTE y2, UBYTE w2, UBYTE h2) {
    return (x1 < (x2 + w2) && (x1 + w1) > x2 && y1 < (y2 + h2) && (y1 + h1) > y2);
}

// Reads the user input and responds apropriately. 
void input() {
    UBYTE j = joypad();
    if (j & J_UP) {
        player.dir = UP;
        if (collision(player.x, player.y - 1, player.dir))
            player.y--;
    } else if (j & J_DOWN) {
        player.dir = DOWN;
        if(collision(player.x, player.y + 1, player.dir))
            player.y++;
    } else if (j & J_LEFT) {
        player.dir = LEFT;
        if (collision(player.x - 1, player.y, player.dir))
            player.x--;
    } else if (j & J_RIGHT) {
        player.dir = RIGHT;
        if (collision(player.x + 1, player.y, player.dir))
            player.x++;
    }

    // If player presses A, shoot test projectile.
    if (j & J_A) 
        shoot(player.x, player.y, player.dir);
}

// Controls other game functions such as moving projectiles. 
void logic() {
    switch (projectile.dir) {
        case UP:
            if (collision(projectile.x, projectile.y - 4, projectile.dir))
                projectile.y -= 4;
            else {
                hide_sprite(1);
                projectile.alive = false;
            }
            break;
        case DOWN:
            if (collision(projectile.x, projectile.y + 1, projectile.dir))
                projectile.y += 4;
            else {
                hide_sprite(1);
                projectile.alive = false;
            }
            break;
        case LEFT:
            if (collision(projectile.x - 4, projectile.y, projectile.dir))
                projectile.x -= 4;
            else {
                hide_sprite(1);
                projectile.alive = false;
            }
            break;
        case RIGHT:
            if (collision(projectile.x + 4, projectile.y, projectile.dir))
                projectile.x += 4;
            else {
                hide_sprite(1);
                projectile.alive = false;
            }
            break;
    }
    
    if (spritecollision(projectile.x, projectile.y, 8, 3, testEnemy.x, testEnemy.y, 8, 8)) {
        testEnemy.health--;
        if (testEnemy.health == 0) 
            hide_sprite(2);
    }
}

// Every ten frames, update the animation. 
void draw() {
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
    // Set the projectile sprite.
    switch (projectile.dir) {
        case UP:
            set_sprite_tile(1, 9);
            set_sprite_prop(1, get_sprite_prop(1) | S_FLIPY);
            break;
        case DOWN:
            set_sprite_tile(1, 9);
            set_sprite_prop(1, get_sprite_prop(1) & ~S_FLIPY);
            break;
        case LEFT:
            set_sprite_tile(1, 8);
            set_sprite_prop(1, get_sprite_prop(1) | S_FLIPX);
            break;
        case RIGHT:
            set_sprite_tile(1, 8);
            set_sprite_prop(1, get_sprite_prop(1) & ~S_FLIPX);
            break;
    }
    // Move the player sprite. 
    move_sprite(0, player.x, player.y);
    // Move the projectile sprite if it's alive.
    if (projectile.alive)
        move_sprite(1, projectile.x, projectile.y);
    // Wait until we're done drawing to the screen.
    wait_vbl_done();
}

void main() {
    show_title();
    const UWORD brick_palette[] = { RGB_WHITE, RGB_LIGHTGRAY, RGB_DARKGRAY, RGB_BLACK };
    const UWORD heart_palette[] = { 0, RGB_PINK, RGB_RED, RGB_DARKRED };
    const UWORD palette[] = { RGBHTML(0xd0d058), RGBHTML(0xa0a840), RGBHTML(0x708028), RGBHTML(0x405010) };
    set_sprite_palette(0, 1, palette);
    set_sprite_palette(1, 1, heart_palette);
    set_sprite_data(0, 8, arrow);
    set_sprite_tile(0, 0);
    set_sprite_prop(0, 1);

    set_sprite_data(8, 4, test_projectile);
    set_sprite_tile(1, 9);
    hide_sprite(1);

    set_sprite_data(13, 1, test_enemy);
    set_sprite_tile(2, 13);

    initPlayer();
    initTestEnemy();
    move_sprite(0, player.x, player.y);

    set_bkg_data(20, 44, testroomtiles);
    set_bkg_tiles(0, 0, testroom2Width, testroom2Height, testroom2);
    set_bkg_palette(0, 1, brick_palette);

    set_win_data(0, 20, hud_data);
    set_win_tiles(0, 0, hud_tilemapWidth, hud_tilemapHeight, hud_tilemap);
    move_win(8, 128);

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