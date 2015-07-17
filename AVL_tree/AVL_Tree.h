#pragma once
#pragma once
#include <cstdlib>
#include<iostream>
#include <fstream>
class node
{
public:
	int key;
	unsigned char height;
	node* left;
	node* right;
	node(int k) { key = k; left = right = 0; height = 1; }
	~node() {}
};
class AVL_Tree
{
public:
	AVL_Tree();
	~AVL_Tree();
	unsigned char height(node* p);
	int balancefactor(node* p);
	void updateHeight(node* p);
	node* rotateright(node* p);
	node* rotateleft(node* q);
	node* rebalance(node* p);
	node* insert(node* p, int k);
	void preOrder(struct node * root);
	void print(node* p, int indent = 0);
private:
	node* root;
};