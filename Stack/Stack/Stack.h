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

//初始化
void STInit(ST* ps);

//销毁
void STDestroy(ST* ps);

//压栈
void STPush(ST* ps, STDataType x);

//出栈
void STPop(ST* ps);

//栈大小
int STSize(ST* ps);

//判空
bool STEmpty(ST* ps);

//查看栈顶元素
STDataType STTop(ST* ps);
