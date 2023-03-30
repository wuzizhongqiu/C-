#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h" 

//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

//销毁
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

//打印
void QueuePrint(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//入队
void QueuePush(Queue* pq, QDataType x)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc::fail");
		exit(-1);
	}

	newnode->data = x;
	newnode->next = NULL;

	if (pq->head == NULL)
	{
		assert(pq->tail == NULL);
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	pq->size++;
}

//出队
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head != NULL);

	QNode* tmp = pq->head;
	pq->head = pq->head->next;
	free(tmp);
	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}

	pq->size--;
}

//队列大小
int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}

//判空
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->size == 0;
}

//队头
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(&pq));

	return pq->head->data;
}

//队尾
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(&pq));
	
	return pq->tail->data;
}