# ifndef _GAME_H__
# define _GAME_H__

#include<stdio.h>
#include<time.h>
#include<stdlib.h>


#define EASY_COUNT 10

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

void init_board(char board[ROWS][COLS], int rows, int cols, char set);
void display_board(char board[ROWS][COLS], int row, int col);
void set_board(char mine[ROWS][COLS], int row, int col);



void find_board(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

# endif //__GAME_H_
