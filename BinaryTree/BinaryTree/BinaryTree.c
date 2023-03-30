#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree.h"
#include "Queue.h" 


//�����������ڵ�
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

//��һ��������
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

//������ǰ�����
void PreOrder(BTNode* root)
{
	if (root == NULL) return;

	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

//�������������
void InOrder(BTNode* root)
{
	if (root == NULL) return;

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

//�������������
void PostOrder(BTNode* root)
{
	if (root == NULL) return;

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

//��������С
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

//�������߶�
int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	int l = TreeHeight(root->left);
	int r = TreeHeight(root->right);

	return l > r ? l + 1 : r + 1;
}

//������k���С
int TreeKLevel(BTNode* root, int k)
{
	assert(k > 0);

	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return TreeKLevel(root->left, k - 1) + TreeKLevel(root->right, k - 1);
}

//����ֵΪx�Ľڵ�
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

//�������Ĳ������
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
