#pragma once 

#include "direction.h"

struct TestEnemy {
    uint8_t x;
    uint8_t y; 
    Direction dir;
    uint8_t health;
} testEnemy;

typedef struct {
    uint8_t x;
    uint8_t y;
    uint8_t health;
    Direction dir;
} Enemy;
struct {
    Enemy array[16];
    uint8_t count;
} enemies;

void initTestEnemy();

void initEnemies();
void spawnEnemy(uint8_t, uint8_t, Direction, uint8_t);
void updateEnemies();