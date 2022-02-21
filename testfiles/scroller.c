#include <gb/gb.h>
#include <stdint.h>

#include "../source/direction.h"
#include "bigmap_map.h"
#include "bigmap_tiles.h"

#define CAMERA_MAX_Y ((bigmap_mapHeight - 18) * 8)
#define CAMERA_MAX_X ((bigmap_mapWidth - 20) * 8)

#define MIN(A, B) A < B ? A : B

uint8_t joy;

struct {
    uint16_t x;
    uint16_t y;
} camera, old_camera;

struct {
    uint8_t x;
    uint8_t y;
} map, old_map;

void set_camera() {
    /*  Update hardware scroll position. */
    SCY_REG = camera.y;
    SCX_REG = camera.x;
    /*  Up or down. */
    /*  Divide by 8, cast to a unsigned byte. */
    map.y = (uint8_t)(camera.y >> 3u);
    if (map.y != old_map.y){
        /*  Moving up. */
        if (camera.y < old_camera.y) 
            /*  Starting at tile map.x, map.y (above the camera), draw an at most 21 tile wide by 1 tile tall submap of the given tilemap. */
            set_bkg_submap(map.x, map.y, MIN(21u, bigmap_mapWidth - map.x), 1, bigmap_map, bigmap_mapWidth);
        /*  Moving down. */
        else if (bigmap_mapHeight - 18u > map.y) 
            set_bkg_submap(map.x, map.y + 18u, MIN(21u, bigmap_mapWidth - map.x), 1, bigmap_map, bigmap_mapWidth);
        old_map.y = map.y;
    }
    /*  Left or right. */
    /*  Divide by 8, cast to a unsigned byte. */
    map.x = (uint8_t)(camera.x >> 3u);
    if (map.x != old_map.x) {
        /*  Moving left. */
        if (camera.x < old_camera.x)
            set_bkg_submap(map.x, map.y, 1, MIN(19u, bigmap_mapHeight - map.y), bigmap_map, bigmap_mapWidth);
        else if (bigmap_mapWidth - 20u > map.x)
            set_bkg_submap(map.x + 20u, map.y, 1, MIN(19u, bigmap_mapHeight - map.y), bigmap_map, bigmap_mapWidth);
        old_map.x = map.x;
    }
    /*  Update old camera position. */
    old_camera.x = camera.x;
    old_camera.y = camera.y;
}

void scroll_cam(Direction dir) {
    switch (dir) {
        case UP:
            for (int i = 0; i <= 18 * 8; i++) {
                camera.y--;
                wait_vbl_done();
                set_camera();
            }
            break;
        case DOWN:
            for (int i = 0; i <= 18 * 8; i++) {
                camera.y++;
                wait_vbl_done();
                set_camera();
            }
            break;
        case LEFT:
            for (int i = 0; i <= 20 * 8; i++) {
                camera.x--;
                wait_vbl_done();
                set_camera();
            }
            break;
        case RIGHT:
            for (int i = 0; i <= 20 * 8; i++) {
                camera.x++;
                wait_vbl_done();
                set_camera();
            }
            break;
    }
}

void main() {
    DISPLAY_OFF;
    SHOW_BKG;
    set_bkg_data(0, sizeof(bigmap_tiles) >> 3u, bigmap_tiles);

    map.x = 0;
    map.y = 0;
    old_map.x = 0xFF;
    old_map.y = 0xFF;
    /*  Draw a 20x18 (Gameboy screen sized) submap of the tilemap. */
    set_bkg_submap(map.x, map.y, 20, 18, bigmap_map, bigmap_mapWidth);
    DISPLAY_ON;

    camera.x = 0;
    camera.y = 0;
    old_camera.x = 0;
    old_camera.y = 0;

    SCX_REG = camera.x;
    SCY_REG = camera.y;

    while (TRUE) {
        joy = joypad();
        /*  Up or down. */
        if (joy & J_UP){
            if (camera.y != 0)
                scroll_cam(UP);
        } else if (joy & J_DOWN) {
            if (camera.y < CAMERA_MAX_Y)
                scroll_cam(DOWN);
        } else if (joy & J_LEFT) {
            if (camera.x != 0)
                scroll_cam(LEFT);
        } else if (joy & J_RIGHT) {
            if (camera.x < CAMERA_MAX_X)
                scroll_cam(RIGHT);
        }
    }
}