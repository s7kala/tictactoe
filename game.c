#include "board.h"


void game_end(struct board *board) {
    int result = has_won(board);
    switch(result) {
        case 0:  board_print(board);
                 printf("It's a draw!");
                 break;
        case 1:  board_print(board);
                 printf("You lose :P");
                 break;
        case -1: board_print(board);
                 printf("You won?! How?!");
                 break;
    }
}

int minimax(struct board *board, int player) {
    if(has_won(board)) {
        return has_won(board) * player;
    }
    int move = -1, score = -2;
    for(int i = 1; i < 10; i++) {
        if(!item_at(board, i)) {
            place_item(board, i, player);
            int newscore = -minimax(board, -player);
            if(newscore > score) {
                score = newscore;
                move = i;
            }
            place_item(board, i, 0);
        }
    }
    if(move == -1){
        return 0;
    }
    return score;
}

void player_move(struct board *board) {
    int move = 0;
    do {
        start:
        printf("\nEnter a valid square to make your move(1-9):\n");
        scanf("%d", &move);
        if (move > 0 && move < 10 && item_at(board, move)) {
            printf("Hey! This cell is already occupied!\n");
            board_print(board);
            goto start;
        }
    } while(move > 9 || (move < 1 && item_at(board, move) == 0));
    printf("Player placed X on cell %d!\n", move);
    place_item(board, move, -1);
}

void comp_move(struct board *board) {
    int move = -1, score = -2;
    for(int i = 1; i < 10; i++) {
        if(!item_at(board, i)) {
            place_item(board, i, 1);
            int movescore = -minimax(board, -1);
            place_item(board, i, 0);
            if(movescore > score) {
                score = movescore;
                move = i;
            }
        }
    }
    printf("The computer is making a move...\n");
    place_item(board, move, 1);
}


int main(void) {
    struct board *map = board_create();
    printf("Hello! Welcome to Tic-Tac-Toe!\n");
    int player = player_turn(map);
    for(int turn = 0; turn < 9 && !has_won(map); turn++) {
        if((turn + player) % 2 == 0) {
            comp_move(map);
        } else {
            board_print(map);
            player_move(map);
        }
    }
    game_end(map);
    board_destroy(map);
    printf("Enter any key to exit, thank\n");
    scanf("%d", &player);
    return 0;
}



