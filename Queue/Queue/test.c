#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

void test()
{
	Queue q;
	QueueInit(&q);

	QueuePrint(&q);
	QueueDestroy(&q);
}

int main()
{
	test();
	return  0;
}
