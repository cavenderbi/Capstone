#include "collision.h"

/*  Function used for checking collision between two sprites. 
    Common uses for this function would be checking if a projectile collides 
    with an enemy or if an enemy collides with a player.
    @param x_1 The x-coordinate of the first sprite.
    @param y_1 The y-coordinate of the first sprite.
    @param width_1 The width of the first sprite.
    @param height_1 The height of the first sprite.
    @param x_2 The x-coordinate of the second sprite.
    @param y_2 The y-coordinate of the second sprite.
    @param width_2 The width of the second sprite.
    @param height_2 The height of the second sprite.
    @returns Returns true if the two sprites overlap, otherwise returns false. */
inline bool sprite_sprite_collision(uint8_t x_1, uint8_t y_1, uint8_t width_1, uint8_t height_1, uint8_t x_2, uint8_t y_2, uint8_t width_2, uint8_t height_2) {
    return (x_1 < (x_2 + width_2) && (x_1 + width_1) > x_2 && y_1 < (y_2 + height_2) && (y_1 + height_1) > y_2);
}


/*  Function used for checking collision between a sprite and a background tile. 
    Common uses for this function would be checking if a player or enemy have walked into a wall. 
    @param x The x-coordinate of the sprite.
    @param y The y-coordinate of the sprite.
    @param width The width of the sprite. 
    @param height The height of the sprite.
    @returns Returns false if the sprite overlaps with a collidable background tile. */
inline bool sprite_tile_collision(uint8_t x, uint8_t y, Direction dir) {
    if (dir == DOWN || dir == RIGHT) {
        x += 7;
        y += 7;
    }
    uint8_t tile =  get_bkg_tile_xy((x - 8) / 8, ((y - 16) / 8));
    return tile == 0x14 || tile == 0;
}