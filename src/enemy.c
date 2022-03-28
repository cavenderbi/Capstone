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
    for (Enemy * current = enemies; current != enemies + 8; current++)
        if (current->health == 0) {
            current->x = x;
            current->y = y;
            current->dir = dir;
            current->health = health;
            break;
        }
}

/*  Updates enemy and relevant sprites. 
    For now, they bounce back and forth against the wall.
    TODO: Implement true pathfinding. A* pathfinding maybe? */
void updateEnemies(Enemy * enemies) {
    int i = 0xB;
    const int speed = 1;
    for (Enemy * current = enemies; current != enemies + 8; current++, i++) {
        if (current->health > 0) {
            set_sprite_tile(i, 0x12);
            move_sprite(i, current->x - camera.x_pos, current->y - camera.y_pos);
        } else hide_sprite(i);
    }
}

void hideEnemies() {
    for (int i = 0xB; i <= 0x13; ++i) 
        hide_sprite(i);
}