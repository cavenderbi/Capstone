#include "camera.h"
#include "rooms.h"

uint8_t tile_offset;
Cam cam;

#define EMPTY_TILE 0x21

/*  Loads in a single column of a tileset.
 *  
 *  @param x Starting X-coordinate (in tiles).
 *  @param y Starting Y-coordinate (in tiles).
 *  @param row_height Number of rows in the tilemap.
 *  @param map_width Width of the tilemap.
 *  @param p_src_map Pointer to the tilemap to be scrolled to. 
 */
void set_bkg_tiles_col(uint8_t x, uint8_t y, uint8_t row_height, uint8_t map_width, const uint8_t * p_src_map) {
    // Cache returned address of first cam tile vram address
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
void scroll_up(Player * player, const uint8_t * tilemap, uint8_t tilemap_width, uint8_t tilemap_height) {
    int i = tilemap_height;
    tilemap += tilemap_width * (tilemap_height - 1);
    while (i--) {
        wait_vbl_done();
        cam.y_pos--;
        // Draw the new row.
        set_bkg_tiles(cam.x_pos % 32, cam.y_pos % 32, tilemap_width, 1u, tilemap);
        // Move the camera.
        wait_vbl_done();
        SCY_REG -= 8;
        // Erase the old row.
        fill_bkg_rect(cam.x_pos % 32, (cam.y_pos + tilemap_height) % 32, tilemap_width, 1u, EMPTY_TILE);
        tilemap -= tilemap_width;
        // Handle player position. 
        if ((player->y_pos / 8) - cam.y_pos < 17) {
            scroll_sprite(0, 0, 8);
            scroll_sprite(1, 0, 8);
            scroll_sprite(2, 0, 8);
            scroll_sprite(3, 0, 8);
        } else player->y_pos -= 8;
    }
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
void scroll_down(Player * player, const uint8_t * tilemap, uint8_t tilemap_width, uint8_t tilemap_height) {
    int i = tilemap_height;
    while (i--) {
        wait_vbl_done();
        // Draw the new row.
        set_bkg_tiles(cam.x_pos % 32, (cam.y_pos + tilemap_height) % 32, tilemap_width, 1u, tilemap);
        // Move the camera.
        wait_vbl_done();
        SCY_REG += 8;
        // Erase the old row.
        fill_bkg_rect(cam.x_pos % 32, cam.y_pos % 32, tilemap_width, 1u, EMPTY_TILE);
        tilemap += tilemap_width;
        cam.y_pos++;
        // Handle player position. 
        if ((player->y_pos / 8) - 2 > cam.y_pos) {
            scroll_sprite(0, 0, -8);
            scroll_sprite(1, 0, -8);
            scroll_sprite(2, 0, -8);
            scroll_sprite(3, 0, -8);
        } else player->y_pos += 8;
    }
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
void scroll_left(Player * player, const uint8_t * tilemap, uint8_t tilemap_width, uint8_t tilemap_height) {
    int i = tilemap_width; 
    tilemap += (tilemap_width - 1);
    while (i--) {
        wait_vbl_done();
        cam.x_pos--;
        // Draw the new column.
        set_bkg_tiles_col(cam.x_pos % 32, cam.y_pos % 32, tilemap_height, tilemap_width, tilemap--);
        // Move the camera.
        wait_vbl_done();
        SCX_REG -= 8;
        // Erase the old column.
        fill_bkg_rect((cam.x_pos + tilemap_width) % 32, cam.y_pos % 32, 1u, tilemap_height, EMPTY_TILE);
        // Handle player position. 
        if ((player->x_pos / 8) - cam.x_pos < 20) {
            scroll_sprite(0, 8, 0);
            scroll_sprite(1, 8, 0);
            scroll_sprite(2, 8, 0);
            scroll_sprite(3, 8, 0);
        } else player->x_pos -= 8;
    }
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
void scroll_right(Player * player, const uint8_t * tilemap, uint8_t tilemap_width, uint8_t tilemap_height) {
    int i = tilemap_width;
    while (i--) {
        wait_vbl_done();
        // Draw the new column.
        set_bkg_tiles_col((cam.x_pos + tilemap_width) % 32, cam.y_pos % 32, tilemap_height, tilemap_width, tilemap++);
        // Move the camera.
        wait_vbl_done();
        SCX_REG += 8;
        // Erase the old column.
        fill_bkg_rect(cam.x_pos % 32, cam.y_pos % 32, 1u, tilemap_height, EMPTY_TILE);
        cam.x_pos++;
        // Handle player position. 
        if ((player->x_pos / 8) - 1 > cam.x_pos) {
            scroll_sprite(0, -8, 0);
            scroll_sprite(1, -8, 0);
            scroll_sprite(2, -8, 0);
            scroll_sprite(3, -8, 0);
        } else player->x_pos += 8;
    }
}

void init_camera(const uint8_t * tiles, uint8_t tile_offset, uint8_t num_tiles, const uint8_t * tilemap, uint8_t x_pos, uint8_t y_pos) {
    DISPLAY_OFF;

    // Initialize the camera's position. 
    SCX_REG = (cam.x_pos = x_pos * 20) * 8;
    SCY_REG = (cam.y_pos = y_pos * 16) * 8;

    // Clear the screen.
    fill_rect(0, 0, 32, 32, 0x21);
    // Draw the first tilemap. 
    set_bkg_data(tile_offset, num_tiles, tiles);
    set_bkg_tiles(SCX_REG / 8, SCY_REG / 8, 20u, 16u, tilemap);

    DISPLAY_ON;
    SHOW_BKG;
}

void scroll_camera(Player * player) {
    hide_sprites_range(4, MAX_HARDWARE_SPRITES);
    switch(player->dir) {
        case UP:
            scroll_up(player, rooms[player->room_i][--player->room_j]->tilemap, 20u, 16u);
            break;
        case DOWN:
            scroll_down(player, rooms[player->room_i][++player->room_j]->tilemap, 20u, 16u);
            break;
        case LEFT:
            scroll_left(player, rooms[--player->room_i][player->room_j]->tilemap, 20u, 16u);
            break;
        case RIGHT:
            scroll_right(player, rooms[++player->room_i][player->room_j]->tilemap, 20u, 16u);
            break;
    }
}