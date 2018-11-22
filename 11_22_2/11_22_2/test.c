//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
////qsort������ʹ���ߵ�ʵ��һ���ȽϺ���
//int int_cmp(const void*p1, const void*p2)
//{
//	return (*(int *)p1 > *(int *)p2);
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 3, 7, 9, 8, 0 };
//	int i = 0;
//
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%d", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int int_cmp(const void*p1, const void*p2)
{
	return (*(int *)p1 > *(int *)p2);
}
void _swap(void*p1, void*p2, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		char tmp = *((char *)p1 + i);
		*((char *)p1 + i) = *((char *)p2 + i);
		*((char *)p2 + i) = tmp;
	}
}
void bubble(void *base, int count, int size, int(*cmp)(void *, void *))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - i; j++)
		{
			if (cmp((char *)base + j*size, (char *)base + (j + 1)*size)>0)
			{
				_swap((char *)base + j*size, (char *)base + (j + 1)*size, size);
			}

		}
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 3, 7, 9, 8, 0 };
//	char*arr[]={"aaaa","bbbb","cccc","dddd"};
	int i = 0;

	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

 