#include "SeqList.h"
#include <stdio.h>


void TestSeqList1() {
	SeqList seqlist;

	SeqListInit(&seqlist, 100);

	SeqListPushBack(&seqlist, 1);
	SeqListPushBack(&seqlist, 2);
	SeqListPushBack(&seqlist, 3);
	// 1, 2, 3 

	SeqListPushFront(&seqlist, 11);
	SeqListPushFront(&seqlist, 12);
	SeqListPushFront(&seqlist, 13);
	// 13, 12, 11, 1, 2, 3

	SeqListInsert(&seqlist, 4, 100);
	// 13, 12, 11, 1, 100, 2, 3


	SeqListPopBack(&seqlist);
	// 13, 12, 11, 1, 100, 2

	SeqListPopFront(&seqlist);
	// 12, 11, 1, 100, 2

	SeqListErase(&seqlist, 2);
	// 12, 11, 100, 2
	SeqListDestroy(&seqlist);
}

void TestSeqList2()
{
	SeqList seqlist;

	SeqListInit(&seqlist, 10);

	SeqListPushBack(&seqlist, 3);
	SeqListPushBack(&seqlist, 5);
	SeqListPushBack(&seqlist, 2);
	SeqListPushBack(&seqlist, 7);
	SeqListPushBack(&seqlist, 9);
	SeqListPushBack(&seqlist, 4);
	SeqListPushBack(&seqlist, 8);
	SeqListPushBack(&seqlist, 6);
	SeqListPushBack(&seqlist, 1);
	SeqListPushBack(&seqlist, 0);

	SeqListBubbleSort(&seqlist);

	int r = SeqListBinarySearch(&seqlist, 3);
	printf("%d\n", r);
}

int main() {
	TestSeqList2();
}
