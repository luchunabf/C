#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _GAME_H__
#define _GAME_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


#define ROW 3
#define COL 3
void init_board(char board[ROW][COL], int row, int col);
void display_board(char board[ROW][COL], int row, int col);
void player_board(char board[ROW][COL], int row, int col);
void comp_board(char board[ROW][COL], int row, int col);

//void srand(unsigned seed);
//int rand(void);


int winner_board(char board[ROW][COL], int row, int col);
int is_full(char board[ROW][COL], int row, int col);





#endif // !_GAME_H__
