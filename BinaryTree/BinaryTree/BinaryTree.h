#pragma once

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;


//�����������ڵ�
BTNode* BuyNode(BTDataType x);

//��һ��������
BTNode* CreatTree();

//������ǰ�����
void PreOrder(BTNode* root);

//�������������
void InOrder(BTNode* root);


//�������������
void PostOrder(BTNode* root);


