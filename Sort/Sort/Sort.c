#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"
#include "Stack.h"

//打印
void Print(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

//插入排序
void InsertSort(int* a, int n) {

	//遍历数组
	for (int i = 1; i < n; i++) {

		//end位置表示要被比较的数
		int end = i - 1;

		//tmp存放的是正在进行插入排序的数
		int tmp = a[i];

		while (end >= 0) {
			//如果tmp比end位置的数小
			if (tmp < a[end]) { 
				//就让end位置的数往后挪动
				a[end + 1] = a[end];
				//再跟前一个end位置的数比较
				end--; 
			}
			else {
				//如果tmp比end位置的数大，那就别动了
				break; 
			}
		}
		//将之前因为往后挪动而空出的位置赋值成tmp
		a[end + 1] = tmp;
	}
}

//希尔排序
void ShellSort(int* a, int n) {

	//将gap初始化成数组大小（之后再慢慢让它变小）
	int gap = n;

	//当gap == 1，证明已经完成最后一步：插入排序
	while (gap > 1) {

		//不断/2，让gap不断变小进行预排，当gap == 1时进行插入排序
		gap /= 2;

		//这个是将gap分成的每个部分进行插入排序，也就是预排序
		for (int i = 0; i < gap; i++) {
			for (int j = i; j < n - gap; j += gap) {

				//end位置表示要被比较的数
				int end = j;

				//tmp存放的是正在进行插入排序的数
				int tmp = a[end + gap];

				//插入排序
				while (end >= 0) {
					//从跳过一个数，变成跳过gap个
					if (tmp < a[end]) {
						a[end + gap] = a[end];
						end -= gap;
					}
					else {
						break;
					}
				}
				a[end + gap] = tmp;
			}
		}
	}
}

//交换
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//向下调整
void AdjustDown(int* a, int n, int parent)
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

//选择排序//双选优化
void SelectSort(int* a, int n) {
	int left = 0, right = n - 1;
	while (left < right) {
		//选出最小的和左边交换，最大的和右边交换
		int mini = left, maxi = left;
		for (int i = left; i <= right; i++) {
			if (a[i] < a[mini]) {
				mini = i;
			}
			if (a[i] > a[maxi]) {
				maxi = i;
			}
		}
		Swap(&a[left], &a[mini]);
		//如果最大数的下标是left，小心left指向的数被换走
		if (left == maxi) maxi = mini;
		Swap(&a[right], &a[maxi]);
		left++;
		right--;
	}
}

//堆排序//堆排也是一种选择排序
void HeapSort(int* a, int n)
{
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

//冒泡排序
void BubbleSort(int* a, int n) {
	//每次将最大的数交换到数组最后
	for (int i = 0; i < n; i++) {
		int flag = 1;
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				Swap(&a[j], &a[j + 1]);
				flag = 0;
			}
		}
		//优化：如果没发生交换，证明数组有序，直接跳出循环
		if (flag) break;
	}
}

//三数取中
int GetMidNum(int* a, int left, int right) {
	int mid = (left + right) / 2;
	if (a[left] < a[mid]) {
		if (a[right] > a[mid]) return mid;
		else if (a[left] < a[right]) return right;
		else return left;
	}
	else { //a[left] > a[mid]
		if (a[right] < a[mid]) return mid;
		else if (a[left] > a[right]) return right;
		else return left; 
	}
}

//快速排序hoare版本
void QuickSortH(int* a, int left, int right) {
	//如果当前数组在只有一个数的时候进递归，会出现left > right的情况
	if (left >= right) return;

	//保存好left和right
	int begin = left, end = right;

	////优化方法一 //随机选key //防止有序的情况
	//int randi = left + (rand() % (right - left));
	//Swap(&a[left], &a[randi]);

	//优化方法二 //三数取中
	int midi = GetMidNum(a, left, right);
	Swap(&a[left], &a[midi]);

	//取左边为key值
	int key = left;
	while (left < right) {
		
		//先右边取小
		while (left < right && a[key] <= a[right])
			right--;

		//左边取大
		while (left < right && a[key] >= a[left])
			left++;

		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[right]);

	key = left;//要更新key的下标

	//[begin, key - 1] key [key + 1, end]
	QuickSortH(a, begin, key - 1);
	QuickSortH(a, key + 1, end);
}

