#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

//��ʼ��
void HeapInit(HP* hp)
{
	assert(hp);

	//�ʼ���ĸ�λ��
	hp->a = (HP*)malloc(sizeof(HPDataType) * 4);
	if (hp->a == NULL)
	{
		perror("malloc::HeapInit");
		exit(-1);
	}

	hp->size = 0;
	hp->capacity = 4;
}

//�������������ã�
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType x = *p1;
	*p1 = *p2;
	*p2 = x;
}

//���ϵ���
void AdjustUp(HPDataType* hp, int child)
{
	//���ڵ� = (�ӽڵ� - 1) / 2
	int parent = (child - 1) / 2;

	//������Ѷ��Ͳ��õ�����
	while (child != 0)
	{
		//�ڴ�ѣ�����ӽڵ���ڸ��ڵ�����ϵ���
		if(hp[child] > hp[parent])
		{
			//���ӽڵ��ֵ�븸�ڵ��ֵ����
			Swap(&hp[child], &hp[parent]);

			//���ӽڵ���±��Ϊ���ڵ��±�
			child = parent;

			//���¸��ڵ㣨������ӽڵ�ĸ��ڵ㣩
			parent = (parent - 1) / 2;
		}
		else
		{
			//����ӽڵ�С�ڵ��ڸ��ڵ������ѭ��
			break;
		}
	}  
}

//��������
void HeapPush(HP* hp, HPDataType x)
{
	assert(hp);

	//�����������
	if (hp->size == hp->capacity)
	{
		//��������
		HP* tmp = (HP*)realloc(hp->a, sizeof(HPDataType) * hp->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc::HeapPush");
			exit(-1);
		}
		hp->a = tmp;
		hp->capacity *= 2;
	}

	//������ֵ
	hp->a[hp->size] = x;
	hp->size++;

	//���ϵ���
	AdjustUp(hp->a, hp->size - 1);
}

//���µ���
void AdjustDown(HPDataType* a, int n, int parent)
{
	//�����ӣ��ӽڵ� = ���ڵ� * 2 + 1   //�Һ����� * 2 + 2
	int child = parent * 2 + 1;

	//�ӽڵ���Ҫ�ڶѵķ�Χ��
	while (child < n)
	{
		//����Һ��Ӵ��� && �Һ��Ӵ������ӣ������Һ����Ǳ����µ���
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}

		//������ڵ��ֵС���ӽڵ㣬�ͽ���
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);	

			//���ڵ���±����ӽڵ���±�
			parent = child;

			//�����ӽڵ�
			child = parent * 2 + 1;
		}
		else
		{
			//������ڵ��ֵ���ڵ����ӽڵ㣬������ѭ��
			break;
		}
	}
}

//ɾ������
void HeapPop(HP* hp)
{
	assert(hp);
	assert(!HeapEmpty(&hp));//�п�

	//ͷβ�������Ѷ��������ֵ������
	Swap(&hp->a[0], &hp->a[hp->size - 1]);

	//ɾ���������ĶѶ���
	hp->size--;

	//���µ���
	AdjustDown(hp->a, hp->size, 0);
}

//ȡ�Ѷ�����
HPDataType HeapTop(HP* hp)
{
	assert(hp);
	return hp->a[0];
}

//�п�
bool HeapEmpty(HP* hp)
{
	assert(hp);
	return hp->size == 0;
}

//ȡ��С
int HeapSize(HP* hp)
{
	assert(hp);
	return hp->size;
}

//����
void HeapDestory(HP* hp)
{
	assert(hp);
	free(hp->a);
	hp->a = NULL;
	hp->size = hp->capacity = 0;
}
