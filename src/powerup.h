#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "player.h"
#include "dmgtype.h"

// Power-ups are similar to enemies, except 
// they help the player on collision, not hurt them. 
// They have a position on screen, and a type. 
typedef struct {
    uint16_t x_pos, y_pos;
    bool valid;
    PWR_TYPE type;
} PowerUP;

/*  Spawns a power-up at position x and y. 
    @param  x The x-coord of the power-up
    @param  y The y-coord of the power-up
    @param  type The type of the power-up
    @param  powerups The array of power-ups currently
            in play
*/
void spawn_powerup(uint16_t, uint16_t, PWR_TYPE, PowerUP *);
/*  When the player collides with a power-up, 
    set the player's time and damage type. 
    @param  powerups The array of power-ups currently
            in play.
    @param  player Pointer to the player who collected 
            the power-up.
*/
void update_powerups(PowerUP *, Player *);
// Hide the sprites allocated to power-ups. 
void hide_powerups();
