#pragma once

#include <stdbool.h>

typedef int	SDataType;


typedef struct SeqList {
	SDataType	*array;		// 指向堆上的空间
	int size;		// 表示当前顺序表里有多少个数
	// 顺便也表示了即将插入的下标
	int	capacity;	// 容量
}	SeqList;

// 初始化/销毁
// 初始化
// seqlist 是一个变量的地址
// capacity 表示顺序表的初始容量
void SeqListInit(SeqList *seqlist, int capacity);

void SeqListDestroy(SeqList *seqlist);

// 增删改查

// 插入
// 尾插
void SeqListPushBack(SeqList *seqlist, SDataType value);

// 头插
void SeqListPushFront(SeqList *seqlist, SDataType value);

// 中间插入，往 pos 所在的下标插入 value
void SeqListInsert(SeqList *seqlist, int pos, SDataType value);

// 删除
// 尾删
void SeqListPopBack(SeqList *seqlist);

// 头删
void SeqListPopFront(SeqList *seqlist);

// 删除 pos 所在的下标的数据
void SeqListErase(SeqList *seqlist, int pos);

// 打印
void SeqListPrint(const SeqList *seqlist);

// 修改 pos 所在下标的数据为 value
void SeqListModify(SeqList *seqlist, int pos, SDataType value);

// 查找
// 如果找到，返回第一个找到的下标
// 如果没找到，返回 -1
int SeqListFind(const SeqList *seqlist, SDataType value);

// 找到并删除第一个遇到的 value
void SeqListRemove(SeqList *seqlist, SDataType value);

// 判断顺序表是否为空
bool SeqListEmpty(const SeqList *seqlist);

// 返回数据个数
int SeqListSize(const SeqList *seqlist);

// 冒泡排序
void SeqListBubbleSort(SeqList *seqlist);

// 二分查找
int SeqListBinarySearch(const SeqList *seqlist, SDataType value);


// 删除遇到的所有 value
void SeqListRemoveAll(SeqList *seqlist, SDataType value);
