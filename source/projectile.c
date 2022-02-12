#include "projectile.h"

/*  Spawns a new projectile at the given x and y coordinates, facing the given direction. 
    @param x The starting x-coordinate of the projectile. 
    @param y The starting y-coordinate of the projectile. 
    @param dir The direction the projectile is facing. */
void shoot(uint8_t x, uint8_t y, Direction dir) {
    /*  Only allow 16 projectiles at a time, at least for now. */
    const int MAX_PROJS = 16;
    if (new_index <= MAX_PROJS) {
        /*  Create the new projectile struct. */
        Projectile * new_proj = (Projectile *) malloc(sizeof(Projectile));
        new_proj->dir = dir;
        new_proj->x = x;
        new_proj->y = y;
        new_proj->tile_index = 1;
        /*  Insert the new projectile into the list. */
        insert(proj_head, new_proj);
        /*  Increment new index for the next projectile. */
        new_index++;
    }
}

/*  Updates the projectiles position and detects projectile collision. */
void update_projs() {
    /*  Iterate through the list of projectiles. */
    Node * current = proj_head;
    while (current != NULL) {
        /*  Update projectile position. */

        /*  Take the void pointer of current node's data and cast it to a 
            Projectile pointer. Then get that Projectile's Direction. If a 
            non-Projectile was added to the list, this means nothing and you'll 
            be reading completely meaningless data. */
        Projectile * proj = (Projectile *) current->data;
        switch (proj->dir) {
            case UP:
                if (!sprite_tile_collision(proj->x, proj->y - 4, 3, 8))
                    proj->y -= 4;
                else {

                }
                break;
            case DOWN:
                if (!sprite_tile_collision(proj->x, proj->y + 4, 3, 8))
                    proj->y += 4;
                else {

                }
                break;
            case LEFT:
                if (!sprite_tile_collision(proj->x - 4, proj->y, 3, 8))
                    proj->x -= 4;
                else {

                }
                break;
            case RIGHT:
                if (!sprite_tile_collision(proj->x + 4, proj->y, 3, 8))
                    proj->x += 4;
                else {

                }
                break;
        }
        /*  Update current so there's not an infinite loop. */
        current = current->next;
    }
}