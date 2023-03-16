#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

//��ʼ��˳���
void SeqInit(SL* ps)
{
	//�ṹ��ָ�벻��Ϊ��
	assert(ps);

	//���ٿռ�
	ps->a = (SLDatatype*)malloc(sizeof(SLDatatype) * INIT_CAPACITY);

	//���
	if (ps->a == NULL)
	{
		perror("malloc fail");
	}
	ps->size = 0;
	ps->capacity = INIT_CAPACITY;
}

//����˳���
void SeqDestory(SL* ps)
{
	//�ṹ��ָ�벻��Ϊ��
	assert(ps);

	//�ͷŲ��ÿ�
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

//��ӡ
void SeqPrint(SL* ps)
{
	//�ṹ��ָ�벻��Ϊ��
	assert(ps);

	//������ӡ
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//�������
void CheckCapacity(SL* ps)
{
	//�ṹ��ָ�벻��Ϊ��
	assert(ps);

	if (ps->size == ps->capacity)
	{
		//���ݣ�������
		SLDatatype* tmp = (SLDatatype*)realloc(ps->a, sizeof(SLDatatype) * ps->capacity * 2);

		//����Ƿ����ݳɹ�
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
}

//β��
void SeqPushBack(SL* ps, SLDatatype x)
{
	//���븴��
	SeqInsert(ps, ps->size, x);

	/*����ʵ��

	//�ṹ��ָ�벻��Ϊ��
	assert(ps);

	//�������
	CheckCapacity(ps);

	//β��
	ps->a[ps->size++] = x;
	*/
}

//βɾ
void SeqPopBack(SL* ps)
{
	//���븴��
	SeqErase(ps, ps->size - 1);

	/*����ʵ��
	*
	//�ṹ��ָ�벻��Ϊ��
	assert(ps);

	//���˳����Ƿ�Ϊ��
	assert(ps->size);

	//βɾ
	ps->size--;
	*/
}

//ͷ��
void SeqPushFront(SL* ps, SLDatatype x)
{
	//���븴��
	SeqInsert(ps, 0, x);

	/*����ʵ��

	//�ṹ��ָ�벻��Ϊ��
	assert(ps);

	//�������
	CheckCapacity(ps);

	//��ֵ����Ų
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}

	//ͷ��
	ps->a[0] = x;
	ps->size++;
	*/
}

//ͷɾ
void SeqPopFront(SL* ps)
{
	//���븴��
	SeqErase(ps, 0);

	/*����ʵ��

	//�ṹ��ָ�벻��Ϊ��
	assert(ps);

	//��˳���Ϊ��ʱ�Ͳ���ɾ��
	assert(ps->size);

	//��������ǰ����
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
	*/
}

//����
void SeqInsert(SL* ps, int pos, SLDatatype x)
{
	//�ṹ��ָ�벻��Ϊ��
	assert(ps);

	//pos��Ҫ�������ݵ�����
	assert(pos >= 0 && pos <= ps->size);

	//�������
	CheckCapacity(ps);

	//����Ų������
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}

	//��������
	ps->a[pos] = x;
	ps->size++;
}

//ɾ��
void SeqErase(SL* ps, int pos)
{
	//�ṹ��ָ�벻��Ϊ��
	assert(ps);

	//pos��Ҫ�������ݵ�����
	assert(pos >= 0 && pos < ps->size);

	//Ų������
	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}



