#include "Zero.h"
#include <iostream>
#include <string>

struct Node
{
	Node *next;
	int data;
};

Node zero;
Node one;
Node two;
Node three;
Node four;
Node five;
Node six;

void print(Node *root)
{
	while (root->next != NULL)
	{
		std::cout << root->next->data << std::endl;
		root = root->next;
	}
}

void SwapNodes(Node *a, Node *b, Node *root)
{
	Node *t = new Node();
	t = a->next;
	a->next = b->next;
	b->next = t;

	bool bIsRoot = false; bool aIsRoot = false;
	if (a == root) aIsRoot = true;  
	if (b == root) bIsRoot = true;

	while (root->next != NULL)
	{
		if (root->next == a && aIsRoot == false) { root->next = b; }
		if (root->next == b && bIsRoot == false) { root->next = a; }

		root = root->next;
	}
}

void linkedList()
{
	zero.next = &one;
	one.next = &two;
	two.next = &three;
	three.next = &four;
	four.next = &five;
	five.next = &six;
	six.next = NULL;

	one.data = 1;
	two.data = 2;
	three.data = 3;
	four.data = 4;
	five.data = 5;
	six.data = 6;
}

int main()
{
	linkedList();

	SwapNodes(&one, &five, &zero);
	print(&zero);

	//SwapNodes(&one, &five, &zero);
	//print(&zero);

	system("Pause");
	return 0;
}