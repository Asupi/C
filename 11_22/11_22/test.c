//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%p\n", arr);
//	printf("%p\n", &arr);
//	system("pause");
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int Add(int a, int b)
{
	return a + b;
}
int Sub(int a, int b)
{
	return a - b;
}
int Mul(int a, int b)
{
	return a*b;
}
int Div(int a, int b)
{
	return a / b;
}
int main()
{
	int x, y;
	int input = 1;
	int ret = 0;
	while (input)
	{
		printf("******************************\n");
		printf("****** 1:Add      2:Sub ******\n");
		printf("****** 3:Mul      4:Div ******\n");
		printf("******************************\n");
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入操作数：");
			scanf("%d %d", &x, &y);
			ret = Add(x, y);
			break;
		case 2:
			printf("请输入操作数：");
			scanf("%d %d", &x, &y);
			ret = Sub(x, y);
			break;
		case 3:
			printf("请输入操作数：");
			scanf("%d %d", &x, &y);
			ret = Mul(x, y);
			break;
		case 4:
			printf("请输入操作数：");
			scanf("%d %d", &x, &y);
			ret = Div(x, y);
			break;
		default:
			printf("输入错误\n");
			break;
		}
		printf("ret = %d\n", ret);
	}
	system("pause");
	return 0;
}
