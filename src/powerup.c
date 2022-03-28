#include "powerup.h"
#include "collision.h"
#include "hud.h"

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
        if (sprite_sprite_collision(player->x_pos - 8, player->y_pos - 8, 16, 16, current->x_pos, current->y_pos, 8, 8)) {
            player->element = current->type;
            draw_HUD_element(player->element);
            current->valid = false;
        }
        if (current->valid) {
            set_sprite_tile(i, 0x3);    // Draw sprite.
            move_sprite(i, current->x_pos, current->y_pos);
        } else hide_sprite(i);          // Hide sprite. 
    }
}

void hide_powerups() {
    for (int i = 0x14; i <= 0x14 + 8; ++i)
        hide_sprite(i);
}