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


//创建二叉树节点
BTNode* BuyNode(BTDataType x);

//建一个二叉树
BTNode* CreatTree();

//二叉树前序遍历
void PreOrder(BTNode* root);

//二叉树中序遍历
void InOrder(BTNode* root);


//二叉树后序遍历
void PostOrder(BTNode* root);

//二叉树大小
int TreeSize(BTNode* root);

//二叉树高度
int TreeHeight(BTNode* root);

//二叉树k层大小
int TreeKLevel(BTNode* root, int k);

//查找值为x的节点
BTNode* TreeFind(BTNode* root, BTDataType x);

//二叉树的层序遍历
void LevelOrder(BTNode* root);