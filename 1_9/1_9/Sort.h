#pragma once

#include <stdio.h>
#include <string.h>
#include "�߾��ȼ�ʱ.h"

void PrintArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}

	printf("\n");
}

#if 0
// ��������
// ֱ�Ӳ��뷨
void InsertSort(int array[], int size) {
	for (int i = 1; i < size; i++) {
		// ҪΪ array[i] ��λ��
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

// ֱ�Ӳ���
// ʱ�� O(n^2)
// �	ƽ�� ���
// n^2������  n^2	 n (�Ѿ�����
// �ռ� O(1)
// �ȶ��� �ȶ�
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

// ��������Ľ���
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

// ��������
// ���ֲ���λ��
// O(n^2)
// ������ҵ


// �� gap �����Ĳ�����������
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

// ϣ������
// ����
// O(n^1.3 - n^2)
// �ռ� O(1)
// ���ȶ�
void ShellSort(int array[], int size) {
	int gap = size;
	while (1) {
		gap = gap / 3 + 1;
		// gap �Ƚϴ���� -> С -> 1 ֹͣ
		InsertSortWithGap(array, size, gap);
		if (gap == 1) {
			break;
		}
	}
}

// �� gap �Ĳ���������
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

// ����ϣ������
void ShellSortR(int array[], int size) {
	int gap = size;
	while (1) {
		gap = gap / 3 + 1;
		// gap �Ƚϴ���� -> С -> 1 ֹͣ
		InsertSortWithGapR(array, size, gap);
		if (gap == 1) {
			break;
		}
	}
}

// ����
void Swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

// ֱ��ѡ������
// ÿ��ѡ��С����
// ʱ�临�Ӷ� O(n^2)
// �ռ临�Ӷ� O(1)
// �ȶ�	���ȶ�
void SelectSort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		// ����������ɫ�Ĳ��֣��ҵ���С�����±�
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (array[j] < array[min]) {
				min = j;
			}
		}

		// ���� ��С������ ���ʵ�λ����[i]
		Swap(array + min, array + i);
	}
}

// ������
// һ�μ������Ҳ����С
// O(n^2)
void SelectSortOP(int array[], int size) {
	int minSpace = 0;	// �������ҵ�����С�����±�
	int maxSpace = size - 1;	// �������ҵ������������±�
	while (minSpace < maxSpace) {
		int min = minSpace;	// ������С�������±� minSpace
		int max = minSpace;	// �������������±� minSpace

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

// ���µ���
void AdjustDown(int array[], int size, int root) {
	// �ж� root �ǲ���Ҷ��
	int i = 2 * root + 1;

	if (i >= size) {
		return;
	}

	// �ҵ����ӣ��ÿ�����û���Һ��ӵ����
	int max = i;
	if (i + 1 < size && array[i + 1] > array[i]) {
		max = i + 1;
	}

	// ���ӵ�ֵ �� ����ֵ�Ƚ�
	if (array[root] >= array[max]) {
		return;
	}

	// ����
	Swap(array + root, array + max);

	// ������ max ����
	AdjustDown(array, size, max);
}

// ������
// ʱ�临�Ӷ� O(n * logN)
// �ռ临�Ӷ� O(1)
// ���ȶ�
void HeapSort(int array[], int size) {
	// �����
	for (int i = (size - 2) / 2; i >= 0; i--) {
		AdjustDown(array, size, i);
	}

	for (int i = 0; i < size - 1; i++) {
		Swap(&array[0], array + size - 1 - i);
		// ���µ������Ѷѽṹ����Ϊ��ȷ״̬
		AdjustDown(array, size - 1 - i, 0);
	}
}

// ������ȷ��
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

// �����ٶ�
void TestSortSpeed() {
#define SIZE	(10 * 10000)

	srand(20190109);
	int array[SIZE];

	for (int i = 0; i < SIZE; i++) {
		array[i] = rand() % SIZE;
	}

	ShellSortR(array, SIZE);

	�߾��ȼ�ʱ	��ʱ��;
	��ʱ��.��ʼ();
	HeapSort(array, SIZE);
	��ʱ��.����();

	printf("ִ��ʱ�� %f ����\n", ��ʱ��.�������());
}