//I <tyler> have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//I understand that any violation of this disclaimer will result in a 0 for the project.
#include "AVL_Tree.h"
#include <fstream>
using namespace std;
#include <cstdlib>
#include<iostream>
#include <iomanip>

AVL_Tree::AVL_Tree()
{
	root = NULL;
}

AVL_Tree::~AVL_Tree()
{

}

unsigned char AVL_Tree::height(node* p)
{
	return p ? p->height : 0;
}

int AVL_Tree::balancefactor(node* p)
{
	return height(p->right) - height(p->left);
}

void AVL_Tree::updateHeight(node* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl>hr ? hl : hr) + 1;
}

node* AVL_Tree::rotateright(node* p)
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	updateHeight(p);
	updateHeight(q);
	return q;
}

node* AVL_Tree::rotateleft(node* q)
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	updateHeight(q);
	updateHeight(p);
	return p;
}

node* AVL_Tree::rebalance(node* p)
{
	updateHeight(p);
	if (balancefactor(p) == 2)
	{
		if (balancefactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (balancefactor(p) == -2)
	{
		if (balancefactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p;
}

node* AVL_Tree::insert(node* p, int k)
{
	if (!p) return new node(k);
	if (k<p->key)
		p->left = insert(p->left, k);
	else
		p->right = insert(p->right, k);
	return rebalance(p);
}

void AVL_Tree::print(node* p, int indent)
{
	if (p != NULL)
	{
		if (p->left) print(p->left, indent + 4);
		if (p->right) print(p->right, indent + 4);
		if (indent)
		{
			cout << setw(indent) << ' ';
		}
		cout << p->key << "\n ";
	}

	/*if (j == NULL)
	{
		cout << "[EMPTY]" << endl;
	}
	//else if (p->right == NULL || p->left == NULL)
	//{
	//	cout << p << "[Leaf]" << endl;
	//}
	else
	{
		print(j->right, indent + 1);
		print(j->left, indent + 1);
	}*/
}

void AVL_Tree::preOrder(struct node *root)
{
	if (root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main()
{
	node* root = NULL;
	AVL_Tree AVL;
	char zed = '0';
	char input;
	int number;
	cout << "welcome. Please press i to insert a new number into the tree and p to pring the tree when finished press 0 to end" << endl;
	cin >> input;
	while (input != zed)
	{
		if (input == 'i')
		{
			cout << "please enter a number to insert." << endl;
			cin >> number;
			root = AVL.insert(root,number);
		}
		else if (input == 'p')
		{
			AVL.preOrder(root);
			cout << endl;
			AVL.print(root);
		}
		else
		{
			cout << "you entered in a wrong" << endl;
		}
		cout << "Please press i to insert a new number into the tree and p to pring the tree when finished press 0 to end" << endl;
		cin >> input;
	}
	system("PAUSE");
}