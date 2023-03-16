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

//��ӡ����
void SLPrint(SLNode* phead);

//β��
void SLPushBack(SLNode** pphead, SLDataType x);

//ͷ��
void SLPushFront(SLNode** pphead, SLDataType x);

//βɾ
void SLPopBack(SLNode** ppheadx);

//ͷɾ
void SLPopFront(SLNode** pphead);

//����
SLNode* SLFind(SLNode* phead, SLDataType x);

//����
void SLInsert(SLNode** phead, SLNode* pos, SLDataType x);

//ɾ��
void SLErase(SLNode** phead, SLNode* pos);

//��pos�������
void SLInsertAfter(SLNode* pos, SLDataType x);

//��pos����ɾ��
void SLEraseAfter(SLNode* pos);


