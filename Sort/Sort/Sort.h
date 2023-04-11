#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//打印
void Print(int* a, int n);

//八大经典排序：

//插入排序思想：
//1.插入排序
void InsertSort(int* a, int n);

//2.希尔排序
void ShellSort(int* a, int n);

//选择排序思想：
//3.选择排序
void SelectSort(int* a, int n);

//4.堆排序
void HeapSort(int* a, int n);

//交换排序思想：
//5.冒泡排序
void BubbleSort(int* a, int n);

//6.快速排序hoare版本
void QuickSortH(int* a, int left, int right);

//快速排序挖坑法
void QuickSortD(int* a, int left, int right);

//快速排序双指针法
void QuickSortP(int* a, int left, int right);

//快速排序hoare版本 //单趟排序
int PartQuickSortH(int* a, int left, int right);

//快速排序挖坑法 //单趟排序
int PartQuickSortD(int* a, int left, int right);

//快速排序双指针优化版 //单趟排序
int PartQuickSortP(int* a, int left, int right);

//快速排序 //测试专用
void QuickSort(int* a, int left, int right);

//快排的非递归实现
void QuickSortNoR(int* a, int left, int right);

//7.归并排序
void MergeSort(int* a, int n);

//归并的非递归实现
void MergeSortNoR(int* a, int n);

//非比较排序
//8.计数排序
void CountSort(int* a, int n);