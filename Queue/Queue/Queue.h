#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

//初始化
void QueueInit(Queue* pq);

//销毁
void QueueDestroy(Queue* pq);

//打印
void QueuePrint(Queue* pq);

//入队
void QueuePush(Queue* pq, QDataType x);

//出队
void QueuePop(Queue* pq);

//队列大小
void QueueSize(Queue* pq);

//判空
bool QueueEmpty(Queue* pq);

//队头
QDataType QueueFront(Queue* pq);

//队尾
QDataType QueueBack(Queue* pq);

