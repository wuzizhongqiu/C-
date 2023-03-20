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

//��ʼ��
void QueueInit(Queue* pq);

//����
void QueueDestroy(Queue* pq);

//��ӡ
void QueuePrint(Queue* pq);

//���
void QueuePush(Queue* pq, QDataType x);

//����
void QueuePop(Queue* pq);

//���д�С
void QueueSize(Queue* pq);

//�п�
bool QueueEmpty(Queue* pq);

//��ͷ
QDataType QueueFront(Queue* pq);

//��β
QDataType QueueBack(Queue* pq);

