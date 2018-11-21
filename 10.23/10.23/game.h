#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _GAME_H_
#define _GAME_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define ROWS 3
#define COLS 3
void menu();
void game();
void init_board(char board[ROWS][COLS], int row, int col);
void display_board(char board[ROWS][COLS], int row, int col);
void player_move(char board[ROWS][COLS], int row, int col);
void computer_move(char board[ROWS][COLS], int row, int col);
char IsWin(char board[ROWS][COLS], int row, int col);
char IsFull(char board[ROWS][COLS], int row, int col);
#endif//_GANE_H_

