#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h" 

//��ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

//����
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

//��ӡ
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

//���
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

//����
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

//���д�С
int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}

//�п�
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->size == 0;
}

//��ͷ
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(&pq));

	return pq->head->data;
}

//��β
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(&pq));
	
	return pq->tail->data;
}