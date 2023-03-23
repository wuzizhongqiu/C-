#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;//用数组的形式实现堆
	int size;
	int capacity;
}HP;

//初始化
void HeapInit(HP* hp);

//销毁
void HeapDestory(HP* hp);

//插入数据
void HeapPush(HP* hp, HPDataType x);

//删除数据
void HeapPop(HP* hp);

//取堆顶数据
HPDataType HeapTop(HP* hp);

//判空
bool HeapEmpty(HP* hp);

//取大小
int HeapSize(HP* hp);

//向上调整
void AdjustUp(HPDataType* hp, int child);

//向下调整
void AdjustDown(HPDataType* a, int n, int parent);

//交换函数（复用）
void Swap(HPDataType* p1, HPDataType* p2);