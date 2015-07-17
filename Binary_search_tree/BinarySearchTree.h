#pragma once

struct node
{
	int item_value;
	node *left;
	node *right;
};
class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();
	int size();
	void erase(int item);
	void insert(int item);
	void destroy();
private:
	void destroy(node *leaf);
	void insert(int item, node *leaf);
	int size(node* leaf);
	void erase(int item, node* leaf);
	node *root;
};