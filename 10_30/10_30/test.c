#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
//⊙  ■
///////////////////////////////////////
//		地图的长和宽
#define MAPHEIGHT 25
#define MAPWIDTH 60
#define SNAKESIZE 50
///////////////////////////////////////
//		数据设计
int changeFlag = 0;//蛇变形标记
int key = 'w';
struct food
{
	//食物的位置
	int x;
	int y;
}food;
struct snake
{
	int x[SNAKESIZE]; 	//蛇坐标
	int y[SNAKESIZE];
	int len;			//当前长度
	int speed;			//移动速度
}mysnake;		//mysnake[0] 蛇头
/////////////////////////////////////////
//		模块化设计
void drawMap();			//绘制游戏地图
void createFood();		//产生食物
void keyDown();			//按键处理
int  snakeStaus();		//蛇状态
void gotoxy(int x, int y);	//cmd移动辅助函数
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
//			cmd移动辅助函数
void gotoxy(int x, int y)
{
	//获取cmd窗口句柄
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//光标坐标
	COORD coord;
	//设置窗口坐标
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(handle, coord);
}
////////////////////////////////////////
//	  绘制游戏地图
void drawMap()
{
	srand((unsigned int)time(NULL));
	//食物
	//1.食物属性
	food.x = rand() % (MAPWIDTH - 4/*食物图标占用2个字符*/) + 2;
	food.y = rand() % (MAPHEIGHT - 2) + 1;
	//2.画食物
	gotoxy(food.x, food.y);
	printf("⊙");
	//蛇
	//1.蛇属性
	mysnake.x[0] = MAPWIDTH / 2;	//定位在中间
	mysnake.y[0] = MAPHEIGHT / 2;
	//2.画蛇
	gotoxy(mysnake.x[0], mysnake.y[0]);
	printf("■");
	mysnake.len = 3;
	mysnake.speed = 100;
	for (int k = 1; k<mysnake.len; k++)
	{
		mysnake.x[k] = mysnake.x[k - 1] + 2;
		mysnake.y[k] = mysnake.y[k - 1];
		gotoxy(mysnake.x[k], mysnake.y[k]);
		printf("■");
	}
	//边框
	//1.左右
	for (int i = 0; i <= MAPHEIGHT; i++)
	{
		gotoxy(0, i);
		printf("■");
		gotoxy(MAPWIDTH, i);
		printf("■");
	}
	//2.上下
	for (int i = 0; i <= MAPWIDTH; i += 2)
	{
		gotoxy(i, 0);
		printf("■");
		gotoxy(i, MAPHEIGHT);
		printf("■");
	}
}
////////////////////////////////////////
//	  产生食物
void createFood()			//产生食物
{
	//产生条件：食物被吃
	if (mysnake.x[0] == food.x&&mysnake.y[0] == food.y)
	{
		//完整版本：食物不能是在蛇身
		srand((unsigned int)time(NULL));
		//x必须为偶数 	
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
			//食物坐标要为偶数并且不能再蛇身上
			if (flag&&food.x % 2 == 0)
			{
				break;
			}
		}
		gotoxy(food.x, food.y);
		printf("⊙");
		mysnake.len++;
		changeFlag = 1;
	}
}
////////////////////////////////////////												
//	  按键处理
void keyDown()
{

	//无按键处理蛇要移动
	if (_kbhit())
	{
		fflush(stdin);
		key = _getch();
	}
	//没变化
	if (!changeFlag)
	{
		gotoxy(mysnake.x[mysnake.len - 1], mysnake.y[mysnake.len - 1]);
		printf("  ");
	}
	//后面的节数处理:往前移动
	for (int i = mysnake.len - 1; i > 0; i--)
	{
		mysnake.x[i] = mysnake.x[i - 1];
		mysnake.y[i] = mysnake.y[i - 1];
	}
	//有按键处理
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
	printf("■");
	changeFlag = 0;
	gotoxy(MAPHEIGHT + 2, 0);
}
int  snakeStaus()		//蛇状态
{
	if (mysnake.x[0] == 0 || mysnake.x[0] == MAPHEIGHT - 2 || mysnake.y[0] == MAPWIDTH - 2 || mysnake.y[0] == 0)
		return 0;
	for (int k = 1; k<mysnake.len; k++)
	if (mysnake.x[k] == mysnake.x[0] && mysnake.y[k] == mysnake.y[0])
		return 0;
	return 1;
}
