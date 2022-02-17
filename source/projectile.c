#include "projectile.h"

/*  Initialize the projectile array. */
void initProjs() {
    projectiles.count = 0;
    for (int i = 0; i < sizeof(projectiles.array) / sizeof(projectiles.array[0]); i++)
        projectiles.array[i].valid = false;
}

/*  Spawns a new projectile at the given x and y coordinates, facing the given direction. 
    @param x The starting x-coordinate of the projectile. 
    @param y The starting y-coordinate of the projectile. 
    @param dir The direction the projectile is facing. */
void shoot(uint8_t x, uint8_t y, Direction dir) {
    /*  Limit the number of projectiles, at least for now. */
    for (int i = 0; i < sizeof(projectiles.array) / sizeof(projectiles.array[0]); i++)
        if (!projectiles.array[i].valid) {
            projectiles.count++;
            projectiles.array[i].x = x;
            projectiles.array[i].y = y;
            projectiles.array[i].dir = dir;
            projectiles.array[i].valid = true;
            break;
        }
}

/*  Updates the projectiles position and detects projectile collision. 
    Then updates the relevant sprites. */
void updateProjs() {
    const int speed = 4;
    Projectile * current;
    for (int i = 0; i < sizeof(projectiles.array) / sizeof(projectiles.array[0]); i++) {
        current = &projectiles.array[i];
        if (current->valid) {
            /*  Move valid projectiles. */
            switch (current->dir) {
                case UP:
                    if (sprite_tile_collision(current->x, current->y - speed, current->dir)) {
                        current->y -= speed;
                        set_sprite_tile(1 + i, 9);
                        set_sprite_prop(1 + i, get_sprite_prop(1 + i) | S_FLIPY);
                    } else { current->valid = false; projectiles.count--; }
                    break;
                case DOWN:
                    if (sprite_tile_collision(current->x, current->y + speed, current->dir)) {
                        current->y += speed;
                        set_sprite_tile(1 + i, 9);
                        set_sprite_prop(1 + i, get_sprite_prop(1 + i) & ~S_FLIPY);
                    } else { current->valid = false; projectiles.count--; }
                    break;
                case LEFT:
                    if (sprite_tile_collision(current->x - speed, current->y, current->dir)) {
                        current->x -= speed;
                        set_sprite_tile(1 + i, 8);
                        set_sprite_prop(1 + i, get_sprite_prop(1 + i) | S_FLIPX);
                    } else { current->valid = false; projectiles.count--; }
                    break;
                case RIGHT:
                    if (sprite_tile_collision(current->x + speed, current->y, current->dir)) {
                        current->x += speed;
                        set_sprite_tile(1 + i, 8);
                        set_sprite_prop(1 + i, get_sprite_prop(1 + i) & ~S_FLIPX);
                    } else { current->valid = false; projectiles.count--; }
                    break;
            }
            move_sprite(1 + i, current->x, current->y);
            /*  Projectile enemy collision. */
            Enemy * currentEnemy;
            for (int i = 0; i < sizeof(enemies.array) / sizeof(enemies.array[0]); i++) {
                currentEnemy = &enemies.array[i];
                if (currentEnemy->health > 0 && sprite_sprite_collision(current->x, current->y, 8, 4, currentEnemy->x, currentEnemy->y, 8, 8)) {
                    currentEnemy->health--;
                    projectiles.count--;
                    current->valid = false;
                } 
            }
        } else hide_sprite(1 + i);
    }
}