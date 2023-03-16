#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define INIT_CAPACITY 4

//选择需要的类型
typedef int SLDatatype;

//动态的顺序表
typedef struct SeqList
{
	SLDatatype* a;
	int size;	  //有效的数据个数
	int capacity; //顺序表的空间容量
}SL;

//顺序表的增删查改:

//初始化顺序表
void SeqInit(SL* s);

//销毁顺序表
void SeqDestory(SL* s);

//打印顺序表
void SeqPrint(SL* s);

//检查容量
void CheckCapacity(SL* s);

//尾插
void SeqPushBack(SL* s, SLDatatype x);

//尾删
void SeqPopBack(SL* s);

//头插
void SeqPushFront(SL* s, SLDatatype x);

//头删
void SeqPopFront(SL* s);

//插入
void SeqInsert(SL* s, int pos, SLDatatype x);

//删除
void SeqErase(SL* s, int pos);


