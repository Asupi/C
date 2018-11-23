#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//#include <time.h>
//	static void BubbleSort(int *shuzu);
//	void main()
//	{
//		system("clear");
//		int i = 0;
//		int shuzu[11];
//		srand((unsigned int)time(NULL));
//		for (i = 0; i <= 10; i++)
//		{
//			shuzu[i] = rand() % 100;
//		}
//		printf("Original is \n");
//		for (i = 0; i <= 10; i++)
//		{
//			printf("%d  ", shuzu[i]);
//		}
//		printf("\n\n\n");
//		BubbleSort(shuzu);
//		system("pause");
//	}
//	static void BubbleSort(int *shuzu)
//	{
//		int i = 0, j = 0, k = 0;
//		int temp = 0;
//		for (i = 0; i <= 10; i++)
//		{
//			for (j = 10; j >= i; j--)
//			{
//				if (shuzu[j - 1]>shuzu[j])
//				{
//					temp = shuzu[j];
//					shuzu[j] = shuzu[j - 1];
//					shuzu[j - 1] = temp;
//				}
//				for (k = 0; k <= 10; k++)
//				{
//					printf("%d  ", *(shuzu + k));
//				}
//				printf("\n");
//			}
//			printf("the %d round  end\n", i);
//		}
//		printf("\nafter BubbleSort \n");
//		for (i = 0; i <= 10; i++)
//		{
//			printf("%d  ", *(shuzu + i));
//		}
//		printf("\n");
//	}
//
//	



//桶排序最大数字
#define BUCKETSORT_MAX_NUM 1000
//桶排序 p待排序数组指针 length数组长度
int BucketSort(int *p, int length)
{
	int i, j;
	int bucket[BUCKETSORT_MAX_NUM];
	//初始化
	for (i = 0; i<BUCKETSORT_MAX_NUM; i++)
	{
		bucket[i] = 0;
	}
	//桶排序
	for (i = 0; i<length; i++)
	{
		bucket[p[i]]++;
	}
	//输出
	for (i = 0; i<BUCKETSORT_MAX_NUM; i++)
	{
		for (j = 0; j<bucket[i]; j++)
		{
			printf("%d ", i);
		}
	}
	return 1;
}
int main()
{
	//待排序数组
	int array[10] = { 1, 3, 5, 2, 4, 6, 10, 9, 8, 9 };
	int sortResult = BucketSort(array, 10);
	printf("\n%d", sortResult);
	system("pause");
	return 1;
}
