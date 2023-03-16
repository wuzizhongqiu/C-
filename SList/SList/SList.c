#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

//打印链表
void SLPrint(SLNode* phead)
{
	//设置一个指针用来遍历链表
	SLNode* cur = phead;

	//遍历打印
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}

	//如果链表为空
	printf("NULL\n");
}

//建立一个新节点（重复操作写成函数复用）
SLNode* BuyNewNode(SLDataType x)
{
	//malloc一个链表节点大小的空间
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));

	//检查
	if (newnode == NULL)
	{
		perror("malloc::fail");
		return;
	}

	//赋值
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

//尾插
void SLPushBack(SLNode** pphead, SLDataType x)
{
	//检查二级指针pphead地址是否为空	
	//方便检查是否传空指针了
	assert(pphead);

	//创建节点
	SLNode* newnode = BuyNewNode(x);

	//如果链表为空
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else//如果链表不为空
	{
		//找尾
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		//尾插
		tail->next = newnode;
	}
}

//头插
void SLPushFront(SLNode** pphead, SLDataType x)
{
	//检查二级指针pphead地址是否为空	
	//方便检查是否传空指针了
	assert(pphead);

	//创建节点
	SLNode* newnode = BuyNewNode(x);

	//头插
	newnode->next = *pphead;
	*pphead = newnode;
}

//尾删
void SLPopBack(SLNode** pphead)
{
	//检查二级指针pphead地址是否为空	
	//方便检查是否传空指针了
	assert(pphead);
	//检查链表是否为空
	assert(*pphead);

	//头删的情况（链表只有一个数据）
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//找尾
		SLNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}

		//尾删
		free(tail->next);
		tail->next = NULL;
	}
}

//头删
void SLPopFront(SLNode** pphead)
{
	//检查二级指针pphead地址是否为空	
	//方便检查是否传空指针了
	assert(pphead);
	//检查链表是否为空
	assert(*pphead);

	//头删
	SLNode* cur = (*pphead)->next;
	free(*pphead);
	*pphead = NULL;
	*pphead = cur;
}

//查找
SLNode* SLFind(SLNode* phead, SLDataType x)
{
	//创建指针遍历链表
	SLNode* cur = phead;

	//查找
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

//插入
void SLInsert(SLNode** pphead, SLNode* pos, SLDataType x)
{
	//检查查找的地址是否为空
	assert(pos);

	//pos的位置
	if (pos == *pphead)
	{
		SLPushFront(pphead, x);
	}
	else//在链表中间
	{
		SLNode* prev = *pphead;

		//查找pos对应位置
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		//插入
		SLNode* newnode = BuyNewNode(x);
		prev->next = newnode;
		newnode->next = pos;
	}
}

//删除
void SLErase(SLNode** pphead, SLNode* pos)
{
	//检查二级指针pphead地址是否为空	
	//方便检查是否传空指针了
	assert(pphead);

	//检查查找的地址是否为空
	assert(pos);

	//检查链表是否为空（这里其实不断言也可以）
	assert(*pphead);

	//头删的情况
	if (*pphead == pos)
	{
		SLPopFront(pphead);
	}
	else
	{
		//查找
		SLNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		//删除
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//从pos后面插入
void SLInsertAfter(SLNode* pos, SLDataType x)
{
	//检查查找的地址是否为空
	assert(pos);

	//创建节点
	SLNode* newnode = BuyNewNode(x);

	//再pos后面插入
	newnode->next = pos->next;
	pos->next = newnode;
}

//从pos后面删除
void SLEraseAfter(SLNode* pos)
{
	//检查查找的地址和要删除的地址是否为空
	assert(pos);
	assert(pos->next);

	//在pos后面删除，prev记住要删除的节点，然后free
	SLNode* prev = pos->next;
	pos->next = prev->next;
	free(pos->next);
	prev = NULL;
}






