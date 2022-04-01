#include <stdlib.h>

#include "enemy.h"

/*  Initialize the enemies array. */
void initEnemies(Enemy * enemies) {
    for (Enemy * current = enemies; current != enemies + 8; current++)
        current->health = 0;
}

/*  Spawns in an enemy at the given x,y location, facing the given direction,
    with the given health. 
    @param x x-coordinate to spawn the enemy at.
    @param y y-coordinate to spawn the enemy at. 
    @param dir direction the enemy is facing when it spawns. 
    @param health starting health of the enemy. */
void spawnEnemy(uint8_t x, uint8_t y, Direction dir, uint8_t health, Enemy * enemies) {
    int i = 0xB;
    for (Enemy * current = enemies; current != enemies + 8; current++, i++) {
        set_sprite_tile(i, 0x12);
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
    TODO: Implement true pathfinding. A* pathfinding maybe? */
void updateEnemies(Enemy * enemies, Player * player) {
    int i = 0xB;
    //int16_t x, y;
    for (Enemy * current = enemies; current != enemies + 8; current++, i++) {
        if (current->health > 0) {
            // Update the enemy position based on the player's position.
            if ((sys_time >> 1) & 1) {
                if (abs(player->y_pos - current->y_pos) > abs(player->x_pos - current->x_pos)) {
                    if (current->y_pos > player->y_pos) current->y_pos--;
                    else if (current->y_pos < player->y_pos) current->y_pos++;
                } else {
                    if (current->x_pos > player->x_pos) current->x_pos--; 
                    else if (current->x_pos < player->x_pos) current->x_pos++;
                }
            }
            // Move the enemy sprite to the correct position. 
            move_sprite(i, current->x_pos - camera.x_pos, current->y_pos - camera.y_pos);
        } else hide_sprite(i);
    }
}

void hideEnemies() {
    for (int i = 0xB; i <= 0x13; ++i) 
        hide_sprite(i);
}