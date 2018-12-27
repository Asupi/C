#pragma once

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef int SLDataType;


typedef struct SLNode {
	SLDataType	value;
	struct SLNode *next;
}	SListNode;

typedef struct SList {
	SListNode *first;		// SLNode *head;
}	SList;

// ��ʼ��
void SListInit(SList *list) {
	assert(list != NULL);
	list->first = NULL;
}
// ����
void SListDestroy(SList *list) {
	assert(list != NULL);

	SListNode *cur = list->first;
	SListNode *next;
	while (cur != NULL) {
		next = cur->next;
		free(cur);
		cur = next;
	}

	list->first = NULL;
}

// �����½��
SListNode * SListBuyNode(SLDataType value)
{
	SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	assert(node);
	node->value = value;
	node->next = NULL;

	return node;
}

// ��
// ͷ��
void SListPushFront(SList *list, SLDataType value)
{
	assert(list != NULL);
	SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	assert(node);
	node->value = value;
	node->next = list->first;
	list->first = node;
}

// β��
void SListPushBack(SList *list, SLDataType value)
{
	assert(list != NULL);
	if (list->first == NULL) {
		SListPushFront(list, value);
		return;
	}

	// �������н������
	// �������е����һ�����
	SListNode *cur;
	for (cur = list->first; cur->next != NULL; cur = cur->next) {
	}

	// cur �������һ�����
	SListNode *node = SListBuyNode(value);
	cur->next = node;
}

// ɾ
// ͷɾ
void SListPopFront(SList *list)
{
	assert(list != NULL);			// ��֤�������е�
	assert(list->first != NULL);	// ��֤����Ϊ��

	SListNode *old_first = list->first;
	list->first = list->first->next;
	free(old_first);
}

void SListPopBack(SList *list)
{
	assert(list != NULL);			// ��֤�������е�
	assert(list->first != NULL);	// ��֤����Ϊ��
	// ���ֻ��һ�����
	if (list->first->next == NULL) {
		SListPopFront(list);
		return;
	}

	SListNode *cur = list->first;
	while (cur->next->next != NULL) {
		cur = cur->next;
	}

	free(cur->next);
	cur->next = NULL;
}

// ��

// ��

void TestSList1() {
	SList list;
	SListInit(&list);
	assert(list.first == NULL);

	/*
	SListPushFront(&list, 1);
	SListPushFront(&list, 2);
	SListPushFront(&list, 3);
	*/
	// 3 2 1

	SListPushBack(&list, 11);
	SListPushBack(&list, 12);
	SListPushBack(&list, 13);
	// 3 2 1 11 12 13

	SListPopFront(&list);
	SListPopFront(&list);
	SListPopFront(&list);

	printf("��ɹ�\n");
}

// ��ӡ
void SListPrint(const SList *list) {
	for (SListNode *cur = list->first; cur != NULL; cur = cur->next) {
		printf("%d --> ", cur->value);
	}

	printf("NULL\n");
}
