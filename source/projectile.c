#include "projectile.h"

/*  Spawns a new projectile at the given x and y coordinates, facing the given direction. 
    @param x The starting x-coordinate of the projectile. 
    @param y The starting y-coordinate of the projectile. 
    @param dir The direction the projectile is facing. */
void shoot(uint8_t x, uint8_t y, Direction dir) {
    /*  Create the new projectile struct. */
    Projectile * new_proj = (Projectile *) malloc(sizeof(Projectile));
    new_proj->dir = dir;
    new_proj->x = x;
    new_proj->y = y;
    new_proj->alive = true;
    /*  Insert the new projectile into the list. */
    insert(proj_head, new_proj);
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
        switch (((Projectile *)current->data)->dir) {
            case UP:
                break;
            case DOWN:
                break;
            case LEFT:
                break;
            case RIGHT:
                break;
        }
        /*  Update current so there's not an infinite loop. */
        current = current->next;
    }
}