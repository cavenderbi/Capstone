#include "rooms.h"
#include <stdlib.h>
#include <rand.h>
#include <gbdk/font.h>

#include "../res/bottomleft.h"
#include "../res/bottomright.h"
#include "../res/topleft.h"
#include "../res/topright.h"
#include "../res/middle.h"
#include "../res/middletop.h"
#include "../res/middlebottom.h"
#include "../res/middleleft.h"
#include "../res/middleright.h"
#include "../res/singleup.h"
#include "../res/singledown.h"
#include "../res/singleleft.h"
#include "../res/singleright.h"
#include "../res/straighthorizontal.h"
#include "../res/straightvertical.h"

#define LEN(arr) ((int) (sizeof (arr) / sizeof (arr)[0]))

Room * rooms[ROWS][COLS];

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

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
/*  TODO: Acturally generate rooms. Just sets things up for test tilemap. */
void generate_rooms(Player * player) {
    uint8_t row = player->room_i = rand() % ROWS;
    uint8_t col = player->room_j = rand() % COLS;
    uint8_t itr = ROWS * COLS * 2 / 3;
    // Set the player position in the middle of the room. 
    player->x_pos = (20*8*player->room_i) + (80 + 8);
    player->y_pos = (16*8*player->room_j) + (64 + 16);
    
    // Snake around and spawn rooms.
    uint8_t move;
    while (itr--) {
        move = rand() % 4;
        switch (move) {
            case UP:
                if (row - 1 > 0 && row - 1 < ROWS)
                    spawn_room(row, col);
                    rooms[row--][col]->tilemap = middle_map;
                break;
            case DOWN:
                if (row + 1 > 0 && row + 1 < ROWS)
                    spawn_room(row, col);
                    rooms[row++][col]->tilemap = middle_map;
                break;
            case LEFT:
                if (col - 1 > 0 && col - 1 < COLS)
                    spawn_room(row, col);
                    rooms[row][col--]->tilemap = middle_map;
                break;
            case RIGHT:
                if (col + 1 > 0 && col + 1 < COLS)
                    spawn_room(row, col);
                    rooms[row][col++]->tilemap = middle_map;
                break;
        }
    }

     
    font_init();
    for (int a = 0; a < ROWS; ++a) {
        for (int b = 0; b < COLS; ++b)
            if (a == player->room_i && b == player->room_j)
                putchar('S');
            else putchar(rooms[a][b] != NULL ? '1' : '0');
        if (a < ROWS - 1) putchar('\n');
    }
    waitpad(J_START);
}