//快速排序挖坑法
void QuickSortD(int* a, int left, int right) {
	//如果当前数组在只有一个数的时候进递归，会出现left > right的情况
	if (left >= right) return;

	//保存好left和right
	int begin = left, end = right;

	////优化方法一 //随机选hole //防止有序的情况
	//int randi = left + (rand() % (right - left));
	//Swap(&a[left], &a[randi]);

	//优化方法二 //三数取中
	int midi = GetMidNum(a, left, right);
	Swap(&a[left], &a[midi]);

	//取左边为坑
	int hole = left;
	int keys = a[hole];//挖坑
	while (left < right) {

		//右边找小
		while (left < right && a[right] >= keys) {
			right--;
		}
		a[hole] = a[right];//填旧坑
		hole = right;//换新坑

		//左边找大
		while (left < right && a[left] <= keys) {
			left++;
		}
		a[hole] = a[left];//填旧坑
		hole = left;//换新坑
	}
	a[hole] = keys;//填坑

	//[begin, hole - 1] hole [hole + 1, end]
	QuickSortD(a, begin, hole - 1);
	QuickSortD(a, hole + 1, end);
}

//快速排序双指针法
void QuickSortP(int* a, int left, int right) {
	//如果当前数组在只有一个数的时候进递归，会出现left > right的情况
	if (left >= right) return;

	//三数取中
	int midi = GetMidNum(a, left, right);
	Swap(&a[left], &a[midi]);
	
	//前后指针
	int prev = left, cur = left + 1;

	int key = left;
	while (cur <= right) {

		//如果遇到a[cur] < a[key]，让prev往后走并交换
		if (a[cur] < a[key] && ++prev != cur) Swap(&a[cur], &a[prev]);

		//cur一直往后走
		cur++;
	}
	Swap(&a[key], &a[prev]);
	key = prev;

	//[begin, key - 1] key [key + 1, end]
	QuickSortP(a, left, key - 1);
	QuickSortP(a, key + 1, right);
}

//快速排序 //测试专用
void QuickSort(int* a, int left, int right) {
	//如果当前数组在只有一个数的时候进递归，会出现left > right的情况
	if (left >= right) return;

	if ((right - left + 1) > 10) {
		//int key = PartQuickSortD(a, left, right);//hoare版本
		//int key = PartQuickSortH(a, left, right);//挖坑法
		int key = PartQuickSortP(a, left, right);//双指针法

		QuickSort(a, left, key - 1);
		QuickSort(a, key + 1, right);
	}
	else { //小区间优化，小区间直接使用插排，减少递归层数
		InsertSort(a + left, right - left + 1);
	}
}

//快速排序hoare版本 //单趟排序
int PartQuickSortH(int* a, int left, int right) {

	//三数取中
	int midi = GetMidNum(a, left, right);
	Swap(&a[left], &a[midi]);

	//取左边为key值
	int key = left;
	while (left < right) {

		//先右边取小
		while (left < right && a[key] <= a[right])
			right--;

		//左边取大
		while (left < right && a[key] >= a[left])
			left++;

		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[right]);

	key = left;//要更新key的下标

	return key;
}

//快速排序挖坑法 //单趟排序
int PartQuickSortD(int* a, int left, int right) {

	//三数取中
	int midi = GetMidNum(a, left, right);
	Swap(&a[left], &a[midi]);

	//取左边为坑
	int hole = left;
	int keys = a[hole];//挖坑
	while (left < right) {

		//右边找小
		while (left < right && a[right] >= keys) {
			right--;
		}
		a[hole] = a[right];//填旧坑
		hole = right;//换新坑

		//左边找大
		while (left < right && a[left] <= keys) {
			left++;
		}
		a[hole] = a[left];//填旧坑
		hole = left;//换新坑
	}
	a[hole] = keys;//填坑 

	return hole;
}

//快速排序双指针优化版 //单趟排序
int PartQuickSortP(int* a, int left, int right) {

	//三数取中
	int midi = GetMidNum(a, left, right);
	Swap(&a[left], &a[midi]);

	//前后指针
	int prev = left, cur = left + 1;

	int key = left;
	while (cur <= right) {

		//如果遇到a[cur] < a[key]，让prev往后走并交换
		if (a[cur] < a[key] && ++prev != cur) Swap(&a[cur], &a[prev]);

		//cur一直往后走
		cur++;
	}
	Swap(&a[key], &a[prev]);
	key = prev;
	
	return key;
}

