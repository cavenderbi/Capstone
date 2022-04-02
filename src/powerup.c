#include "powerup.h"
#include "collision.h"
#include "hud.h"

#include <gb/cgb.h>

void spawn_powerup(uint16_t x, uint16_t y, PWR_TYPE type, PowerUP * powerups) {
    for (PowerUP * current = powerups; current != powerups + 8; current++)
        if (!current->valid) {
            current->x_pos = x;
            current->y_pos = y;
            current->type = type;
            current->valid = true;
            break;
        }
}

void update_powerups(PowerUP * powerups, Player * player) {
    int i = 0x14;
    for (PowerUP * current = powerups; current != powerups + 8; current++, i++) {
        if (current->valid) {
            // Check collision. 💥
            if (sprite_sprite_collision(player->x_pos - 8, player->y_pos - 8, 16, 16, current->x_pos, current->y_pos, 8, 8)) {
                draw_HUD_element(player->element = current->type);
                draw_HUD_usage((player->usage = 14 * NUM_SHOTS_PER_BAR) / NUM_SHOTS_PER_BAR);
                current->valid = false;
            }
            // Draw sprite. ✍️
            set_sprite_tile(i, 21);
            switch (current->type) {
                case PWR_FIRE:
                    set_sprite_prop(i, get_sprite_prop(i) | 0b101);
                    break;
                case PWR_FROST:
                    set_sprite_prop(i, get_sprite_prop(i) | 0b110);
                    break;
                case PWR_SHOCK:
                    set_sprite_prop(i, get_sprite_prop(i) | 0b111);
                    break;
            }
            move_sprite(i, current->x_pos, current->y_pos);
        }
        // Hide sprite. 🙈
        else hide_sprite(i);
    }
}

void hide_powerups() {
    for (int i = 0x14; i <= 0x14 + 8; ++i)
        hide_sprite(i);
}