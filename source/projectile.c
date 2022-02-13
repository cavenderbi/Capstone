#include "projectile.h"

/*  Initialize the projectile vector. */
void initProjs() {
    VECTOR_INIT(proj_vector);
}

/*  Spawns a new projectile at the given x and y coordinates, facing the given direction. 
    @param x The starting x-coordinate of the projectile. 
    @param y The starting y-coordinate of the projectile. 
    @param dir The direction the projectile is facing. */
void shoot(uint8_t x, uint8_t y, Direction dir) {
    /*  Limit the number of projectiles, at least for now. */
    const int max_projs = 16;
    if (VECTOR_SIZE(proj_vector) < max_projs) {
        Projectile * new_proj = malloc(sizeof(Projectile));
        new_proj->x = x;
        new_proj->y = y;
        new_proj->dir = dir;
        VECTOR_ADD(proj_vector, new_proj);
    }
}

/*  Updates the projectiles position and detects projectile collision. 
    Then updates the relevant sprites. */
void updateProjs() {
    /*  Loop through all of the projectiles in the vector. */
    int i;
    for (i = 0; i < VECTOR_SIZE(proj_vector); i++) {
        Projectile * current = VECTOR_GET(proj_vector, Projectile *, i);
        switch (current->dir) {
            case UP:
                if (sprite_tile_collision(current->x, current->y - 4, current->dir)) {
                    current->y -= 4;
                    set_sprite_tile(1 + i, 9);
                    set_sprite_prop(1 + i, get_sprite_prop(1 + i) | S_FLIPY);
                    move_sprite(1 + i, current->x, current->y);
                } else VECTOR_REMOVE(proj_vector, i--);
                break;
            case DOWN:
                if (sprite_tile_collision(current->x, current->y + 4, current->dir)) {
                    current->y += 4;
                    set_sprite_tile(1 + i, 9);
                    set_sprite_prop(1 + i, get_sprite_prop(1 + i) & ~S_FLIPY);
                    move_sprite(1 + i, current->x, current->y);
                } else VECTOR_REMOVE(proj_vector, i--);
                break;
            case LEFT:
                if (sprite_tile_collision(current->x - 4, current->y, current->dir)) { 
                    current->x -= 4;
                    set_sprite_tile(1 + i, 8);
                    set_sprite_prop(1 + i, get_sprite_prop(1 + i) | S_FLIPX);
                    move_sprite(1 + i, current->x, current->y);
                } else VECTOR_REMOVE(proj_vector, i--);
                break;
            case RIGHT:
                if (sprite_tile_collision(current->x + 4, current->y, current->dir)) {
                    current->x += 4;
                    set_sprite_tile(1 + i, 8);
                    set_sprite_prop(1 + i, get_sprite_prop(1 + i) & ~S_FLIPX);
                    move_sprite(1 + i, current->x, current->y);
                } else VECTOR_REMOVE(proj_vector, i--);
        }
    }
}