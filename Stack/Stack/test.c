#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void test_stack()
{
	ST st;
	STInit(&st);

	STDestroy(&st);
}

int main()
{
	test_stack();
	return 0;
}