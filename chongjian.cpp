#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <iostream>
using namespace std;

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;

	BinaryTreeNode(int n = 0)
		:value(n)
		, pLeft(NULL)
		, pRight(NULL)
	{}
};

BinaryTreeNode* ConstructCore
(int* startPreOder, int* endPreOrder,
int* startInOrder, int* endInOrder);

BinaryTreeNode* Construct(int* preOrder, int* inOrder, int length)
{
	if (preOrder == NULL || inOrder == NULL || length <= 0)
	{
		return NULL;
	}

	return ConstructCore(preOrder, preOrder + length - 1, inOrder, inOrder + length - 1);
}

BinaryTreeNode* ConstructCore(int* startPreOder, int* endPreOrder, int* startInOrder, int* endInOrder)
{
	// 前序遍历的第一个数字作为根节点的值
	int rootValue = startPreOder[0];
	BinaryTreeNode* root = new BinaryTreeNode(rootValue);

	if (startPreOder == endPreOrder)
	{
		if (startInOrder == endInOrder&&*startPreOder == *startInOrder)
		{
			return root;
		}
		else
		{
			throw exception("Invalid input");
		}
	}

	//在中序遍历中找根节点的值
	int* rootInOrder = startInOrder;
	while (rootInOrder < endInOrder&&*rootInOrder != rootValue)
	{
		++rootInOrder;
	}

	if (rootInOrder == endInOrder&&*rootInOrder != rootValue)
	{
		throw exception("Invalid input");
	}

	//左子树长度  -1
	int LeftLength = rootInOrder - startInOrder;
	int* LeftPreOrderEnd = startInOrder + LeftLength;

	if (LeftLength > 0)
	{
		//构建左子树
		root->pLeft = ConstructCore(startPreOder + 1, LeftPreOrderEnd, startInOrder, rootInOrder - 1);
	}

	if (LeftPreOrderEnd < endPreOrder)

	{
		//构建右子树
		root->pRight = ConstructCore(LeftPreOrderEnd + 1, endPreOrder, rootInOrder + 1, endInOrder);
	}
	return root;
}

int main()
{

	int PreOrder[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int InOrder[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	BinaryTreeNode* root = Construct(PreOrder, InOrder, 8);
	return 0;
}



Node* Rebulid(char*& prev, char* in1, char in2)
{
	assert(prev && in1 && in2);
	Node* root = new Node(*prev);

	char* pos = in1;
	while (*pos != *prev)
	{
		++pos;
	}
	//[)
	if (in1 < pos)
	{
		root->_left = Rebulid(++prev, in1, in2);
	}
	//(]
	if (pos < in2)
	{
		root->_right = Rebulid(++prev, pos + 1, in2);
	}
}