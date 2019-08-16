#include "board.h"

struct board {
    int cells[9];
    int turn;
};

struct board *board_create() {
    struct board *new = malloc(sizeof(struct board));
    memset(new->cells, 0, 9 * sizeof(int));
    srand(time(NULL));
    new->turn = rand() % 2;
    return new;
}

void board_destroy(struct board *board) {
    assert(board);
    free(board);
}

bool is_in_board(int pos) {
    return (pos > 0 && pos < 10);
}

int item_at(struct board *board, int pos) {
    assert(board);
    assert(is_in_board(pos));
    return board->cells[pos-1];
}

int player_turn(struct board *board) {
    assert(board);
    return board->turn;
}

void board_print(struct board *board) {
    assert(board);
    printf("\n");
    for (int i = 0; i < 9; i++) {
        if (!board->cells[i]) {
            printf("_   ");
        } else if (board->cells[i] == 1) {
            printf("O   ");
        } else printf("X   ");
        if(i && (i+1) % 3 == 0) {
            printf("\n");
            for(int k = 1; k <= 3; k++) {
                printf("%d   ", k + (i/3 * 3));
            }
            printf("\n\n");
        }
    }
}

void place_item(struct board *board, int pos, int item) {
    assert(board);
    assert(pos > 0 && pos < 10);
    assert(item < 2 && item > -2);
    board->cells[pos-1] = item;
}

int has_won(struct board *board) {
    int win_cases[8][3] = {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}};
    for(int i = 0; i < 8; i++) {
        if(board->cells[win_cases[i][0]] &&
           board->cells[win_cases[i][0]] == board->cells[win_cases[i][1]] &&
           board->cells[win_cases[i][0]] == board->cells[win_cases[i][2]]) {
            return board->cells[win_cases[i][2]];
        }
    }
    return 0;
}