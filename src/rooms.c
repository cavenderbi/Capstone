#include "rooms.h"

struct _room rooms[9][9];

/*  TODO: Acturally generate rooms. Just sets things up for test tilemap. */
void generate_rooms(Player * player) {
    rooms[1][1].tilemap = down_right_tileset;
    rooms[1][2].tilemap = down_left_tileset;
    rooms[2][1].tilemap = up_right_tilemap;
    rooms[2][2].tilemap = up_left_tilemap;

    // Starting room is [0][0]
    player->room_i = 1;
    player->room_j = 1;
}

/*  TODO: Remove this. It's a good example of how to loop throught a 2D-array 
    with pointer for-loops. */
void print_rooms() {
    for (struct _room (*p1)[9] = rooms; p1 != rooms + 9; ++p1) {
        for (struct _room *p2 = *p1; p2 != *p1 + 9; ++p2)
            if (p2->tilemap != 0)
                printf("R");
            else 
                printf("*");
        printf("\n");
    }
}

