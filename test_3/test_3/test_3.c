#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//int clc_disp(int n)
//{
//	int i = 0;
//	int j = 0;
//
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%-2d*%-2d=%-4d", i, j, i*j);
//		}
//		printf("\n");
//	}
//}
//	int main()
//	{
//		int num = 0;
//		printf("������������������");
//		scanf("%d", &num);
//		clc_disp(num);
//
//		system("pause");
//	return 0;
//}
//void swap(int *a,int *b)
//{
//		int tmp;
//		tmp = *a;
//		*a = *b;
//		*b = tmp;
//	
//}
//int main()
//{
//	int a = 20;
//	int b = 10;
//	swap(&a, &b);
//	printf("a=%d b=%d", a, b);
//	system("pause");
//	return 0;
//
//}

//int bissextile(year)
//{
//	return(year % 4 == 0) && (year % 100 != 0)|| (year % 400 == 0);
//}
//int main()
//{
//	int year = 0;
//	int ret = 0;
//	printf("���������: ");
//	scanf("%d", &year);
//	printf("\n");
//	ret = bissextile(year);
//	if (ret == 1)
//		printf("%d������\n", year);
//	else
//		printf("%d��������\n", year);
//	system("pause");
//	return 0;
//
//
//}
//void init(int a[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		a[i] = i;
//		printf("%d ", a[i]);
//	}
//}
//void empty(int a[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		a[i] = 0;
//		printf("%d ", a[i]);
//	}
//}
//void reverse(int a[], int sz)
//{
//	int i = 0;
//	int left = 0;
//	int right = sz - 1;
//	for (i = 0; i < sz; i++)
//	{
//		while (left < right)
//		{
//			int tmp = a[left];
//			a[left] = a[right];
//			a[right] = tmp;
//			left++;
//			right--;
//		}
//		printf("%d ", a[i]);
//	}
//}
//int main()
//{
//	int a[5];
//	int sz = sizeof(a) / sizeof(a[0]);
//	printf("��������ʼ��:\n");
//	init(a, sz);
//	printf("\n");
//	printf("��������������:\n");
//	reverse(a, sz);
//	printf("\n");
//	printf("���������:\n");
//	empty(a, sz);
//	printf("\n");
//	system("pause");
//	return 0;
//}
int prime(int a)
{
	int i = 0;
	for (i = 2; i < a; i++)
	{
		if (a%i == 0)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int a = 0;
	int ret = 0;
	printf("������һ�����ڶ�����: ");
	scanf("%d", &a);
	prime(a);
	ret = prime(a);
	if (ret == 1)
	{
		printf("��������");
	}
	else
	{
		printf("������");
	}
	system("pause");
	return 0;
}