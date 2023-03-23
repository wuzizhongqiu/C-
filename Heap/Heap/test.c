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

//堆排序：时间复杂度 O(N * logN) 的排序
void HeapSort(int* a, int n)
{
	////向上调整建个大堆
	//for (int i = 1; i < n; i++)
	//{
	//	AdjustUp(a, i);
	//}

	//向下调整建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	//头尾交换，然后向下调整（向下调整的左右子树必须是大堆）
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
	//test();//用于测试

	int a[10] = { 2, 8, 3, 7, 5, 4, 1, 9, 10, 6 };

	HeapSort(a, 10);

	print(a);

	return 0;
}



