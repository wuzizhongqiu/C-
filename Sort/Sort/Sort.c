#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"
#include "Stack.h"

//��ӡ
void Print(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

//��������
void InsertSort(int* a, int n) {

	//��������
	for (int i = 1; i < n; i++) {

		//endλ�ñ�ʾҪ���Ƚϵ���
		int end = i - 1;

		//tmp��ŵ������ڽ��в����������
		int tmp = a[i];

		while (end >= 0) {
			//���tmp��endλ�õ���С
			if (tmp < a[end]) { 
				//����endλ�õ�������Ų��
				a[end + 1] = a[end];
				//�ٸ�ǰһ��endλ�õ����Ƚ�
				end--; 
			}
			else {
				//���tmp��endλ�õ������Ǿͱ���
				break; 
			}
		}
		//��֮ǰ��Ϊ����Ų�����ճ���λ�ø�ֵ��tmp
		a[end + 1] = tmp;
	}
}

//ϣ������
void ShellSort(int* a, int n) {

	//��gap��ʼ���������С��֮��������������С��
	int gap = n;

	//��gap == 1��֤���Ѿ�������һ������������
	while (gap > 1) {

		//����/2����gap���ϱ�С����Ԥ�ţ���gap == 1ʱ���в�������
		gap /= 2;

		//����ǽ�gap�ֳɵ�ÿ�����ֽ��в�������Ҳ����Ԥ����
		for (int i = 0; i < gap; i++) {
			for (int j = i; j < n - gap; j += gap) {

				//endλ�ñ�ʾҪ���Ƚϵ���
				int end = j;

				//tmp��ŵ������ڽ��в����������
				int tmp = a[end + gap];

				//��������
				while (end >= 0) {
					//������һ�������������gap��
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

//����
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//���µ���
void AdjustDown(int* a, int n, int parent)
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

//ѡ������//˫ѡ�Ż�
void SelectSort(int* a, int n) {
	int left = 0, right = n - 1;
	while (left < right) {
		//ѡ����С�ĺ���߽��������ĺ��ұ߽���
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
		//�����������±���left��С��leftָ�����������
		if (left == maxi) maxi = mini;
		Swap(&a[right], &a[maxi]);
		left++;
		right--;
	}
}

//������//����Ҳ��һ��ѡ������
void HeapSort(int* a, int n)
{
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

//ð������
void BubbleSort(int* a, int n) {
	//ÿ�ν��������������������
	for (int i = 0; i < n; i++) {
		int flag = 1;
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				Swap(&a[j], &a[j + 1]);
				flag = 0;
			}
		}
		//�Ż������û����������֤����������ֱ������ѭ��
		if (flag) break;
	}
}

//����ȡ��
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

//��������hoare�汾
void QuickSortH(int* a, int left, int right) {
	//�����ǰ������ֻ��һ������ʱ����ݹ飬�����left > right�����
	if (left >= right) return;

	//�����left��right
	int begin = left, end = right;

	////�Ż�����һ //���ѡkey //��ֹ��������
	//int randi = left + (rand() % (right - left));
	//Swap(&a[left], &a[randi]);

	//�Ż������� //����ȡ��
	int midi = GetMidNum(a, left, right);
	Swap(&a[left], &a[midi]);

	//ȡ���Ϊkeyֵ
	int key = left;
	while (left < right) {
		
		//���ұ�ȡС
		while (left < right && a[key] <= a[right])
			right--;

		//���ȡ��
		while (left < right && a[key] >= a[left])
			left++;

		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[right]);

	key = left;//Ҫ����key���±�

	//[begin, key - 1] key [key + 1, end]
	QuickSortH(a, begin, key - 1);
	QuickSortH(a, key + 1, end);
}

//���������ڿӷ�
void QuickSortD(int* a, int left, int right) {
	//�����ǰ������ֻ��һ������ʱ����ݹ飬�����left > right�����
	if (left >= right) return;

	//�����left��right
	int begin = left, end = right;

	////�Ż�����һ //���ѡhole //��ֹ��������
	//int randi = left + (rand() % (right - left));
	//Swap(&a[left], &a[randi]);

	//�Ż������� //����ȡ��
	int midi = GetMidNum(a, left, right);
	Swap(&a[left], &a[midi]);

	//ȡ���Ϊ��
	int hole = left;
	int keys = a[hole];//�ڿ�
	while (left < right) {

		//�ұ���С
		while (left < right && a[right] >= keys) {
			right--;
		}
		a[hole] = a[right];//��ɿ�
		hole = right;//���¿�

		//����Ҵ�
		while (left < right && a[left] <= keys) {
			left++;
		}
		a[hole] = a[left];//��ɿ�
		hole = left;//���¿�
	}
	a[hole] = keys;//���

	//[begin, hole - 1] hole [hole + 1, end]
	QuickSortD(a, begin, hole - 1);
	QuickSortD(a, hole + 1, end);
}

//��������˫ָ�뷨
void QuickSortP(int* a, int left, int right) {
	//�����ǰ������ֻ��һ������ʱ����ݹ飬�����left > right�����
	if (left >= right) return;

	//����ȡ��
	int midi = GetMidNum(a, left, right);
	Swap(&a[left], &a[midi]);
	
	//ǰ��ָ��
	int prev = left, cur = left + 1;

	int key = left;
	while (cur <= right) {

		//�������a[cur] < a[key]����prev�����߲�����
		if (a[cur] < a[key] && ++prev != cur) Swap(&a[cur], &a[prev]);

		//curһֱ������
		cur++;
	}
	Swap(&a[key], &a[prev]);
	key = prev;

	//[begin, key - 1] key [key + 1, end]
	QuickSortP(a, left, key - 1);
	QuickSortP(a, key + 1, right);
}

//�������� //����ר��
void QuickSort(int* a, int left, int right) {
	//�����ǰ������ֻ��һ������ʱ����ݹ飬�����left > right�����
	if (left >= right) return;

	if ((right - left + 1) > 10) {
		//int key = PartQuickSortD(a, left, right);//hoare�汾
		//int key = PartQuickSortH(a, left, right);//�ڿӷ�
		int key = PartQuickSortP(a, left, right);//˫ָ�뷨

		QuickSort(a, left, key - 1);
		QuickSort(a, key + 1, right);
	}
	else { //С�����Ż���С����ֱ��ʹ�ò��ţ����ٵݹ����
		InsertSort(a + left, right - left + 1);
	}
}

//��������hoare�汾 //��������
int PartQuickSortH(int* a, int left, int right) {

	//����ȡ��
	int midi = GetMidNum(a, left, right);
	Swap(&a[left], &a[midi]);

	//ȡ���Ϊkeyֵ
	int key = left;
	while (left < right) {

		//���ұ�ȡС
		while (left < right && a[key] <= a[right])
			right--;

		//���ȡ��
		while (left < right && a[key] >= a[left])
			left++;

		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[right]);

	key = left;//Ҫ����key���±�

	return key;
}

//���������ڿӷ� //��������
int PartQuickSortD(int* a, int left, int right) {

	//����ȡ��
	int midi = GetMidNum(a, left, right);
	Swap(&a[left], &a[midi]);

	//ȡ���Ϊ��
	int hole = left;
	int keys = a[hole];//�ڿ�
	while (left < right) {

		//�ұ���С
		while (left < right && a[right] >= keys) {
			right--;
		}
		a[hole] = a[right];//��ɿ�
		hole = right;//���¿�

		//����Ҵ�
		while (left < right && a[left] <= keys) {
			left++;
		}
		a[hole] = a[left];//��ɿ�
		hole = left;//���¿�
	}
	a[hole] = keys;//��� 

	return hole;
}

//��������˫ָ���Ż��� //��������
int PartQuickSortP(int* a, int left, int right) {

	//����ȡ��
	int midi = GetMidNum(a, left, right);
	Swap(&a[left], &a[midi]);

	//ǰ��ָ��
	int prev = left, cur = left + 1;

	int key = left;
	while (cur <= right) {

		//�������a[cur] < a[key]����prev�����߲�����
		if (a[cur] < a[key] && ++prev != cur) Swap(&a[cur], &a[prev]);

		//curһֱ������
		cur++;
	}
	Swap(&a[key], &a[prev]);
	key = prev;
	
	return key;
}

//���ŵķǵݹ�ʵ��
void QuickSortNoR(int* a, int left, int right) {
	ST st;
	STInit(&st);

	//��������ջ������ȳ���
	STPush(&st, right);
	STPush(&st, left);

	//�ǵݹ�ʵ��
	while (!STEmpty(&st)) {

		//ȡ��һ������
		int begin = STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st);

		//��������keyֵ�����е�������
		int key = PartQuickSortP(a, begin, end);
		//[begin, key - 1] key [key + 1, end]

		//˼���ǣ���� key + 1 < end ֤��������1������0����
		//�������ڵ������ڵ���2���ͽ�������ջ
		if (key + 1 < end) {
			STPush(&st, end);
			STPush(&st, key + 1);
		}

		//�������ڵ������ڵ���2���ͽ�������ջ
		if (begin < key - 1) {
			STPush(&st, key - 1);
			STPush(&st, begin);
		}
	}
	STDestroy(&st);
}

//�鲢�Ӻ���
void _MergeSort(int* a, int* tmp, int begin, int end) {

	//�鲢���������ˣ��ͷ���
	if (begin >= end) return;

	//��������
	int mid = (begin + end) >> 1;
	_MergeSort(a, tmp, begin, mid);
	_MergeSort(a, tmp, mid + 1, end);
	
	//�����ֳ���������
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;

	//tmp���±�
	int i = begin;

	//��������Ƚϣ�Ȼ��β�嵽tmp����
	while (begin1 <= end1 && begin2 <= end2) {
		if (a[begin1] < a[begin2]) {
			tmp[i++] = a[begin1++];
		}
		else {
			tmp[i++] = a[begin2++];
		}
	}

	//û����������飬ȫ��β�嵽tmp
	while (begin1 <= end1) tmp[i++] = a[begin1++];
	while (begin2 <= end2) tmp[i++] = a[begin2++];

	//������õ�tmp��������ݿ�����a��������
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

//�鲢����
void MergeSort(int* a, int n) {

	//����һ����ʱ����
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL) {
		perror("MergeSort::malloc");
		exit(-1);
	}

	//�ݹ�����Ӻ������������Լ�����ֹ�������ռ䣩
	_MergeSort(a, tmp, 0, n - 1);

	//�ǵ��ͷſ��ٵĿռ�
	free(tmp);
}

//�鲢�ķǵݹ�
void MergeSortNoR(int* a, int n) {

	//����һ����ʱ����
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL) {
		perror("MergeSort::malloc");
		exit(-1);
	}

	int gap = 1;
	while (gap < n) {

		for (int j = 0; j < n; j += gap * 2) {

			//�����ֳ���������
			int begin1 = j, end1 = j + gap - 1;
			int begin2 = j + gap, end2 = j + gap * 2 - 1;

			//����Խ��
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

			//tmp���±�
			int i = j;

			//��������Ƚϣ�Ȼ��β�嵽tmp����
			while (begin1 <= end1 && begin2 <= end2) {
				if (a[begin1] < a[begin2]) {
					tmp[i++] = a[begin1++];
				}
				else {
					tmp[i++] = a[begin2++];
				}
			}

			//û����������飬ȫ��β�嵽tmp
			while (begin1 <= end1) tmp[i++] = a[begin1++];
			while (begin2 <= end2) tmp[i++] = a[begin2++];
		} 

		//������õ�tmp��������ݿ�����a��������
		memcpy(a, tmp, sizeof(int) * n);

		gap *= 2;
	}

	//�ǵ��ͷſ��ٵĿռ�
	free(tmp);
}


//��������
void CountSort(int* a, int n) {

	//ȡ�������Сֵ
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
		if (a[i] < min) {
			min = a[i];
		}
	}

	//����һ����������countA
	int range = max - min + 1;
	int* countA = (int*)malloc(sizeof(int) * range);
	if (countA == NULL) {
		perror("Count::malloc::fail");
		exit(-1);
	}
	memset(countA, 0, sizeof(int) * range);

	//����
	for (int i = 0; i < n; i++) {
		countA[a[i] - min]++;
	}

	//����
	int j = 0;
	for (int i = 0; i < range; i++) {
		while (countA[i]--) {
			a[j++] = i + min;
		}
	}

	//�ǵ�Ҫfree�����ٵĿռ�
	free(countA);
}