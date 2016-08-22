
#pragma once
#include <iostream>
using namespace std;


struct Node
{
	Node* left;
	Node* right;
	int value;

	Node(int v)
		:value(v)
		, left(NULL)
		, right(NULL)
	{}
};


int _find_ancestor(Node* root, Node* &ancestor, const Node* a, const Node* b)
{
	if (root == NULL)
	{
		return 0;
	}

	int count = 0;

	count += _find_ancestor(root->left, ancestor, a, b);

	if (root == a || root == b)
	{
		count += 1;
	}

	count += _find_ancestor(root->right, ancestor, a, b);

	if (count == 2)
	{
		ancestor = root;
		count = 0;//防止返回时，上面const的值还是2，导致anceator不准确被覆盖
	}
	return count;
}

void test_find_ancestor()
{
	Node n1(1);
	Node n2(2);
	Node n3(3);
	Node n4(4);
	Node n5(5);

	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;

	Node* ancestor = NULL;
	_find_ancestor(&n1, ancestor, &n4, &n5);

	_find_ancestor(&n1, ancestor, &n2, &n5);

	_find_ancestor(&n1, ancestor, &n5, &n3);

}


int main()
{

	test_find_ancestor();
	getchar();
	return 0;
}