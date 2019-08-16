//
// Created by qft77 on 21-04-2019.
//

#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <time.h>

struct board;

/* board_create() returns a pointer to a newly created board(mapped 1 to 9) on the heap
 * effects: allocates heap memory, caller must free
 * time: O(1) */
struct board *board_create(void);

/* board_destroy(board) frees memory allocated by the board
 * requires: board is a valid pointer
 * effects: board is freed
 * time: O(1) */
void board_destroy(struct board *board);

/* is_in_board(pos) returns true if pos is a position on the board
 * time: O(1) */
bool is_in_board(int pos);

/* item_at(board, pos) returns the int value of the piece on the board at pos
 * requires: board is a valid pointer
 *           is_in_board(pos) is true
 * time: O(1) */
int item_at(struct board *board, int pos);

/* player_turn(board) returns an int to determine whose turn it is in the game
 * requires: board is a valid pointer
 * time: O(1); */
int player_turn(struct board *board);

/* board_print(board) prints the current board
 * requires: board is a valid pointer
 * effects: produces output
 * time: O(1) */
void board_print(struct board *board);

/* place_item(board, pos) places an item (X = -1, O = 1, _ = 0) on the board
 * at pos(square number)
 * requires: board is a valid pointer
 *           pos > 0 and pos < 10
 * time: O(1) */
void place_item(struct board *board, int pos, int item);

/* has_won(board) returns 1 if the game is complete, and 0 otherwise
 * requires: board is a valid pointer
 * time: O(1) */
int has_won(struct board *board);

#endif // BOARD_H
