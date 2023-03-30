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

//��������С
int TreeSize(BTNode* root);

//�������߶�
int TreeHeight(BTNode* root);

//������k���С
int TreeKLevel(BTNode* root, int k);

//����ֵΪx�Ľڵ�
BTNode* TreeFind(BTNode* root, BTDataType x);

//�������Ĳ������
void LevelOrder(BTNode* root);