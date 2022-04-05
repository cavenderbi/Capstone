#include <gb/gb.h>
#include <stdio.h>
#include <stdlib.h>
#include <rand.h>
#include <time.h>
#include <stdbool.h>

#define ROW 9
#define COL 10

void main() {
    char grid[ROW][COL];
    int ro, co;
    int i = 0;
    begin:  

    // Fill with '.' characters. 
    for (int r = 0; r < ROW; ++r)
        for (int c = 0; c < COL; ++c)
            grid[r][c] = '.';
    /* We use the DIV register to get a random initial seed */
    puts("Getting seed");
    puts("Push any key (1)");
    waitpad(0xFF);
    waitpadup();
    uint16_t seed = DIV_REG;
    puts("Push any key (2)");
    waitpad(0xFF);
    waitpadup();
    seed |= (uint16_t)DIV_REG << 8;

    /* initarand() calls initrand() */
    initrand(seed);

    // Pick starting point. 
    /* ro = rand() % ROW;
    co = rand() % COL; */
    ro = ROW / 2;
    co = COL / 2;
    grid[ro][co];

    /*  Now, there's four possible moves for the walk to take. 
     *      move    direction.
     *      0       row++
     *      1       column++
     *      2       row--
     *      3       column-- 
     */
    int n = 0;
    int row = ro;
    int col = co;
    bool blocked = false;
    while (n++ < 26) {
        int move = rand() % 4;
        switch (move) {
            case 0:
                if (ro + 1 > 0 && ro + 1 < ROW)
                    grid[++ro][co] = 'X';
                break;
            case 1: 
                if (co + 1 > 0 && co + 1 < ROW)
                    grid[ro][++co] = 'X';
                break;
            case 2:
                if (ro - 1 > 0 && ro - 1 < ROW)
                    grid[--ro][co] = 'X';
                break;
            case 3: 
                if (co - 1 > 0 && co - 1 < ROW)
                    grid[ro][--co] = 'X';
                break;
        }
    }
    // Set the starting tile to 'S'.
    grid[row][col] = 'S';
    // Set the boss room to 'B'.
    grid[ro][co] = 'B';
    // Print the walk. 
    for (int a = 0; a < ROW; ++a) {
        for (int b = 0; b < COL; ++b)
            printf("%c ", grid[a][b]);
        if (a < ROW - 1) printf("\n");
    }
    waitpad(J_START);
    waitpadup();
    fill_rect(0, 0, 20, 18, 0);
    goto begin;
}