//快排的非递归实现
void QuickSortNoR(int* a, int left, int right) {
	ST st;
	STInit(&st);

	//让区间入栈（后进先出）
	STPush(&st, right);
	STPush(&st, left);

	//非递归实现
	while (!STEmpty(&st)) {

		//取出一个区间
		int begin = STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st);

		//计算他的key值（进行单趟排序）
		int key = PartQuickSortP(a, begin, end);
		//[begin, key - 1] key [key + 1, end]

		//思想是：如果 key + 1 < end 证明区间有1个或者0个数
		//右区间内的数大于等于2，就将区间入栈
		if (key + 1 < end) {
			STPush(&st, end);
			STPush(&st, key + 1);
		}

		//左区间内的数大于等于2，就将区间入栈
		if (begin < key - 1) {
			STPush(&st, key - 1);
			STPush(&st, begin);
		}
	}
	STDestroy(&st);
}

//归并子函数
void _MergeSort(int* a, int* tmp, int begin, int end) {

	//归并完子区间了，就返回
	if (begin >= end) return;

	//分治排序
	int mid = (begin + end) >> 1;
	_MergeSort(a, tmp, begin, mid);
	_MergeSort(a, tmp, mid + 1, end);
	
	//两个分出来的数组
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;

	//tmp的下标
	int i = begin;

	//两个数组比较，然后尾插到tmp数组
	while (begin1 <= end1 && begin2 <= end2) {
		if (a[begin1] < a[begin2]) {
			tmp[i++] = a[begin1++];
		}
		else {
			tmp[i++] = a[begin2++];
		}
	}

	//没有用完的数组，全部尾插到tmp
	while (begin1 <= end1) tmp[i++] = a[begin1++];
	while (begin2 <= end2) tmp[i++] = a[begin2++];

	//将排序好的tmp数组的内容拷贝到a数组里面
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

//归并排序
void MergeSort(int* a, int n) {

	//开辟一个临时数组
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL) {
		perror("MergeSort::malloc");
		exit(-1);
	}

	//递归调用子函数（不调用自己，防止多次申请空间）
	_MergeSort(a, tmp, 0, n - 1);

	//记得释放开辟的空间
	free(tmp);
}

//归并的非递归
void MergeSortNoR(int* a, int n) {

	//开辟一个临时数组
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL) {
		perror("MergeSort::malloc");
		exit(-1);
	}

	int gap = 1;
	while (gap < n) {

		for (int j = 0; j < n; j += gap * 2) {

			//两个分出来的数组
			int begin1 = j, end1 = j + gap - 1;
			int begin2 = j + gap, end2 = j + gap * 2 - 1;

			//修正越界
			if (end1 >= n) {
				end1 = n - 1;
				begin2 = n;
				end2 = n - 1;
			}
			else if (begin2 >= n) {
				begin2 = n;
				end2 = n - 1;
			}
			else if(end2 >= n) {
				end2 = n - 1;
			}

			//tmp的下标
			int i = j;

			//两个数组比较，然后尾插到tmp数组
			while (begin1 <= end1 && begin2 <= end2) {
				if (a[begin1] < a[begin2]) {
					tmp[i++] = a[begin1++];
				}
				else {
					tmp[i++] = a[begin2++];
				}
			}

			//没有用完的数组，全部尾插到tmp
			while (begin1 <= end1) tmp[i++] = a[begin1++];
			while (begin2 <= end2) tmp[i++] = a[begin2++];
		} 

		//将排序好的tmp数组的内容拷贝到a数组里面
		memcpy(a, tmp, sizeof(int) * n);

		gap *= 2;
	}

	//记得释放开辟的空间
	free(tmp);
}


//计数排序
void CountSort(int* a, int n) {

	//取出最大最小值
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
		if (a[i] < min) {
			min = a[i];
		}
	}

	//创建一个计数数组countA
	int range = max - min + 1;
	int* countA = (int*)malloc(sizeof(int) * range);
	if (countA == NULL) {
		perror("Count::malloc::fail");
		exit(-1);
	}
	memset(countA, 0, sizeof(int) * range);

	//计数
	for (int i = 0; i < n; i++) {
		countA[a[i] - min]++;
	}

	//排序
	int j = 0;
	for (int i = 0; i < range; i++) {
		while (countA[i]--) {
			a[j++] = i + min;
		}
	}

	//记得要free掉开辟的空间
	free(countA);
}