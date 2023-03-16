#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SLNode;

//打印链表
void SLPrint(SLNode* phead);

//尾插
void SLPushBack(SLNode** pphead, SLDataType x);

//头插
void SLPushFront(SLNode** pphead, SLDataType x);

//尾删
void SLPopBack(SLNode** ppheadx);

//头删
void SLPopFront(SLNode** pphead);

//查找
SLNode* SLFind(SLNode* phead, SLDataType x);

//插入
void SLInsert(SLNode** phead, SLNode* pos, SLDataType x);

//删除
void SLErase(SLNode** phead, SLNode* pos);

//从pos后面插入
void SLInsertAfter(SLNode* pos, SLDataType x);

//从pos后面删除
void SLEraseAfter(SLNode* pos);


