#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
void menu()
{
	printf("*******************************\n");
	printf("********    0.�˳�    *********\n");
	printf("********    1.����Ϸ  *********\n");
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
	  printf("���Ӯ\n");
	else if (ret=='0')
	  printf("����Ӯ\n");
	else if (ret == "Q")
	  printf("ƽ��\n");
	display_board(board, ROWS, COLS);
}


int main()
{
	int input = 0;
	srand((int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
				break;
		case 1:
				game();
				break;
		default:
				printf("�����������������\n");
				break;
		}
	} while (input);
	return 0;
}