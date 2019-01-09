#pragma once

#include <stdio.h>
#include <string.h>
#include "高精度计时.h"

void PrintArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}

	printf("\n");
}

#if 0
// 插入排序
// 直接插入法
void InsertSort(int array[], int size) {
	for (int i = 1; i < size; i++) {
		// 要为 array[i] 找位置
		int k = array[i];
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (array[j] <= array[i]) {
				//memmove(array + j + 1, array + j + 2, i - j - 1);
				array[j + 1] = k;
				break;
			}
		}

		if (j == -1) {
			memmove(array + j + 1, array + j + 2, i - j - 1);
			array[j + 1] = k;
		}
	}
}
#endif

// 直接插排
// 时间 O(n^2)
// 最坏	平均 最好
// n^2（逆序）  n^2	 n (已经有序）
// 空间 O(1)
// 稳定性 稳定
void InsertSort(int array[], int size) {
	for (int i = 1; i < size; i++) {
		int k = array[i];
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (array[j] <= k) {
				break;
			}
			else {
				array[j + 1] = array[j];
			}
		}

		array[j + 1] = k;
	}
}

// 插入排序的降序
void InsertSortR(int array[], int size) {
	for (int i = 1; i < size; i++) {
		int k = array[i];
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (array[j] >= k) {
				break;
			}
			else {
				array[j + 1] = array[j];
			}
		}

		array[j + 1] = k;
	}
}

// 插入排序
// 二分查找位置
// O(n^2)
// 留给作业


// 带 gap 参数的插入排序（升序）
void InsertSortWithGap(int array[], int size, int gap) {
	for (int i = gap; i < size; i++) {
		int k = array[i];
		int j;
		for (j = i - gap; j >= 0; j -= gap) {
			if (array[j] <= k) {
				break;
			}
			else {
				array[j + gap] = array[j];
			}
		}

		array[j + gap] = k;
	}
}

// 希尔排序
// 升序
// O(n^1.3 - n^2)
// 空间 O(1)
// 不稳定
void ShellSort(int array[], int size) {
	int gap = size;
	while (1) {
		gap = gap / 3 + 1;
		// gap 比较大的数 -> 小 -> 1 停止
		InsertSortWithGap(array, size, gap);
		if (gap == 1) {
			break;
		}
	}
}

// 带 gap 的插入排序降序
void InsertSortWithGapR(int array[], int size, int gap) {
	for (int i = gap; i < size; i++) {
		int k = array[i];
		int j;
		for (j = i - gap; j >= 0; j -= gap) {
			if (array[j] >= k) {
				break;
			}
			else {
				array[j + gap] = array[j];
			}
		}

		array[j + gap] = k;
	}
}

// 降序希尔排序
void ShellSortR(int array[], int size) {
	int gap = size;
	while (1) {
		gap = gap / 3 + 1;
		// gap 比较大的数 -> 小 -> 1 停止
		InsertSortWithGapR(array, size, gap);
		if (gap == 1) {
			break;
		}
	}
}

// 交换
void Swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

// 直接选择排序
// 每次选最小的数
// 时间复杂度 O(n^2)
// 空间复杂度 O(1)
// 稳定	不稳定
void SelectSort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		// 遍历整个蓝色的部分，找到最小数的下标
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (array[j] < array[min]) {
				min = j;
			}
		}

		// 交换 最小的数到 合适的位置上[i]
		Swap(array + min, array + i);
	}
}

// 进化版
// 一次既找最大也找最小
// O(n^2)
void SelectSortOP(int array[], int size) {
	int minSpace = 0;	// 用来放找到的最小数的下标
	int maxSpace = size - 1;	// 用来放找到的最大的数的下标
	while (minSpace < maxSpace) {
		int min = minSpace;	// 假设最小的数在下标 minSpace
		int max = minSpace;	// 假设最大的数在下标 minSpace

		for (int j = minSpace + 1; j <= maxSpace; j++) {
			if (array[j] < array[min]) {
				min = j;
			}

			if (array[j] > array[max]) {
				max = j;
			}
		}

		Swap(array + min, array + minSpace);
		if (minSpace == max) {
			max = min;
		}
		Swap(array + max, array + maxSpace);

		minSpace++;
		maxSpace--;
	}
}

// 向下调整
void AdjustDown(int array[], int size, int root) {
	// 判断 root 是不是叶子
	int i = 2 * root + 1;

	if (i >= size) {
		return;
	}

	// 找到大孩子，得考虑有没有右孩子的情况
	int max = i;
	if (i + 1 < size && array[i + 1] > array[i]) {
		max = i + 1;
	}

	// 大孩子的值 和 根的值比较
	if (array[root] >= array[max]) {
		return;
	}

	// 交换
	Swap(array + root, array + max);

	// 继续对 max 调整
	AdjustDown(array, size, max);
}

// 堆排序
// 时间复杂度 O(n * logN)
// 空间复杂度 O(1)
// 不稳定
void HeapSort(int array[], int size) {
	// 建大堆
	for (int i = (size - 2) / 2; i >= 0; i--) {
		AdjustDown(array, size, i);
	}

	for (int i = 0; i < size - 1; i++) {
		Swap(&array[0], array + size - 1 - i);
		// 向下调整，把堆结构调整为正确状态
		AdjustDown(array, size - 1 - i, 0);
	}
}

// 测试正确性
void TestSort() {
	int array[] = {
		3, 9, 1, 7, 6, 8, 4, 2, 5, 0
		//0, 1, 2, 3, 4, 5, 6, 7, 8, 9
		//9, 8, 7, 6, 5, 4, 3, 2, 1, 0
	};
	int size = sizeof array / sizeof(int);

	HeapSort(array, size);

	PrintArray(array, size);
}

// 测试速度
void TestSortSpeed() {
#define SIZE	(10 * 10000)

	srand(20190109);
	int array[SIZE];

	for (int i = 0; i < SIZE; i++) {
		array[i] = rand() % SIZE;
	}

	ShellSortR(array, SIZE);

	高精度计时	计时器;
	计时器.开始();
	HeapSort(array, SIZE);
	计时器.结束();

	printf("执行时间 %f 毫秒\n", 计时器.间隔毫秒());
}