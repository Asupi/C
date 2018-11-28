#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* GetMemory()
{
	char *p = (char *)malloc(100);
	return p;
}
void main(void)
{
	char *str = NULL;
	str= GetMemory();
	strcpy(str, "hello world");
	printf(str);
	system("pause");
}
