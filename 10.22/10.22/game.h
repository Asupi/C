#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __GAME_H__
#define __GAME_H__
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define COUNT 10
void Initboard(char board[ROWS][COLS], int row, int col, char ret);
void Displayboard(char board[ROWS][COLS], int row, int col);
void Bombboard(char board[ROWS][COLS], int row, int col);
int  Countbomb(char show[ROWS][COLS], int x, int y);
char first_step(char board[ROWS][COLS], int x, int y, int row, int col);
#endif
