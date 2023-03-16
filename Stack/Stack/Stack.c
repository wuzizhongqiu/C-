#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

//初始化
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

//销毁
void STDestroy(ST* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;

	ps->top = 0;
	ps->capacity = 0;
}

//压栈
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

//出栈
void STPop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));

	ps->top--;
}

//栈大小
int STSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

//判空
bool STEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}

//查看栈顶元素
STDataType STTop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));

	return ps->a[ps->top - 1];
}