#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
//��  ��
///////////////////////////////////////
//		��ͼ�ĳ��Ϳ�
#define MAPHEIGHT 25
#define MAPWIDTH 60
#define SNAKESIZE 50
///////////////////////////////////////
//		�������
int changeFlag = 0;//�߱��α��
int key = 'w';
struct food
{
	//ʳ���λ��
	int x;
	int y;
}food;
struct snake
{
	int x[SNAKESIZE]; 	//������
	int y[SNAKESIZE];
	int len;			//��ǰ����
	int speed;			//�ƶ��ٶ�
}mysnake;		//mysnake[0] ��ͷ
/////////////////////////////////////////
//		ģ�黯���
void drawMap();			//������Ϸ��ͼ
void createFood();		//����ʳ��
void keyDown();			//��������
int  snakeStaus();		//��״̬
void gotoxy(int x, int y);	//cmd�ƶ���������
int main()
{
	drawMap();
	while (1)
	{
		createFood();
		Sleep(mysnake.speed);
		keyDown();
		if (!snakeStaus())
		{
			break;
		}
	}
	printf("\nGameOver");
	system("pause");
	return 0;
}
//////////////////////////////////////
//			cmd�ƶ���������
void gotoxy(int x, int y)
{
	//��ȡcmd���ھ��
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//�������
	COORD coord;
	//���ô�������
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(handle, coord);
}
////////////////////////////////////////
//	  ������Ϸ��ͼ
void drawMap()
{
	srand((unsigned int)time(NULL));
	//ʳ��
	//1.ʳ������
	food.x = rand() % (MAPWIDTH - 4/*ʳ��ͼ��ռ��2���ַ�*/) + 2;
	food.y = rand() % (MAPHEIGHT - 2) + 1;
	//2.��ʳ��
	gotoxy(food.x, food.y);
	printf("��");
	//��
	//1.������
	mysnake.x[0] = MAPWIDTH / 2;	//��λ���м�
	mysnake.y[0] = MAPHEIGHT / 2;
	//2.����
	gotoxy(mysnake.x[0], mysnake.y[0]);
	printf("��");
	mysnake.len = 3;
	mysnake.speed = 100;
	for (int k = 1; k<mysnake.len; k++)
	{
		mysnake.x[k] = mysnake.x[k - 1] + 2;
		mysnake.y[k] = mysnake.y[k - 1];
		gotoxy(mysnake.x[k], mysnake.y[k]);
		printf("��");
	}
	//�߿�
	//1.����
	for (int i = 0; i <= MAPHEIGHT; i++)
	{
		gotoxy(0, i);
		printf("��");
		gotoxy(MAPWIDTH, i);
		printf("��");
	}
	//2.����
	for (int i = 0; i <= MAPWIDTH; i += 2)
	{
		gotoxy(i, 0);
		printf("��");
		gotoxy(i, MAPHEIGHT);
		printf("��");
	}
}
////////////////////////////////////////
//	  ����ʳ��
void createFood()			//����ʳ��
{
	//����������ʳ�ﱻ��
	if (mysnake.x[0] == food.x&&mysnake.y[0] == food.y)
	{
		//�����汾��ʳ�ﲻ����������
		srand((unsigned int)time(NULL));
		//x����Ϊż�� 	
		while (1)
		{
			int flag = 1;
			food.x = rand() % (MAPWIDTH - 4) + 2;
			food.y = rand() % (MAPHEIGHT - 2) + 1;
			for (int k = 0; k < mysnake.len; k++)
			{
				if (mysnake.x[k] == food.x&&mysnake.y[k] == food.y)
				{
					flag = 0;
					break;
				}
			}
			//ʳ������ҪΪż�����Ҳ�����������
			if (flag&&food.x % 2 == 0)
			{
				break;
			}
		}
		gotoxy(food.x, food.y);
		printf("��");
		mysnake.len++;
		changeFlag = 1;
	}
}
////////////////////////////////////////												
//	  ��������
void keyDown()
{

	//�ް���������Ҫ�ƶ�
	if (_kbhit())
	{
		fflush(stdin);
		key = _getch();
	}
	//û�仯
	if (!changeFlag)
	{
		gotoxy(mysnake.x[mysnake.len - 1], mysnake.y[mysnake.len - 1]);
		printf("  ");
	}
	//����Ľ�������:��ǰ�ƶ�
	for (int i = mysnake.len - 1; i > 0; i--)
	{
		mysnake.x[i] = mysnake.x[i - 1];
		mysnake.y[i] = mysnake.y[i - 1];
	}
	//�а�������
	switch (key)
	{
	case 'w':
	case 'W':
	case 72:
		mysnake.y[0]--;
		break;
	case 's':
	case 'S':
	case 80:
		mysnake.y[0]++;
		break;
	case 'a':
	case 'A':
	case 75:
		mysnake.x[0] -= 2;
		break;
	case 'd':
	case 'D':
	case 77:
		mysnake.x[0] += 2;
		break;
	}
	gotoxy(mysnake.x[0], mysnake.y[0]);
	printf("��");
	changeFlag = 0;
	gotoxy(MAPHEIGHT + 2, 0);
}
int  snakeStaus()		//��״̬
{
	if (mysnake.x[0] == 0 || mysnake.x[0] == MAPHEIGHT - 2 || mysnake.y[0] == MAPWIDTH - 2 || mysnake.y[0] == 0)
		return 0;
	for (int k = 1; k<mysnake.len; k++)
	if (mysnake.x[k] == mysnake.x[0] && mysnake.y[k] == mysnake.y[0])
		return 0;
	return 1;
}
