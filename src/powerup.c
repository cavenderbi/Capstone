#pragma bank 1

#include "powerup.h"
#include "collision.h"
#include "hud.h"

#include <gb/cgb.h>

void spawn_powerup(uint16_t x, uint16_t y, PWR_TYPE type, PowerUP * powerups) NONBANKED {
    int i = 0x14;
    for (PowerUP * current = powerups; current != powerups + 8; current++, i++)
        if (!current->valid) {
            current->x_pos = x;
            current->y_pos = y;
            current->type = type;
            current->valid = true;
            set_sprite_tile(i, 0x26);
            switch (type) {
                case PWR_FIRE:
                    set_sprite_prop(i, 5);
                    break;
                case PWR_FROST:
                    set_sprite_prop(i, 6);
                    break;
                case PWR_SHOCK:
                    set_sprite_prop(i, 7);
                    break;
            }
            break;
        }
}

void update_powerups(PowerUP * powerups, Player * player) NONBANKED {
    int i = 0x14;
    for (PowerUP * current = powerups; current != powerups + 8; current++, i++) {
        if (current->valid) {
            // Check collision. 💥
            if (sprite_sprite_collision(player->x_pos - 8, player->y_pos - 8, 16, 16, current->x_pos, current->y_pos, 8, 8)) {
                draw_HUD_element(player->element = current->type);
                draw_HUD_usage((player->usage = 14 * NUM_SHOTS_PER_BAR) / NUM_SHOTS_PER_BAR);
                current->valid = false;
                // Edit the player's color palette based on the current damage type.
                switch (player->element) {
                    case PWR_NONE:
                        set_sprite_palette_entry(0, 2, RGB8(120, 120, 120));
                        break;
                    case PWR_FIRE: 
                        set_sprite_palette_entry(0, 2, RGBHTML(0xe12d2d));
                        break;
                    case PWR_FROST: 
                        set_sprite_palette_entry(0, 2, RGBHTML(0x76aef4));
                        break;
                    case PWR_SHOCK: 
                        set_sprite_palette_entry(0, 2, RGBHTML(0xe4e325));
                        break;
                }
            }
            // Draw sprite. ✍️
            move_sprite(i, current->x_pos, current->y_pos);
        }
        // Hide sprite. 🙈
        else hide_sprite(i);
    }
}