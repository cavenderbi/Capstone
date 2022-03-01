#include "camera.h"

Cam camera, old_camera;

Map map, old_map;

static uint8_t * tilemap;
static uint8_t tilemap_height;
static uint8_t tilemap_width;

/*  Initializes the camera scrolling behavior.  
    @param tiles Pointer to the tiles.
    @param tile_offset Which index do the tiles start at in VRAM? 
    @param num_tiles The number of tiles to load into VRAM. 
    @param tilemap Pointer to the big tilemap. 
    @param tilemap_width Width in tiles of the tilemap.
    @param tilemap_height Height in tiles of the tilemap. */
void init_camera(uint8_t * tiles, uint8_t tile_offset, uint8_t num_tiles, uint8_t * _tilemap, uint8_t _tilemap_width, uint8_t _tilemap_height) {
    DISPLAY_OFF;
    SHOW_BKG;
    set_bkg_data(tile_offset, num_tiles, tiles);

    tilemap = _tilemap;
    tilemap_height = _tilemap_height;
    tilemap_width = _tilemap_width;

    map.x_pos = 0;
    map.y_pos = 0;
    old_map.x_pos = 0xff;
    old_map.y_pos = 0xff;
    /*  Draw a 20x18 (Gameboy screen sized) submap of the tilemap. */
    set_bkg_submap(map.x_pos, map.y_pos, 20, 18, tilemap, tilemap_width);
    DISPLAY_ON;

    camera.x_pos = 0;
    camera.y_pos = 0;
    old_camera.x_pos = 0;
    old_camera.y_pos = 0;

    SCX_REG = camera.x_pos;
    SCY_REG = camera.y_pos;
}

/*  Scrolls the camera in the given direction for the given distance in tiles. 
    @param dir Direction to scroll the camera. 
    @param dist Distance in 8x8 tiles to scroll the camera. */
void scroll_camera(Player * player) {
    /*  If the player is below the y-minPt and below the x-maxPt, then they left the room from the top*/
    switch (player->dir) {
    case UP:
        hideEnemies();
        for (int i = 0; i <= 128; i++) {
            camera.y_pos--;
            wait_vbl_done();
            set_camera();
            if (player->y_pos > camera.y_pos)
                scroll_sprite(0, 0, 1);
            else player->y_pos--;
        }
        player->room_j--;
        break;
    case DOWN:
        hideEnemies();
        for (int i = 0; i <= 128; i++) {
            camera.y_pos++;
            wait_vbl_done();
            set_camera();
            if (player->y_pos - 16 > camera.y_pos)
                scroll_sprite(0, 0, -1);
            else player->y_pos++;
        }
        player->room_j++;
        break;
    case LEFT:
        hideEnemies();
        for (int i = 0; i <= 160; i++) {
            camera.x_pos--;
            wait_vbl_done();
            set_camera();
            if (player->x_pos > camera.x_pos)
                scroll_sprite(0, 1, 0);
            else player->x_pos--;
        }
        player->room_i--;
        break;
    case RIGHT:
        hideEnemies();
        for (int i = 0; i <= 160; i++) {
            camera.x_pos++;
            wait_vbl_done();
            set_camera();
            if (player->x_pos - 8 > camera.x_pos)
                scroll_sprite(0, -1, 0);
            else player->x_pos++;
        }
        player->room_i++;
        break;
    }
}

/*  The meat and potatoes of the camera scrolling operation. Using
    set_bkg_submap, this function draws smaller parts of the larger tilemap
    infront of the camera. This will allow for the player to move around a map
    larger than 32x32 tiles. 
    
    It's fragile. Don't touch it and don't call it anywhere other than scroll_camera. */
static void set_camera() {
    /*  Update hardware scroll position. */
    SCX_REG = camera.x_pos;
    SCY_REG = camera.y_pos;
    /*  Up or down. */
    map.y_pos = (uint8_t)(camera.y_pos >> 3u);
    if (map.y_pos != old_map.y_pos) {
        if (camera.y_pos < old_camera.y_pos)
            set_bkg_submap(map.x_pos, map.y_pos, MIN(21u, tilemap_width - map.x_pos), 1, tilemap, tilemap_width);
        else if (tilemap_height - 16u > map.y_pos)
            set_bkg_submap(map.x_pos, map.y_pos + 16u, MIN(21u, tilemap_width - map.x_pos), 1, tilemap, tilemap_width);
        old_map.y_pos = map.y_pos;
    }
    /*  Left or right? */
    map.x_pos = (uint8_t)(camera.x_pos >> 3u);
    if (map.x_pos != old_map.x_pos) {
        if (camera.x_pos < old_camera.x_pos)
            set_bkg_submap(map.x_pos, map.y_pos, 1, MIN(19u, tilemap_height - map.y_pos), tilemap, tilemap_width);
        else if (tilemap_width - 20u > map.x_pos) 
            set_bkg_submap(map.x_pos + 20u, map.y_pos, 1, MIN(19u, tilemap_height - map.y_pos), tilemap, tilemap_width);
        old_map.x_pos = map.x_pos;
    }
    /*  Update old camera positions. */
    old_camera.x_pos = camera.x_pos;
    old_camera.y_pos = camera.y_pos;
}
inline uint8_t get_camera_x_pos() { return camera.x_pos; }
inline uint8_t get_camera_y_pos() { return camera.y_pos; }
inline uint8_t get_tilemap_x_pos() { return map.x_pos; }
inline uint8_t get_tilemap_y_pos() { return map.y_pos; }