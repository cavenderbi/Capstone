#pragma once

#include <stdint.h>
#include "dmgtype.h"

void init_HUD();
void draw_HUD_health(uint8_t);
void draw_HUD_element(PWR_TYPE);
void draw_HUD_time(uint16_t);