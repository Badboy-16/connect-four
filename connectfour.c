#include <stdio.h>

#define EMPTY 0
#define PLAYERONE 1
#define PLAYERTWO 2
#define COL 7
#define ROW 6
#define GRID COL*ROW
#define WIN 4

int main() {
    int board[GRID]; /* board indices start from 0 at bottom left */
    for (int idx = 0; idx < GRID; idx++) {
        board[idx] == EMPTY;
    }
}

int printboard(int board[]) {
    for (int row = ROW - 1; row >= 0; row--) {
        for (int col = 0; col <= COL - 1; col++) {
            printf("%d ", board[getidx(row, col)]);
        }
        printf("\n");
    }
    printf("\n");
}

/* get column index from 0 (left) to 6 (right) */
int getcol(int idx) {
    return idx % COL;
}

/* get row index from 0 (bottom) to 5 (top) */
int getrow(int idx) {
    return idx / COL;
}

int getidx(int row, int col) {
    return row * COL + col;
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
    /* check horizontal connection */
    int connection[WIN];
    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col <= COL - WIN; col++) {
            for (int space = 0; space < WIN; space++) {
                connection[space] = board[getidx(row, col+space)];
            }
            if (winplayer(connection) != 0) {
                return winplayer(connection);
            }
        }
    }
    for (int col = 0; col < COL; col++) {
        for (int row = 0; row < ROW - WIN; row++) {
            for (int space = 0; space < WIN; space++) {
                connection[space] = board[getidx(row+space, col)];
            }
            if (winplayer(connection) != 0) {
                return winplayer(connection);
            }
        }
    }
    for (int col = 0; col < COL - WIN; col++) {
        for (int row = 0; row < ROW - WIN; row++) {
            for (int space = 0; space < WIN; space++) {
                connection[space] = board[getidx(row+space, col+space)];
            }
            if (winplayer(connection) != 0) {
                return winplayer(connection);
            }
        }
    }
    for (int col = 0; col < COL - WIN; col++) {
        for (int row = ROW - 1; row > ROW - WIN; row--) {
            for (int space = 0; space < WIN; space++) {
                connection[space] = board[getidx(row-space, col+space)];
            }
            if (winplayer(connection) != 0) {
                return winplayer(connection);
            }
        }
    }
}

int winplayer(int connection[]) {
    if (sizeof(connection) / sizeof(int) == 1) {
        return connection[0];
    }
    for (int idx = 0; idx < sizeof(connection) / sizeof(int) - 1; idx++) {
        if (connection[idx] != connection[idx+1]) {
            return 0;
        }
    }
    return connection[0];
}
