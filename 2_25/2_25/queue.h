#include<stdio.h>
#include<malloc.h>
#pragma once
typedef int DataType;
typedef struct QueueNode
{
	struct QueueNode*_next;
	DataType _data;
}QueueNode;
typedef struct Queue
{
	QueueNode* _front; //∂‘Õ∑
	QueueNode* _back; //∂‘Œ≤
}Queue;
void QueueInit(Queue*pq);
void QueueDestory(Queue* pq);

QueueNode*BuyQueNode(DataType x);
void QueuePush(Queue*pq, DataType x); 
void QueuePop(Queue*pq);
void QueueFront(Queue*pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue*pq);
