#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"list.h"
void test()
{
	Node* plist=NULL;
	//InitList(&plist);
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PrintList(plist); 
	printf("len=%d\n", GetListLength(plist));
	DestroyList(&plist);
	PrintList(plist);
}
int main()
{
	test();
	return 0;
}
