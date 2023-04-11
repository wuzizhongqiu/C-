#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

//≤‚ ‘
void test() {

	int a[] = { 4, 3, 9, 6, 8, 0, 7, 2, 1, 5 ,3,3,3,3,3,3,3 };
	//int a[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	//int a[] = { 2, 1};

	int size = sizeof(a) / sizeof(int);

	CountSort(a, size);

	Print(a, size);
}

int main() {
	test();
	return 0;
}