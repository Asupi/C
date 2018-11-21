#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
void menu()
{
	printf("*******************************\n");
	printf("********    0.退出    *********\n");
	printf("********    1.玩游戏  *********\n");
}
void game()
{
	char board[ROWS][COLS] = { 0 };
	char ret = 0;
	init_board(board, ROWS, COLS);
	display_board(board, ROWS, COLS);
	while (1)
	{
		player_move(board, ROWS, COLS);
		ret = IsWin(board, ROWS, COLS);
		if (ret != ' ')
		break;
		display_board(board, ROWS, COLS);
		computer_move(board, ROWS, COLS);
		ret = IsWin(board, ROWS, COLS);
		if (ret != ' ')
		break;
		display_board(board, ROWS, COLS);
	}
	if (ret=='X')
	  printf("玩家赢\n");
	else if (ret=='0')
	  printf("电脑赢\n");
	else if (ret == "Q")
	  printf("平局\n");
	display_board(board, ROWS, COLS);
}


int main()
{
	int input = 0;
	srand((int)time(NULL));
	do
	{
		menu();
		printf("请选择>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
				break;
		case 1:
				game();
				break;
		default:
				printf("输入错误，请重新输入\n");
				break;
		}
	} while (input);
	return 0;
}