#pragma once 

#include "direction.h"

struct TestEnemy {
    uint8_t x;
    uint8_t y; 
    Direction dir;
    uint8_t health;
} testEnemy;

void initTestEnemy();