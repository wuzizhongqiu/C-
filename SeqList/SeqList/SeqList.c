#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

//初始化顺序表
void SeqInit(SL* ps)
{
	//结构体指针不能为空
	assert(ps);

	//开辟空间
	ps->a = (SLDatatype*)malloc(sizeof(SLDatatype) * INIT_CAPACITY);

	//检查
	if (ps->a == NULL)
	{
		perror("malloc fail");
	}
	ps->size = 0;
	ps->capacity = INIT_CAPACITY;
}

//销毁顺序表
void SeqDestory(SL* ps)
{
	//结构体指针不能为空
	assert(ps);

	//释放并置空
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

//打印
void SeqPrint(SL* ps)
{
	//结构体指针不能为空
	assert(ps);

	//遍历打印
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//检查容量
void CheckCapacity(SL* ps)
{
	//结构体指针不能为空
	assert(ps);

	if (ps->size == ps->capacity)
	{
		//增容（两倍）
		SLDatatype* tmp = (SLDatatype*)realloc(ps->a, sizeof(SLDatatype) * ps->capacity * 2);

		//检查是否增容成功
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
}

//尾插
void SeqPushBack(SL* ps, SLDatatype x)
{
	//代码复用
	SeqInsert(ps, ps->size, x);

	/*单独实现

	//结构体指针不能为空
	assert(ps);

	//检查容量
	CheckCapacity(ps);

	//尾插
	ps->a[ps->size++] = x;
	*/
}

//尾删
void SeqPopBack(SL* ps)
{
	//代码复用
	SeqErase(ps, ps->size - 1);

	/*单独实现
	*
	//结构体指针不能为空
	assert(ps);

	//检查顺序表是否为空
	assert(ps->size);

	//尾删
	ps->size--;
	*/
}

//头插
void SeqPushFront(SL* ps, SLDatatype x)
{
	//代码复用
	SeqInsert(ps, 0, x);

	/*单独实现

	//结构体指针不能为空
	assert(ps);

	//检查容量
	CheckCapacity(ps);

	//把值往后挪
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}

	//头插
	ps->a[0] = x;
	ps->size++;
	*/
}

//头删
void SeqPopFront(SL* ps)
{
	//代码复用
	SeqErase(ps, 0);

	/*单独实现

	//结构体指针不能为空
	assert(ps);

	//当顺序表为零时就不能删了
	assert(ps->size);

	//将数据往前覆盖
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
	*/
}

//插入
void SeqInsert(SL* ps, int pos, SLDatatype x)
{
	//结构体指针不能为空
	assert(ps);

	//pos需要在有数据的区间
	assert(pos >= 0 && pos <= ps->size);

	//检查容量
	CheckCapacity(ps);

	//往后挪动数据
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}

	//插入数据
	ps->a[pos] = x;
	ps->size++;
}

//删除
void SeqErase(SL* ps, int pos)
{
	//结构体指针不能为空
	assert(ps);

	//pos需要在有数据的区间
	assert(pos >= 0 && pos < ps->size);

	//挪动数据
	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}



