#pragma once
#include"queue.h"
void QueueInit(Queue* pq)
{
	asseert(pq);
	pq->_front = NULL;
	pq->_back = NULL;
}
void QueueDestory(Queue* pq)
{
	QueueNode*cur;
	assert(pq);
	cur =pq->_front;
	while (cur !=NULL)
	{
		QueueNode*next = pq->_next;
		free(cur);

		cur = next;
	}
	pq->_front = pq->_back = NULL;
}

QueueNode*BuyQueNode(DataType x)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	assert(node);

	node->_next = NULL;
	node->_data = x;
	return node;
}
void QueuePush(Queue*pq, DataType x)
{
	assert(pq);
	if (pq->_back == NULL)
	{
		pq->_front = pq->_back = BuyQueueNode(x);
	}
	else
	{
		QueueNode* back = BuyQueueNode(x);
		pq->_back->_next = back;
		pq->_back = back;
	}
}
void QueuePop(Queue*pq)
{
	QueueNode* next;
	assert(pq);
	next = pq->_front->_next;
	free(pq->_front);
	pq->_front = next;
}
void QueueFront(Queue*pq)
{
	assert(pq);
	return pq->_front->_data;
}
//¿Õ 0
//·Ç¿Õ 1
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_front == NULL ? 0 : 1;
}
int QueuSize(Queue*pq)
{
	int size = 0;
	QueueNode*cur = pq->_front;
	while (cur)
	{
		size++;
		cur = cur->_next;
	}

	return size;
}
