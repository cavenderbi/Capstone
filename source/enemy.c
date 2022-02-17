#include "enemy.h"
/*  Initialize the test enemy.
    TODO: Remove this and never use it. */
void initTestEnemy() {
    testEnemy.x = 60;
    testEnemy.y = 60;
    testEnemy.dir = UP;
    testEnemy.health = 2;
}

/*  Initialize the enemies array. */
void initEnemies() {
    enemies.count = 0;
    for (int i = 0; i < sizeof(enemies.array) / sizeof(enemies.array[0]); i++)
        enemies.array[i].health = 0;
}

/*  Spawns in an enemy at the given x,y location, facing the given direction,
    with the given health. 
    @param x x-coordinate to spawn the enemy at.
    @param y y-coordinate to spawn the enemy at. 
    @param dir direction the enemy is facing when it spawns. 
    @param health starting health of the enemy. */
void spawnEnemy(uint8_t x, uint8_t y, Direction dir, uint8_t health) {
    for (int i = 0; i < sizeof(enemies.array) / sizeof(enemies.array[0]); i++)
        if (enemies.array[i].health == 0) {
            enemies.array[i].x = x;
            enemies.array[i].y = y;
            enemies.array[i].dir = dir;
            enemies.array[i].health = health;
            break;
        }
}

/*  Updates enemy and relevant sprites. */
void updateEnemies() {
    Enemy * current;
    for (int i = 0; i < sizeof(enemies.array) / sizeof(enemies.array[0]); i++) {
        current = &enemies.array[i];
        if (current->health > 0) {
            set_sprite_tile(17 + i, 13);
            move_sprite(17 + i, current->x, current->y);
        } else hide_sprite(17 + i);
    }
}