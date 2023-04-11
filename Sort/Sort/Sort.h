#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//��ӡ
void Print(int* a, int n);

//�˴󾭵�����

//��������˼�룺
//1.��������
void InsertSort(int* a, int n);

//2.ϣ������
void ShellSort(int* a, int n);

//ѡ������˼�룺
//3.ѡ������
void SelectSort(int* a, int n);

//4.������
void HeapSort(int* a, int n);

//��������˼�룺
//5.ð������
void BubbleSort(int* a, int n);

//6.��������hoare�汾
void QuickSortH(int* a, int left, int right);

//���������ڿӷ�
void QuickSortD(int* a, int left, int right);

//��������˫ָ�뷨
void QuickSortP(int* a, int left, int right);

//��������hoare�汾 //��������
int PartQuickSortH(int* a, int left, int right);

//���������ڿӷ� //��������
int PartQuickSortD(int* a, int left, int right);

//��������˫ָ���Ż��� //��������
int PartQuickSortP(int* a, int left, int right);

//�������� //����ר��
void QuickSort(int* a, int left, int right);

//���ŵķǵݹ�ʵ��
void QuickSortNoR(int* a, int left, int right);

//7.�鲢����
void MergeSort(int* a, int n);

//�鲢�ķǵݹ�ʵ��
void MergeSortNoR(int* a, int n);

//�ǱȽ�����
//8.��������
void CountSort(int* a, int n);