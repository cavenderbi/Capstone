#include "projectile.h"

Projectile projectiles[16];

/*  Initialize the projectile array. */
void initProjs() {
    for (Projectile * current = projectiles; current != projectiles + 16; current++)
        current->valid = false;
}

/*  Spawns a new projectile at the given x and y coordinates, facing the given direction. 
    @param x The starting x-coordinate of the projectile. 
    @param y The starting y-coordinate of the projectile. 
    @param dir The direction the projectile is facing. */
void shoot(uint8_t x, uint8_t y, Direction dir) {
    /*  Limit the number of projectiles, at least for now. */
    for (Projectile * current = projectiles; current != projectiles + 16; current++)
        if (!current->valid) {
            current->x = x;
            current->y = y;
            current->dir = dir;
            current->valid = true;
            break;
        }
}

/*  Updates the projectiles position and detects projectile collision. 
    Then updates the relevant sprites. */
void updateProjs() {
    const int speed = 4;
    int i = 0;
    for (Projectile * current = projectiles; current != projectiles + 16; current++, i++) {
        if (current->valid) {
            /*  Move valid projectiles. */
            switch (current->dir) {
                case UP:
                    if (sprite_tile_collision(current->x, current->y - speed, current->dir)) {
                        current->y -= speed;
                        set_sprite_tile(1 + i, 9);
                        set_sprite_prop(1 + i, get_sprite_prop(1 + i) | S_FLIPY);
                    } else current->valid = false;
                    break;
                case DOWN:
                    if (sprite_tile_collision(current->x, current->y + speed, current->dir)) {
                        current->y += speed;
                        set_sprite_tile(1 + i, 9);
                        set_sprite_prop(1 + i, get_sprite_prop(1 + i) & ~S_FLIPY);
                    } else current->valid = false;
                    break;
                case LEFT:
                    if (sprite_tile_collision(current->x - speed, current->y, current->dir)) {
                        current->x -= speed;
                        set_sprite_tile(1 + i, 8);
                        set_sprite_prop(1 + i, get_sprite_prop(1 + i) | S_FLIPX);
                    } else current->valid = false;
                    break;
                case RIGHT:
                    if (sprite_tile_collision(current->x + speed, current->y, current->dir)) {
                        current->x += speed;
                        set_sprite_tile(1 + i, 8);
                        set_sprite_prop(1 + i, get_sprite_prop(1 + i) & ~S_FLIPX);
                    } else current->valid = false;
                    break;
            }
            move_sprite(1 + i, current->x - camera.x_pos, current->y - camera.y_pos);
            /*  Projectile enemy collision. */
            for (Enemy * currentEnemy = enemies; currentEnemy != enemies + 16; currentEnemy++) {
                if (currentEnemy->health > 0 && sprite_sprite_collision(current->x, current->y, 8, 4, currentEnemy->x, currentEnemy->y, 8, 8)) {
                    currentEnemy->health--;
                    current->valid = false;
                } 
            }
        } else hide_sprite(1 + i);
    }
}