#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree.h"
#include "Queue.h" 


//创建二叉树节点
BTNode* BuyNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc::fail");
		exit(-1);
	}

	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

//建一个二叉树
BTNode* CreatTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);


	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node3->right = node7;

	return node1;
}

//二叉树前序遍历
void PreOrder(BTNode* root)
{
	if (root == NULL) return;

	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

//二叉树中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL) return;

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

//二叉树后序遍历
void PostOrder(BTNode* root)
{
	if (root == NULL) return;

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

//二叉树大小
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

//二叉树高度
int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	int l = TreeHeight(root->left);
	int r = TreeHeight(root->right);

	return l > r ? l + 1 : r + 1;
}

//二叉树k层大小
int TreeKLevel(BTNode* root, int k)
{
	assert(k > 0);

	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return TreeKLevel(root->left, k - 1) + TreeKLevel(root->right, k - 1);
}

//查找值为x的节点
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	
	if (root->data == x)
		return root;

	BTNode* l = TreeFind(root->left, x);
	if (l) return l;
	BTNode* r = TreeFind(root->right, x);
	if (r) return r;

	return NULL;
}

//二叉树的层序遍历
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root) QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%d ", front->data);

		if (front->left) QueuePush(&q, front->left);
		if (front->right) QueuePush(&q, front->right);
	}


	QueueDestroy(&q);
}
