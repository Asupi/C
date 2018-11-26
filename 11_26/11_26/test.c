#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
int cmp(const void *m, const void *n)
{
	return *(char *)m - *(char *)n;
}
void swap(char *p1, char *p2, int width)
{
	int i = 0;
	char temp;
	for (; i < width; i++)
	{
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
		*p1++;
		*p2++;
	}

}
void my_qsort(void *base, int size, int width)
{
	int i = 0;
	int j = 0;
	int ret = 0;
	for (i = 0; i < size; i++)
	{
		j = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			ret = cmp((char*)base + j*width, (char*)base + (j + 1)*width);
			if (ret>0)
			{
				swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
			}
		}
	}
}

int main()
{
	int i = 0;
	int a[] = { 5, 4, 3, 2, 1 };
	char b[] = { 's', 'm', 'l', 'z', 'h' };
	//定义两种类型的数据用同一个函数对两组数据进行冒泡排序
	my_qsort(a, 5, 4);
	for (i = 0; i < 5; i++)
	{
		printf("%d\n", a[i]);
	}
	printf("\n");
	my_qsort(b, 5, 1);
	for (i = 0; i < 5; i++)
	{
		printf("%c\n", b[i]);
	}
	printf("\n");
	system("pause");
	return 0;

}

