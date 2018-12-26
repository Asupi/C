#include "SeqList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// ����Ƿ���Ҫ���ݣ������Ҫ���ݾͽ�������
// ��֤��������������һ������
static void CheckCapacity(SeqList *seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size <= seqlist->capacity);

	if (seqlist->size < seqlist->capacity) {
		return;
	}

	// �ߵ�����һ����Ҫ������
	int capacity = 2 * seqlist->capacity;
	SDataType *array = (SDataType *)malloc(sizeof(SDataType)* capacity);
	assert(array);

	// �������ݰ��ƹ���
	for (int i = 0; i < seqlist->size; i++) {
		array[i] = seqlist->array[i];
	}

	free(seqlist->array);
	seqlist->array = array;
}

void SeqListInit(SeqList *seqlist, int capacity)
{
	assert(seqlist != NULL);

	seqlist->array = (SDataType *)malloc(sizeof(SDataType)* capacity);
	assert(seqlist->array);

	seqlist->size = 0;
	seqlist->capacity = capacity;
}

void SeqListDestroy(SeqList *seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);

	free(seqlist->array);	// �ص�

	seqlist->array = NULL;
	seqlist->size = 0;
	seqlist->capacity = 0;
}

void SeqListPushBack(SeqList *seqlist, SDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);

	CheckCapacity(seqlist);

	seqlist->array[seqlist->size] = value;
	seqlist->size++;
}

void SeqListPopBack(SeqList *seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);

	seqlist->size--;
}

void SeqListPushFront(SeqList *seqlist, SDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);

	CheckCapacity(seqlist);

	// �����ݰ��ƣ�i ����ռ��±�
	for (int i = seqlist->size; i > 0; i--) {
		seqlist->array[i] = seqlist->array[i - 1];
	}

	seqlist->array[0] = value;
	seqlist->size++;
}

void SeqListPopFront(SeqList *seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);

	// �����ݰ��ƣ�i ���������±�
	for (int i = 1; i < seqlist->size; i++) {
		seqlist->array[i - 1] = seqlist->array[i];
	}

	seqlist->size--;
}

void SeqListInsert(SeqList *seqlist, int pos, SDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(pos >= 0 && pos <= seqlist->size);

	CheckCapacity(seqlist);

	for (int i = seqlist->size - 1; i >= pos; i--) {
		seqlist->array[i + 1] = seqlist->array[i];
	}

	seqlist->array[pos] = value;
	seqlist->size++;
}

void SeqListErase(SeqList *seqlist, int pos)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);
	assert(pos >= 0 && pos < seqlist->size);

	// ����
	for (int i = pos + 1; i < seqlist->size; i++) {
		seqlist->array[i - 1] = seqlist->array[i];
	}

	seqlist->size--;
}

void SeqListPrint(const SeqList *seqlist)
{
	for (int i = 0; i < seqlist->size; i++) {
		printf("%d ", seqlist->array[i]);
	}

	printf("\n");
}

// �޸� pos �����±������Ϊ value
void SeqListModify(SeqList *seqlist, int pos, SDataType value)
{
	assert(pos >= 0 && pos < seqlist->size);

	seqlist->array[pos] = value;
}

// ����
int SeqListFind(const SeqList *seqlist, SDataType value)
{
	for (int i = 0; i < seqlist->size; i++) {
		if (seqlist->array[i] == value) {
			return i;
		}
	}

	return -1;
}

// �ҵ���ɾ����һ�������� value
void SeqListRemove(SeqList *seqlist, SDataType value)
{
	int pos = SeqListFind(seqlist, value);
	if (pos != -1) {
		SeqListErase(seqlist, pos);
	}
}

// �ж�˳����Ƿ�Ϊ��
bool SeqListEmpty(const SeqList *seqlist)
{
	return seqlist->size == 0;
}

// �������ݸ���
int SeqListSize(const SeqList *seqlist)
{
	return seqlist->size;
} 

void Swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

// ð������
void SeqListBubbleSort(SeqList *seqlist)
{
	int isSorted;
	for (int i = 0; i < seqlist->size - 1; i++) {
		isSorted = 1;

		// һ��ð�ݹ���
		for (int j = 0; j < seqlist->size - 1 - i; j++) {
			if (seqlist->array[j] > seqlist->array[j + 1]) {
				Swap(seqlist->array + j, seqlist->array + j + 1);
				isSorted = 0;
			}
		}
		// һ��ð�ݽ���

		if (isSorted == 1) {
			break;
		}
	}
}

// ���ֲ���
int SeqListBinarySearch(const SeqList *seqlist, SDataType value)
{
	int left = 0;
	int right = seqlist->size;

	while (left < right) {
		int mid = (right - left) / 2 + left;
		if (value == seqlist->array[mid]) {
			return mid;
		}
		else if (value < seqlist->array[mid]) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	return -1;
}


void SeqListRemoveAll(SeqList *seqlist, SDataType value)
{
#if 0	// O(N^2)	O(1)
	int pos;
	while ((pos = SeqListFind(seqlist, value)) != -1) {
		SeqListErase(seqlist, pos);
	}
#endif

#if 0		// O(N)		O(N)
	SDataType *array = (SDataType *)malloc(sizeof(SDataType)* seqlist->size);
	assert(array);

	int index = 0;
	for (int i = 0; i < seqlist->size; i++) {
		if (seqlist->array[i] != value) {
			array[index] = seqlist->array[i];
			index++;
		}
	}

	for (int j = 0; j < index; j++) {
		seqlist->array[j] = array[j];
	}

	seqlist->size = index;
#endif

	int index = 0;
	for (int i = 0; i < seqlist->size; i++) {
		if (seqlist->array[i] != value) {
			seqlist->array[index] = seqlist->array[i];
			index++;
		}
	}

	seqlist->size = index;
}
