#include "rooms.h"
#include <stdlib.h>

#include "../res/bottomleft.h"
#include "../res/bottomright.h"
#include "../res/topleft.h"
#include "../res/topright.h"

#define LEN(arr) ((int) (sizeof (arr) / sizeof (arr)[0]))

Room * rooms[4][4];

/*  Spawns a room at [i][j]. 
    Uses malloc. 
*/
void spawn_room(uint8_t i, uint8_t j) {
    if (i > LEN(rooms) || j > LEN(*rooms))
        return;

    rooms[i][j] = (Room *)calloc(1, sizeof(Room));
}

/*  Loops through and frees allocated rooms. 
    Uses free. 
*/
void free_rooms() {
    for (int i = 0; i < LEN(rooms); ++i)
        for (int j = 0; i < LEN(*rooms); ++i)
            free(rooms[i][j]);
}

/*  TODO: Acturally generate rooms. Just sets things up for test tilemap. */
void generate_rooms(Player * player) {
    // Allocate the data for the rooms.
    spawn_room(0, 0);
    spawn_room(0, 1);
    spawn_room(1, 0);
    spawn_room(1, 1);
    // Set the tileset for each room. 
    rooms[0][0]->tilemap = topright_map;
    rooms[0][1]->tilemap = bottomright_map;
    rooms[1][0]->tilemap = topleft_map;
    rooms[1][1]->tilemap = bottomleft_map;

    // Starting room is [0][0]
    player->room_i = 0;
    player->room_j = 0;
    // Set the player position in the middle of the room. 
    player->x_pos = (20*8*player->room_i) + 80 + 8;
    player->y_pos = (16*8*player->room_j) + 64 + 16; 
    player->dir = RIGHT;
}
