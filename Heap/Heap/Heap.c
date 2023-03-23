#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

//初始化
void HeapInit(HP* hp)
{
	assert(hp);

	//最开始开四个位置
	hp->a = (HP*)malloc(sizeof(HPDataType) * 4);
	if (hp->a == NULL)
	{
		perror("malloc::HeapInit");
		exit(-1);
	}

	hp->size = 0;
	hp->capacity = 4;
}

//交换函数（复用）
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType x = *p1;
	*p1 = *p2;
	*p2 = x;
}

//向上调整
void AdjustUp(HPDataType* hp, int child)
{
	//父节点 = (子节点 - 1) / 2
	int parent = (child - 1) / 2;

	//如果到堆顶就不用调整了
	while (child != 0)
	{
		//在大堆，如果子节点大于父节点就向上调整
		if(hp[child] > hp[parent])
		{
			//让子节点的值与父节点的值交换
			Swap(&hp[child], &hp[parent]);

			//让子节点的下标改为父节点下标
			child = parent;

			//更新父节点（变成新子节点的父节点）
			parent = (parent - 1) / 2;
		}
		else
		{
			//如果子节点小于等于父节点就跳出循环
			break;
		}
	}  
}

//插入数据
void HeapPush(HP* hp, HPDataType x)
{
	assert(hp);

	//如果容量满了
	if (hp->size == hp->capacity)
	{
		//扩容两倍
		HP* tmp = (HP*)realloc(hp->a, sizeof(HPDataType) * hp->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc::HeapPush");
			exit(-1);
		}
		hp->a = tmp;
		hp->capacity *= 2;
	}

	//插入数值
	hp->a[hp->size] = x;
	hp->size++;

	//向上调整
	AdjustUp(hp->a, hp->size - 1);
}

//向下调整
void AdjustDown(HPDataType* a, int n, int parent)
{
	//（左孩子）子节点 = 父节点 * 2 + 1   //右孩子是 * 2 + 2
	int child = parent * 2 + 1;

	//子节点需要在堆的范围内
	while (child < n)
	{
		//如果右孩子存在 && 右孩子大于左孩子，就往右孩子那边向下调整
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}

		//如果父节点的值小于子节点，就交换
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);	

			//父节点的下标变成子节点的下标
			parent = child;

			//更新子节点
			child = parent * 2 + 1;
		}
		else
		{
			//如果父节点的值大于等于子节点，就跳出循环
			break;
		}
	}
}

//删除数据
void HeapPop(HP* hp)
{
	assert(hp);
	assert(!HeapEmpty(&hp));//判空

	//头尾交换（堆顶与堆最后的值交换）
	Swap(&hp->a[0], &hp->a[hp->size - 1]);

	//删除（曾经的堆顶）
	hp->size--;

	//向下调整
	AdjustDown(hp->a, hp->size, 0);
}

//取堆顶数据
HPDataType HeapTop(HP* hp)
{
	assert(hp);
	return hp->a[0];
}

//判空
bool HeapEmpty(HP* hp)
{
	assert(hp);
	return hp->size == 0;
}

//取大小
int HeapSize(HP* hp)
{
	assert(hp);
	return hp->size;
}

//销毁
void HeapDestory(HP* hp)
{
	assert(hp);
	free(hp->a);
	hp->a = NULL;
	hp->size = hp->capacity = 0;
}
