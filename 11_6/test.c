#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	int i = -20;
//	unsigned int j = 10;
//	printf("%d\n", i + j);
//	system("pause");
//	return 0;
//}
//int main()
//{
//	unsigned int i;
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);
//	}
//	system("pause");
//	return 0;
//}
int main()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d", strlen(a));
	system("pause");
		return 0;
}