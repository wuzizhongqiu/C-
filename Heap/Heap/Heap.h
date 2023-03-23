#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;//���������ʽʵ�ֶ�
	int size;
	int capacity;
}HP;

//��ʼ��
void HeapInit(HP* hp);

//����
void HeapDestory(HP* hp);

//��������
void HeapPush(HP* hp, HPDataType x);

//ɾ������
void HeapPop(HP* hp);

//ȡ�Ѷ�����
HPDataType HeapTop(HP* hp);

//�п�
bool HeapEmpty(HP* hp);

//ȡ��С
int HeapSize(HP* hp);

//���ϵ���
void AdjustUp(HPDataType* hp, int child);

//���µ���
void AdjustDown(HPDataType* a, int n, int parent);

//�������������ã�
void Swap(HPDataType* p1, HPDataType* p2);