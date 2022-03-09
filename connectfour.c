#include <stdio.h>

#define EMPTY 0
#define PLAYERONE 1
#define PLAYERTWO 2
#define COL 7
#define ROW 6
#define GRID COL*ROW

int main() {
    int board[GRID]; /* board indices start from 0 at bottom left */
    for (int idx = 0; idx < GRID; idx++) {
        board[idx] == EMPTY;
    }
}

int printboard(int board[]) {
}

/* get column index from 0 (left) to 6 (right) */
int getcol(int idx) {
    return idx % COL;
}

/* get row index from 0 (bottom) to 5 (top) */
int getrow(int idx) {
    return idx / COL;
}

int makemove(int col, int player, int board[]) {
    for (int idx = col; idx < GRID; idx += ROW) {
        if (board[idx] == EMPTY) {
            board[idx] = player;
            return 0;
        }
    }
    return -1;
}

int checkwin(int board[]) {
}
