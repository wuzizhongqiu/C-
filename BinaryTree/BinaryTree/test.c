#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree.h"

void test()
{
	BTNode* root = CreatTree();

	PreOrder(root);
	printf("\n");

	InOrder(root);
	printf("\n");

	PostOrder(root);
	printf("\n");
}

int main()
{
	test();
	return 0;
}