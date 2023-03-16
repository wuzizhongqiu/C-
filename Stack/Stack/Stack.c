#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

//��ʼ��
void STInit(ST* ps)
{
	assert(ps);

	ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (ps->a == NULL)
	{
		perror("malloc::STInit");
		exit(-1);
	}

	ps->capacity = 4;
	ps->top = 0;
}

//����
void STDestroy(ST* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;

	ps->top = 0;
	ps->capacity = 0;
}

//ѹջ
void STPush(ST* ps, STDataType x)
{
	assert(ps);

	if (ps->top == ps->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc::STPush");
			exit(-1);
		}

		ps->a = tmp;
		ps->capacity *= 2;
	}

	ps->a[ps->top] = x;
	ps->top++;
}

//��ջ
void STPop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));

	ps->top--;
}

//ջ��С
int STSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

//�п�
bool STEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}

//�鿴ջ��Ԫ��
STDataType STTop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));

	return ps->a[ps->top - 1];
}