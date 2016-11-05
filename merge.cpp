#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>

using namespace std;

void merge(int a[], int lengthA, int b[], int lengthB,int c[])
{
	int indexA = 0;
	int indexB = 0;
	int indexC = 0;
	while (indexA<lengthA && indexB<lengthB)
	{
		if (a[indexA] < b[indexB])
		{
			c[indexC++] = a[indexA++];
		}
		else
		{
			c[indexC++] = b[indexB++];
		}
	}
	while (indexA < lengthA)
	{
		c[indexC++] = a[indexA++];
	}
	while (indexB < lengthB)
	{
		c[indexC++] = b[indexB++];
	}
};

int main()
{
	int a[] = { 1, 2, 3, 4 };
	int b[] = { 5, 6, 7, 8 };
	int c[8] = {};
	merge(a, 4, b, 4, c);
	for (int i = 0; i <= 7; i++)
	{
		cout << c[i] << " ";
	}
	getchar();
	return 0;
}