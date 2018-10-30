#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void Initboard(char board[ROWS][COLS], int row, int col, char ret)//初始化数组
{
	int i = 0, j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			board[i][j] = ret;
		}
	}
}
void Displayboard(char board[ROWS][COLS], int row, int col)//打印雷盘界面
{
	int i = 0, j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void Bombboard(char board[ROWS][COLS], int row, int col)//设置雷
{
	int count = COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
void first_step(char board[ROWS][COLS], int x, int y, int row, int col)//第一步不睬雷
{
	if (board[x][y] == '1')
	{
		board[x][y] = '0';
		int count = 1;
		while (count)
		{
			int x1 = rand() % row + 1;
			int y1 = rand() % col + 1;
			if (board[x][y] == '0'&&x1 != x&&y1 != y)
			{
				board[x1][y1] = '1';
				count--;
			}
		}
	}
	return board[x][y];
}
int  Countbomb(char board[ROWS][COLS], int x, int y)//统计周围雷数
{
	return board[x][y] = board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1] +
		board[x][y - 1] + board[x][y + 1] +
		board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1] - 8 * '0';
}
