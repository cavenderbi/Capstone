#include "enemy.h"

/*  Initialize the enemies array. */
void initEnemies() {
    enemies.count = 0;
    for (Enemy * current = enemies.array; current < &enemies.array[15]; current++)
        current->health = 0;
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

/*  Updates enemy and relevant sprites. 
    For now, they bounce back and forth against the wall.
    TODO: Implement true pathfinding. A* pathfinding maybe? */
void updateEnemies() {
    int i = 0;
    const int speed = 1;
    for (Enemy * current = enemies.array; current < &enemies.array[15]; current++, i++) {
        //printf("%d\n", current->health);
        if (current->health > 0) {
            switch (current->dir) {
                case UP:
                    if (sprite_tile_collision(current->x, current->y - speed, current->dir)) {
                        current->y -= speed;
                        set_sprite_tile(17 + i, 13);
                    } else { current->dir = DOWN; }
                    break;
                case DOWN:
                    if (sprite_tile_collision(current->x, current->y + speed, current->dir)) {
                        current->y += speed;
                        set_sprite_tile(17 + i, 13);
                    } else { current->dir = UP; }
                    break;
            }
            move_sprite(17 + i, current->x - camera.x_pos, current->y - camera.y_pos);
        } else hide_sprite(17 + i);
    }
}