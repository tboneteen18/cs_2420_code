//I <tyler> have not used any code other than my own(or that in the textbook) for this project.I also have not used any function or data - structure from the Standard - Template Library.I understand that any violation of this disclaimer will result in a 0 for the project.
#include "BinarySearchTree.h"
#include <fstream>
using namespace std;
#include <cstdlib>

BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}
BinarySearchTree::~BinarySearchTree()
{
	destroy();
}
void BinarySearchTree::destroy()
{
	destroy(root);
}
void BinarySearchTree::destroy(node *leaf)
{
	if (leaf != NULL)
	{
		destroy(leaf->left);
		destroy(leaf->right);
		delete leaf;
	}
}

int BinarySearchTree::size()
{
	if (root == NULL) 
	{
		return 0;
	}
	else 
	{ 
		return size(root->left) + size(root->right) + 1;
	}
}

int BinarySearchTree::size(node* leaf)
{
	if (leaf == NULL)
	{
		return 0;
	}
	else
	{
		return size(leaf->left) + size(leaf->right) + 1;
	}

}

void BinarySearchTree::insert(int item)
{
	if (root != NULL)
		insert(item, root);
	else
	{
		root = new node;
		root->item_value = item;
		root->left = NULL;
		root->right = NULL;
	}
}
void BinarySearchTree::insert(int item, node *leaf)
{
	//check to see if item to be inserted is less then what is in the node
		if (item < leaf->item_value)
		{
			//check to see if there the node has a left child or not
			if (leaf->left != NULL)
				insert(item, leaf->left);
			else
			{
				// since there is no node, we insert here and end
				node* temp = new node;
				temp->item_value = item;
				temp->left = NULL;
				temp->right = NULL;

				leaf->left = temp;
			}
		}
		//check to see if item to be inserted is greater then what is in the node
		else if (item > leaf->item_value)
		{
			////check to see if there the node has a right child or not
			if (leaf->right != NULL)
				insert(item, leaf->right);
			else
			{
				leaf->right = new node;
				leaf->right->item_value = item;
				leaf->right->left = NULL;
				leaf->right->right = NULL;
			}
		}
		//if item to be inserted is in the tree then return
		else return;
}

void BinarySearchTree::erase(int item)
{
	
}

void BinarySearchTree::erase(int item, node *leaf)
{
	//check to see if item to be inserted is less then what is in the node
	if (item < leaf->item_value)
	{
		//check to see if there the node has a left child or not
		if (leaf->left != NULL)
			erase(item, leaf->left);
	}
	else if (item > leaf->item_value)
	{
		////check to see if there the node has a right child or not
		if (leaf->right != NULL)
			erase(item, leaf->right);
	}
	else if (item = leaf->item_value)
	{
		node* temp = new node;
		if (leaf->right != NULL&&leaf->left != NULL)
		{

		}
		else if (leaf->left != NULL)
		{

		}
		else if (leaf->right != NULL)
		{
			
		}
		else
		{
			delete leaf;
		}
	}
}

int main()
{
	BinarySearchTree BST;
	
	system("PAUSE");
}