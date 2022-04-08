#include "camera.h"
#include "rooms.h"

const uint8_t * tilemap;
uint8_t tile_offset;
uint8_t x, y;

/*  Loads in a single column of a tileset.
 *  
 *  @param x Starting X-coordinate (in tiles).
 *  @param y Starting Y-coordinate (in tiles).
 *  @param row_height Number of rows in the tilemap.
 *  @param map_width Width of the tilemap.
 *  @param p_src_map Pointer to the tilemap to be scrolled to. 
 */
void set_bkg_tiles_col(uint8_t x, uint8_t y, uint8_t row_height, uint8_t map_width, const uint8_t * p_src_map) {
    // Cache returned address of first map tile vram address
    uint8_t * p_col_screen = (uint8_t *)set_bkg_tile_xy(x, y, *p_src_map);
    while (--row_height) {
        // Move to next Screen Map_y and handle screen wraparound 0x9C00 -> 9800
        p_col_screen = (uint8_t *)((uint16_t)(p_col_screen + 32) & 0x9BFFU);
        p_src_map += map_width; // Move to next Map_y
        set_vram_byte(p_col_screen, *p_src_map);
    }
}

/*  Scrolls upward to the next tilemap.
 *
 *  @param x X-coordinate to start at.
 *  @param y Y-coordinate to start at.
 *  @param tilemap Tilemap to scroll to.
 *  @param tilemap_width Width of tilemap.
 *  @param tilemap_height Height of tilemap.
 *  @returns Y-coordinate ended at. 
 */
int scroll_up(uint8_t x, uint8_t y, const uint8_t * tilemap, uint8_t tilemap_width, uint8_t tilemap_height) {
    int i = tilemap_height;
    x %= 32;
    tilemap += tilemap_width * (tilemap_height - 1);
    while (i--) {
        wait_vbl_done();
        y--; y %= 32;
        set_bkg_tiles(x, y, tilemap_width, 1u, tilemap);
        tilemap -= tilemap_width;
        SCY_REG -= 8;
        delay(25);
    }
    return y;
}

/*  Scrolls downward to the next tilemap.
 *
 *  @param x X-coordinate to start at.
 *  @param y Y-coordinate to start at.
 *  @param tilemap Tilemap to scroll to.
 *  @param tilemap_width Width of tilemap.
 *  @param tilemap_height Height of tilemap.
 *  @returns Y-coordinate ended at. 
 */
int scroll_down(uint8_t x, uint8_t y, const uint8_t * tilemap, uint8_t tilemap_width, uint8_t tilemap_height) {
    int i = tilemap_height;
    y += tilemap_height;
    x %= 32;
    while (i--) {
        wait_vbl_done();
        set_bkg_tiles(x, y, tilemap_width, 1u, tilemap);
        tilemap += tilemap_width;
        y++; y %= 32;
        SCY_REG += 8;
        delay(25);
    }
    return y - 16;
}

/*  Scrolls leftward to the next tilemap.
 *
 *  @param x X-coordinate to start at.
 *  @param y Y-coordinate to start at.
 *  @param tilemap Tilemap to scroll to.
 *  @param tilemap_width Width of tilemap.
 *  @param tilemap_height Height of tilemap.
 *  @returns X-coordinate ended at. 
 */
int scroll_left(uint8_t x, uint8_t y, const uint8_t * tilemap, uint8_t tilemap_width, uint8_t tilemap_height) {
    int i = tilemap_width; 
    y %= 32;
    tilemap += (tilemap_width - 1);
    while (i--) {
        wait_vbl_done();
        x--; x %= 32;
        set_bkg_tiles_col(x, y, tilemap_height, tilemap_width, tilemap--);
        SCX_REG -= 8;
        delay(25);
    }
    return x;
}

/*  Scrolls rightward to the next tilemap.
 *
 *  @param x X-coordinate to start at.
 *  @param y Y-coordinate to start at.
 *  @param tilemap Tilemap to scroll to.
 *  @param tilemap_width Width of tilemap.
 *  @param tilemap_height Height of tilemap.
 *  @returns X-coordinate ended at. 
 */
int scroll_right(uint8_t x, uint8_t y, const uint8_t * tilemap, uint8_t tilemap_width, uint8_t tilemap_height) {
    int i = tilemap_width;
    x += tilemap_width;
    y %= 32;
    while (i--) {
        wait_vbl_done();
        set_bkg_tiles_col(x, y, tilemap_height, tilemap_width, tilemap++);
        x++; x %= 32;
        SCX_REG += 8;
        delay(25);
    }
    return x - 20;
}

void init_camera(const uint8_t * tiles, uint8_t tile_offset, uint8_t num_tiles, const uint8_t * _tilemap, uint8_t _tilemap_width, uint8_t _tilemap_height) {
    
}

void scroll_camera(Player * player) {
    hideEnemies();
    hide_powerups();
    switch(player->dir) {
        case UP:
            y = scroll_up(x, y, rooms[player->room_i][--player->room_j]->tilemap, 20u, 16u);
            break;
        case DOWN:
            y = scroll_down(x, y, rooms[player->room_i][++player->room_j]->tilemap, 20u, 16u);
            break;
        case LEFT:
            x = scroll_left(x, y, rooms[--player->room_i][player->room_j]->tilemap, 20u, 16u);
            break;
        case RIGHT:
            x = scroll_right(x, y, rooms[++player->room_i][player->room_j]->tilemap, 20u, 16u);
            break;
    }
}