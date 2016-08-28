#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
#include<vector>
using namespace std;

struct BinaryTreeNode
{
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;

	int data;
};

class BinaryTree
{
public:
	typedef BinaryTreeNode  Node;
	Node* _root;

	//O(N*N)

	size_t Height(Node* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		int LeftDepth = Height(root->_left);
		int RightDepth = Height(root->_right);
		return LeftDepth > RightDepth ? LeftDepth + 1 : RightDepth + 1;
	}
	int maxLen = 0;
	void MaxLen(Node* root)
	{
		if (root == NULL)
			return;
		int lefeH = Height(root->_left);
		int rightH = Height(root->_right);
		if (lefeH + rightH > maxLen)
			maxLen = lefeH + rightH;

		MaxLen(root->_left);
		MaxLen(root->_right);
	}

	//O(N)
	int maxLen = 0;
	void MaxLen(Node* root)
	{
		if (root == NULL)
			return 0;
		int leftH = Maxlen(root->_left);
		int rightH = MaxLen(root->_right);

		if (leftH + rightH > maxLen)
			maxLen = leftH + rightH;
		return leftH > rightH ? leftH + 1 : rightH + 1;
	}

};