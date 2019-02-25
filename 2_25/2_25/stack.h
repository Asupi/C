#include<stdio.h>
#include<malloc.h>
//#pragma once
//
//typedef int DataType;
//
//typedef struct Stack
//{
//	DataType _a[N];
//	int _top;
//
//}Stack;

#include<assert.h>

typedef int DataType;

typedef struct Stack
{
	DataType* _a;
	int _top;      //Õ»¶¥
	int _capacity; //ÈÝÁ¿
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);

void StackPush(Stack* ps, DataType x);
void StackPop(Stack* ps);

DataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);