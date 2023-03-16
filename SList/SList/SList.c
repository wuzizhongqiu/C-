#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

//��ӡ����
void SLPrint(SLNode* phead)
{
	//����һ��ָ��������������
	SLNode* cur = phead;

	//������ӡ
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}

	//�������Ϊ��
	printf("NULL\n");
}

//����һ���½ڵ㣨�ظ�����д�ɺ������ã�
SLNode* BuyNewNode(SLDataType x)
{
	//mallocһ������ڵ��С�Ŀռ�
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));

	//���
	if (newnode == NULL)
	{
		perror("malloc::fail");
		return;
	}

	//��ֵ
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

//β��
void SLPushBack(SLNode** pphead, SLDataType x)
{
	//������ָ��pphead��ַ�Ƿ�Ϊ��	
	//�������Ƿ񴫿�ָ����
	assert(pphead);

	//�����ڵ�
	SLNode* newnode = BuyNewNode(x);

	//�������Ϊ��
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else//�������Ϊ��
	{
		//��β
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		//β��
		tail->next = newnode;
	}
}

//ͷ��
void SLPushFront(SLNode** pphead, SLDataType x)
{
	//������ָ��pphead��ַ�Ƿ�Ϊ��	
	//�������Ƿ񴫿�ָ����
	assert(pphead);

	//�����ڵ�
	SLNode* newnode = BuyNewNode(x);

	//ͷ��
	newnode->next = *pphead;
	*pphead = newnode;
}

//βɾ
void SLPopBack(SLNode** pphead)
{
	//������ָ��pphead��ַ�Ƿ�Ϊ��	
	//�������Ƿ񴫿�ָ����
	assert(pphead);
	//��������Ƿ�Ϊ��
	assert(*pphead);

	//ͷɾ�����������ֻ��һ�����ݣ�
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//��β
		SLNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}

		//βɾ
		free(tail->next);
		tail->next = NULL;
	}
}

//ͷɾ
void SLPopFront(SLNode** pphead)
{
	//������ָ��pphead��ַ�Ƿ�Ϊ��	
	//�������Ƿ񴫿�ָ����
	assert(pphead);
	//��������Ƿ�Ϊ��
	assert(*pphead);

	//ͷɾ
	SLNode* cur = (*pphead)->next;
	free(*pphead);
	*pphead = NULL;
	*pphead = cur;
}

//����
SLNode* SLFind(SLNode* phead, SLDataType x)
{
	//����ָ���������
	SLNode* cur = phead;

	//����
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}

	return NULL;
}

//����
void SLInsert(SLNode** pphead, SLNode* pos, SLDataType x)
{
	//�����ҵĵ�ַ�Ƿ�Ϊ��
	assert(pos);

	//pos��λ��
	if (pos == *pphead)
	{
		SLPushFront(pphead, x);
	}
	else//�������м�
	{
		SLNode* prev = *pphead;

		//����pos��Ӧλ��
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		//����
		SLNode* newnode = BuyNewNode(x);
		prev->next = newnode;
		newnode->next = pos;
	}
}

//ɾ��
void SLErase(SLNode** pphead, SLNode* pos)
{
	//������ָ��pphead��ַ�Ƿ�Ϊ��	
	//�������Ƿ񴫿�ָ����
	assert(pphead);

	//�����ҵĵ�ַ�Ƿ�Ϊ��
	assert(pos);

	//��������Ƿ�Ϊ�գ�������ʵ������Ҳ���ԣ�
	assert(*pphead);

	//ͷɾ�����
	if (*pphead == pos)
	{
		SLPopFront(pphead);
	}
	else
	{
		//����
		SLNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		//ɾ��
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//��pos�������
void SLInsertAfter(SLNode* pos, SLDataType x)
{
	//�����ҵĵ�ַ�Ƿ�Ϊ��
	assert(pos);

	//�����ڵ�
	SLNode* newnode = BuyNewNode(x);

	//��pos�������
	newnode->next = pos->next;
	pos->next = newnode;
}

//��pos����ɾ��
void SLEraseAfter(SLNode* pos)
{
	//�����ҵĵ�ַ��Ҫɾ���ĵ�ַ�Ƿ�Ϊ��
	assert(pos);
	assert(pos->next);

	//��pos����ɾ����prev��סҪɾ���Ľڵ㣬Ȼ��free
	SLNode* prev = pos->next;
	pos->next = prev->next;
	free(pos->next);
	prev = NULL;
}






