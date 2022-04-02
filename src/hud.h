#pragma once

#include <stdint.h>
#include "dmgtype.h"

#define NUM_SHOTS_PER_BAR 3

void init_HUD();
void draw_HUD_health(uint8_t);
void draw_HUD_element(PWR_TYPE);
void draw_HUD_usage(uint8_t);