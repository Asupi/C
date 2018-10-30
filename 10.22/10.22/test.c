#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

#include "game.h"
void game()
{
	int x = 0, y = 0, i = 0;
	char board[ROWS][COLS] = { '0' };
	char show[ROWS][COLS] = { '0' };
	Initboard(board, ROW, COL, '0');
	Initboard(show, ROW, COL, '*');
	Bombboard(board, ROW, COL);
	//Displayboard(board, ROW, COL);//显示雷的分布点
	Displayboard(show, ROW, COL);
	while (i<ROW*COL - COUNT)
	{
		int  ret = 0;
		printf("请选择:\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= ROW&&y >= 1 && y <= COL)
		{
			if (board[x][y] == '1'&&i == 0)
			{
				board[x][y] = first_step(board, x, y, ROW, COL);
				Displayboard(board, ROW, COL);
				ret = Countbomb(board, x, y);
				show[x][y] = ret + '0';
				Displayboard(show, ROW, COL);
				i++;
			}
			else
			{
				if (board[x][y] == '0')
				{
					ret = Countbomb(board, x, y);
					show[x][y] = ret + '0';
					if (ret == 0)
					{
						show[x - 1][y - 1] = ' ';
						show[x - 1][y] = ' ';
						show[x - 1][y + 1] = ' ';
						show[x][y - 1] = ' ';
						show[x][y + 1] = ' ';
						show[x + 1][y - 1] = ' ';
						show[x + 1][y] = ' ';
						show[x + 1][y + 1] = ' ';
					}
					Displayboard(show, ROW, COL);
					i = i + 8;
				}
				else
				{
					printf("很遗憾，你被炸死了\n");
					break;
				}
			}
		}
		else
		{
			printf("输入坐标有误\n");
		}
	}
	if (i == ROW*COL - COUNT)
		printf("恭喜你，排雷成功!\n");
}
void menu()
{
	printf("*********************\n");
	printf("***1.开始   0.退出***\n");
	printf("*********************\n");
}
int main()
{
void menu();
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		}
	} while (1);
	system("pause");
	return 0;
}
