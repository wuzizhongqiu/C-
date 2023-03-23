#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void test()
{
	HP hp;
	HeapInit(&hp);

	HeapDestory(&hp);
}

void print(int* a)
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
}

//������ʱ�临�Ӷ� O(N * logN) ������
void HeapSort(int* a, int n)
{
	////���ϵ����������
	//for (int i = 1; i < n; i++)
	//{
	//	AdjustUp(a, i);
	//}

	//���µ�������
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	//ͷβ������Ȼ�����µ��������µ������������������Ǵ�ѣ�
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[end], &a[0]);
		AdjustDown(a, end, 0);
		end--;
	}
} 

int main()
{
	//test();//���ڲ���

	int a[10] = { 2, 8, 3, 7, 5, 4, 1, 9, 10, 6 };

	HeapSort(a, 10);

	print(a);

	return 0;
}



