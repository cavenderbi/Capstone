#include "projectile.h"

Projectile projectiles[4];

/*  Initialize the projectile array. */
void initProjs() {
    for (Projectile * current = projectiles; current != projectiles + 4; current++)
        current->valid = false;
}

/*  Spawns a new projectile at the given x and y coordinates, facing the given direction. 
    @param x The starting x-coordinate of the projectile. 
    @param y The starting y-coordinate of the projectile. 
    @param dir The direction the projectile is facing. */
void shoot(uint8_t x, uint8_t y, Direction dir, PWR_TYPE type) {
    /*  Limit the number of projectiles, at least for now. */
    int i = 4;
    for (Projectile * current = projectiles; current != projectiles + 4; current++, i++)
        if (!current->valid) {
            current->x = x;
            current->y = y;
            current->dir = dir;
            current->valid = true;
            // Set color palette and projectile damage based on damage type. 
            switch(type) {
                case PWR_NONE:
                    set_sprite_prop(i, 4);
                    break;
                case PWR_FIRE:
                    set_sprite_prop(i, 5);
                    current->dmg = 2;
                    break;
                case PWR_FROST:
                    set_sprite_prop(i, 6);
                    current->dmg = 1;
                    break;
                case PWR_SHOCK:
                    set_sprite_prop(i, 7);
                    current->dmg = 1;
                    break;
            }
            // Rotate sprite based on the direction. 
            switch(dir) {
                case UP:
                    set_sprite_tile(i, 0x11);
                    set_sprite_prop(i, get_sprite_prop(i) & ~S_FLIPY);
                    break;
                case DOWN:
                    set_sprite_tile(i, 0x11);
                    set_sprite_prop(i, get_sprite_prop(i) | S_FLIPY);
                    break;
                case LEFT:
                    set_sprite_tile(i, 0x10);
                    set_sprite_prop(i, get_sprite_prop(i) & ~S_FLIPX);
                    break;
                case RIGHT:
                    set_sprite_tile(i, 0x10);
                    set_sprite_prop(i, get_sprite_prop(i) | S_FLIPX);
                    break;
            }
            break;
        }
}

/*  Updates the projectiles position and detects projectile collision. 
    Then updates the relevant sprites. */
void updateProjs(Enemy * enemies) {
    const int speed = 3;
    int i = 4;
    for (Projectile * current = projectiles; current != projectiles + 4; current++, i++) {
        // If current is invalid, it's the end of the list. 
        // Don't let projectiles leave the screen.
        if (current->valid) {
            /*  Move valid projectiles. */
            switch (current->dir) {
                case UP:
                    if (sprite_tile_collision(current->x, current->y - speed, current->dir)) 
                        current->y -= speed;
                    else current->valid = false;
                    break;
                case DOWN:
                    if (sprite_tile_collision(current->x, current->y + speed, current->dir)) 
                        current->y += speed;
                    else current->valid = false;
                    break;
                case LEFT:
                    if (sprite_tile_collision(current->x - speed, current->y, current->dir)) 
                        current->x -= speed;
                    else current->valid = false;
                    break;
                case RIGHT:
                    if (sprite_tile_collision(current->x + speed, current->y, current->dir)) 
                        current->x += speed;
                    else current->valid = false;
                    break;
            }
            move_sprite(i, current->x - camera.x_pos, current->y - camera.y_pos);
            /*  Projectile enemy collision. */
            for (Enemy * currentEnemy = enemies; currentEnemy != enemies + 8; currentEnemy++)
                if (currentEnemy->health > 0 && sprite_sprite_collision(current->x, current->y, 8, 4, currentEnemy->x, currentEnemy->y, 8, 8)) {
                    currentEnemy->health -= current->dmg;
                    current->valid = false;
                    // If the projectile hits an enemy, we don't 
                    // need to keep looping through the list of enemies. 
                    break;
                }
        } else hide_sprite(i);
    }
}