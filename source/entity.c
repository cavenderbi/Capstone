#include "entity.h"

void spawn_entity(Entity * this, uint8_t health, uint16_t x_pos, uint16_t y_pos, Direction dir) {
    this->health = health;
    this->x_pos = x_pos;
    this->y_pos = y_pos;
    this->dir = dir;
}

void move_entity(Entity * this, Direction dir, uint8_t distance) {
    // TODO: move the entity independent of the camera movement. 
}

