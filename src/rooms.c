#include "rooms.h"
#include <stdlib.h>

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
void free_rooms() {}

/*  TODO: Acturally generate rooms. Just sets things up for test tilemap. */
void generate_rooms(Player * player) {
    spawn_room(0, 0);
    spawn_room(0, 1);
    spawn_room(1, 0);
    spawn_room(1, 1);

    // Starting room is [0][0]
    player->room_i = 0;
    player->room_j = 0;
}
