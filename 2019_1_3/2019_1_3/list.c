#define _CRT_SECURE_NO_WARNINGS 
#include"list.h"

void InitList(pList* pplist)
{
	assert(pplist != NULL);
	*pplist = NULL;
}
void DestroyList(pList* pplist)
{
	pNode cur = *pplist;
	assert(pplist != NULL);
	cur = *pplist;
	while (cur)
	{
		pNode del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	*pplist = NULL;
}
pNode BuyNode(DataType d)
{
	pNode newNode = (pNode)malloc(sizeof(Node));
	newNode->Data = d;
	newNode->next = NULL;
	return newNode;
}
void PushBack(pList*pplist, DataType d)
{
	//¿ÕÁ´±í
	if (*pplist == NULL)
	{
		pNode newNode = BuyNode(d);
		assert(pplist = !NULL);
	}
	else//·Ç¿ÕÁ´±í
	{
		pNode cur = *pplist;
		pNode newNode = BuyNode(d);
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}
void PrintfList(pList plist)
{
	pNode cur = plist;
	while (cur != NULL)
	{
		printf("%d--> ", cur->data);
		cur = cur->next;
	}
	printf("Over\n");
}
int GetListLength(pList, plist)
{
	pNode cur = plist;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
