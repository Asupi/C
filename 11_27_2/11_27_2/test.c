//#define _CRT_SECURE_NO_WARNINGS 1
//struct Stu
//{
//	char name[20];//名字
//	int age;//年龄
//	char sx[5];//性别
//	char id[20];//学号
//};//分号不能丢
//
//
////匿名结构体类型
//struct
//{
//	int a;
//	char b;
//	float c;
//}x;
//struct
//{
//	int a;
//	char b;
//	float c;
//}a[20], *p;
//
//struct Point
//{
//	int x;
//	int y;
//}p1;//声明类型的同时定义变量p1
//struct Point p2;//定义结构体变量p2
//
////初始化
//struct Point p3 = { x, y };
//struct Stu   //声明类型
//{
//	char name[15];//名字
//	int age;//年龄
//};
//struct Stu s = { "zhangsan",20 }//初始化
//
//struct Node
//{
//	int datd;
//	struct Point p;
//	struct Node*next;
//}n1 = { 10, { 4, 5 }, NULL };//结构头嵌套初始化
//n2 = { 20, { 5, 6 }, NULL };//结构头嵌套初始化
#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
int main()
{
	int n;
	struct contact people;
	people.count_user = 0;
	printf("请输入一个数：");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		add_contact(&people);
		break;
	case 2:
		del_contact(&people);
		break;
	case 3:
		search_contact(&people);
		break;
	case 4:
		clear_contact(&people);
		break;
	case 5:
		modify_contact(&people);
		break;
	case 6:
		show_contact(&people);
		break;
	default:
		printf("输入错误！");
		break;
	}
	return 0;
}
