#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int STDataType;

typedef struct Stack
{
	int* a;
	int top;
	int capacity;
}ST;

//��ʼ��
void STInit(ST* ps);

//����
void STDestroy(ST* ps);

//ѹջ
void STPush(ST* ps, STDataType x);

//��ջ
void STPop(ST* ps);

//ջ��С
int STSize(ST* ps);

//�п�
bool STEmpty(ST* ps);

//�鿴ջ��Ԫ��
STDataType STTop(ST* ps);
