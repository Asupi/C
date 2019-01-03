#ifndef __LIST_H__
#define __LIST_H__
#include<stdio.h>
#include<string.h>
#include<assert.h>
typedef int DataType;
typedef struct Node
{
	DataType Data;
	struct Node* next;
}Node, *pNode, *pList;

pNode BuyNode(DataType d);
void InitList(pList* pplist);
void DestroyList(pList *plist);
void InitList(pList* pplist);
void PushBack(pList*pplist, DataType d)
int GetListLength(pList, plist);

#endif