#pragma bank 1

#include <stdlib.h>
#include <rand.h>

#include "enemy.h"
#include "gb/metasprites.h"
#include "../res/knight_walk_up.h"
#include "../res/knight_walk_down.h"
#include "../res/knight_walk_side.h"

#define LEN(arr) ((int) (sizeof (arr) / sizeof (*arr)))


/*  Spawns in an enemy at the given x,y location, facing the given direction,
 *  with the given health. 
 *  @param x x-coordinate to spawn the enemy at.
 *  @param y y-coordinate to spawn the enemy at. 
 *  @param dir direction the enemy is facing when it spawns. 
 *  @param health starting health of the enemy. 
 */
void spawnEnemy(uint16_t x, uint16_t y, Direction dir, uint8_t health, Enemy * enemies) {
    for (Enemy * current = enemies; current != enemies + 8; current++) {
        if (current->health == 0) {
            current->x_pos = x;
            current->y_pos = y;
            current->dir = dir;
            current->health = health;
            break;
        }
    }
}

/*  Updates enemy and relevant sprites. 
 *  TODO: Implement true pathfinding. A* pathfinding maybe? 
 */
void updateEnemies(Enemy * enemies, Player * player) {
    int i = 0x04;
    //int16_t x, y;
    for (Enemy * current = enemies; current != enemies + 4; current++, i+=4) {
        if (current->health > 0 && current->health < 20) {
            // Update the enemy position based on the player's position.
            if ((sys_time >> 2) & 1) {
                if (abs(player->y_pos - current->y_pos) > 0) {
                    if (current->y_pos > player->y_pos) { current->y_pos--; current->dir = UP; }
                    else if (current->y_pos < player->y_pos) { current->y_pos++; current->dir = DOWN; }
                } else {
                    if (current->x_pos > player->x_pos) { current->x_pos--; current->dir = LEFT; }
                    else if (current->x_pos < player->x_pos) { current->x_pos++; current->dir = RIGHT; }
                }
            }
            // Move the enemy sprite to the correct position. 
            switch (current->dir) {
                case UP:
                    move_metasprite(knight_walk_up_metasprites[(sys_time / 12) & 1], 0x12, i, current->x_pos - (cam.x_pos * 8), current->y_pos - (cam.y_pos * 8));
                    break;
                case DOWN:
                    move_metasprite(knight_walk_down_metasprites[(sys_time / 12) & 1], 0x16, i, current->x_pos - (cam.x_pos * 8), current->y_pos - (cam.y_pos * 8));
                    break;
                case LEFT:
                    move_metasprite(knight_walk_side_metasprites[(sys_time / 12) & 1], 0x1D, i, current->x_pos - (cam.x_pos * 8), current->y_pos - (cam.y_pos * 8));
                    break;
                case RIGHT:
                    move_metasprite_vflip(knight_walk_side_metasprites[(sys_time / 12) & 1], 0x1D, i, current->x_pos - (cam.x_pos * 8), current->y_pos - (cam.y_pos * 8));
                    break;
            }
        } else {
            switch (current->dir) {
            case UP:
                hide_metasprite(knight_walk_up_metasprites[(sys_time / 12) & 1], i);
                break;
            case DOWN:
                hide_metasprite(knight_walk_down_metasprites[(sys_time / 12) & 1], i);
                break;
            case LEFT:
            case RIGHT:
                hide_metasprite(knight_walk_side_metasprites[(sys_time / 12) & 1], i);
                break;
            }
        }
    }
}