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
    if (i > LEN(rooms) || j > LEN(*rooms) || rooms[i][j] != NULL)
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
/*  TODO: Actually generate rooms. Just sets things up for test tilemap. */
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
                    spawn_room(row--, col);
                break;
            case DOWN:
                if (row + 1 > 0 && row + 1 < ROWS)
                    spawn_room(row++, col);
                break;
            case LEFT:
                if (col - 1 > 0 && col - 1 < COLS)
                    spawn_room(row, col--);
                break;
            case RIGHT:
                if (col + 1 > 0 && col + 1 < COLS)
                    spawn_room(row, col++);
                break;
        }
    }

    // TODO: Set correct tilemaps. 
    uint8_t flags;
    for (uint8_t a = 0; a < ROWS; ++a) {
        for (uint8_t b = 0; b < COLS; ++b) {
            flags = 0;
            // Set the flags for UP, DOWN, LEFT, and RIGHT.
            if (a - 1 < ROWS && rooms[b][a - 1] != NULL) flags &= 0x08; // UP
            if (a + 1 < ROWS && rooms[b][a + 1] != NULL) flags &= 0x04; // DOWN
            if (b - 1 < COLS && rooms[b - 1][a] != NULL) flags &= 0x02; // LEFT
            if (b + 1 < COLS && rooms[b + 1][a] != NULL) flags &= 0x01; // RIGHT

            switch (flags) {
                case 0x0F: rooms[b][a]->tilemap = middle_map;               break; // UP, DOWN, LEFT, and RIGHT // 1111
                case 0x0E: rooms[b][a]->tilemap = middleright_map;          break; // UP, DOWN, and LEFT        // 1110
                case 0x0D: rooms[b][a]->tilemap = middleleft_map;           break; // UP, DOWN, and RIGHT       // 1101
                case 0x0C: rooms[b][a]->tilemap = straightvertical_map;     break; // UP and DOWN               // 1100
                case 0x0B: rooms[b][a]->tilemap = middlebottom_map;         break; // UP, LEFT, and RIGHT       // 1011
                case 0x0A: rooms[b][a]->tilemap = bottomleft_map;           break; // UP and LEFT               // 1010
                case 0x09: rooms[b][a]->tilemap = bottomright_map;          break; // UP and RIGHT              // 1001
                case 0x08: rooms[b][a]->tilemap = singleup_map;             break; // UP only                   // 1000
                case 0x07: rooms[b][a]->tilemap = middletop_map;            break; // DOWN, LEFT, and RIGHT     // 0111
                case 0x06: rooms[b][a]->tilemap = topleft_map;              break; // DOWN and LEFT             // 0110
                case 0x05: rooms[b][a]->tilemap = topright_map;             break; // DOWN and RIGHT            // 0101
                case 0x04: rooms[b][a]->tilemap = singledown_map;           break; // DOWN only                 // 0100
                case 0x03: rooms[b][a]->tilemap = straighthorizontal_map;   break; // LEFT and RIGHT            // 0011
                case 0x02: rooms[b][a]->tilemap = singleleft_map;           break; // LEFT only                 // 0010
                case 0x01: rooms[b][a]->tilemap = singleright_map;          break; // RIGHT only                // 0001
            }
        }
    }
    // TODO: Remove layout print once the above is implemented.
    font_init();
    for (int a = 0; a < ROWS; ++a) {
        for (int b = 0; b < COLS; ++b)
            if (b == player->room_i && a == player->room_j)
                putchar('S');
            else putchar(rooms[b][a] != NULL ? '1' : '0');
        if (a < ROWS - 1) putchar('\n');
    }
    waitpad(J_START);
}