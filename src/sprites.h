#pragma once

// Include the sprites defined in their respective C folders. 
// Thanks to png2assets for letting me not have to write 8x8 sprites in hex by hand.

// Player sprites. 
#include "../res/wizard_walk_up.h"
#include "../res/wizard_walk_down.h"
#include "../res/wizard_walk_side.h" 
#include "../res/wizard_palettes.h" 
// Player projectile.
#include "../res/player_basic_proj.h"
// TODO: make a better power-up sprite. 
#include "../res/powerorb.h"
// TODO: Replace with a more permenant sprite.
// Test Enemy Sprite.
#include "../res/knight_walk_down.h"
#include "../res/knight_walk_side.h"
#include "../res/knight_walk_up.h"
// TODO: Camera should be able to scroll from one tilemap to another,
//       as opposed to through one big tilemap like this one.
// Test tilemap.
#include "../res/test_fourrooms.h"

#include "../res/fire.h"
#include "../res/frost.h"
#include "../res/shock.h"