#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define INIT_CAPACITY 4

//ѡ����Ҫ������
typedef int SLDatatype;

//��̬��˳���
typedef struct SeqList
{
	SLDatatype* a;
	int size;	  //��Ч�����ݸ���
	int capacity; //˳���Ŀռ�����
}SL;

//˳������ɾ���:

//��ʼ��˳���
void SeqInit(SL* s);

//����˳���
void SeqDestory(SL* s);

//��ӡ˳���
void SeqPrint(SL* s);

//�������
void CheckCapacity(SL* s);

//β��
void SeqPushBack(SL* s, SLDatatype x);

//βɾ
void SeqPopBack(SL* s);

//ͷ��
void SeqPushFront(SL* s, SLDatatype x);

//ͷɾ
void SeqPopFront(SL* s);

//����
void SeqInsert(SL* s, int pos, SLDatatype x);

//ɾ��
void SeqErase(SL* s, int pos);


