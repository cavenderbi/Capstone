#include "projectile.h"

Projectile projectiles[16];

/*  Initialize the projectile array. */
void initProjs() {
    for (Projectile * current = projectiles; current != projectiles + 8; current++)
        current->valid = false;
}

/*  Spawns a new projectile at the given x and y coordinates, facing the given direction. 
    @param x The starting x-coordinate of the projectile. 
    @param y The starting y-coordinate of the projectile. 
    @param dir The direction the projectile is facing. */
void shoot(uint8_t x, uint8_t y, Direction dir) {
    /*  Limit the number of projectiles, at least for now. */
    for (Projectile * current = projectiles; current != projectiles + 8; current++)
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
void updateProjs(Enemy * enemies, uint8_t pi, uint8_t pj) {
    //if (!(*projectiles).valid) return;
    const int speed = 3;
    int i = 4;
    for (Projectile * current = projectiles; current != projectiles + 8; current++, i++) {
        // Don't let projectiles leave the screen.
        if (current->x - (20*8 * pi) > 20*8 || current->y - (16*8 * pj) > 16*8) {
            hide_sprite(i);
            current->valid = false;
        } else if (current->valid) {
            /*  Move valid projectiles. */
            switch (current->dir) {
                case UP:
                    if (sprite_tile_collision(current->x, current->y - speed, current->dir)) {
                        current->y -= speed;
                        set_sprite_tile(i, 0x11);
                        set_sprite_prop(i, get_sprite_prop(i) & ~S_FLIPY);
                    } else current->valid = false;
                    break;
                case DOWN:
                    if (sprite_tile_collision(current->x, current->y + speed, current->dir)) {
                        current->y += speed;
                        set_sprite_tile(i, 0x11);
                        set_sprite_prop(i, get_sprite_prop(i) | S_FLIPY);
                    } else current->valid = false;
                    break;
                case LEFT:
                    if (sprite_tile_collision(current->x - speed, current->y, current->dir)) {
                        current->x -= speed;
                        set_sprite_tile(i, 0x10);
                        set_sprite_prop(i, get_sprite_prop(i) & ~S_FLIPX);
                    } else current->valid = false;
                    break;
                case RIGHT:
                    if (sprite_tile_collision(current->x + speed, current->y, current->dir)) {
                        current->x += speed;
                        set_sprite_tile(i, 0x10);
                        set_sprite_prop(i, get_sprite_prop(i) | S_FLIPX);
                    } else current->valid = false;
                    break;
            }
            move_sprite(i, current->x - camera.x_pos, current->y - camera.y_pos);
            /*  Projectile enemy collision. */
            for (Enemy * currentEnemy = enemies; currentEnemy != enemies + 16; currentEnemy++) {
                if (currentEnemy->health > 0 && sprite_sprite_collision(current->x, current->y, 8, 4, currentEnemy->x, currentEnemy->y, 8, 8)) {
                    currentEnemy->health--;
                    current->valid = false;
                } 
            }
        } else {
            hide_sprite(i);
            break;
        }
    }
}