#pragma once
#include "Hash_Table.h"
#include <iostream>

Hash_Table::Hash_Table()
{
	for (int i = 0; i<SIZE; i++)
		array[i] = new node(-1, "");
}
void Hash_Table::deconstructor_help(node* n)
{
	if (n->next != NULL)
		deconstructor_help(n->next);
	delete n;
	return;
}
Hash_Table::~Hash_Table()
{
	for (int i = 0; i<SIZE; i++)
	{
		if (array[i]->next != NULL)
			deconstructor_help(array[i]->next);
		delete array[i];
	}
}
void Hash_Table::insert(string passed_ele, double passed_weight, double key)
{
	int index = hash(key);
	if (array[index]->data == -1 || array[index]->data == -2)
	{
		array[index]->data = passed_weight;
		array[index]->element = passed_ele;
	}
	else
	{
		insert(array[index]->next, passed_ele, passed_weight);
	}
}
void Hash_Table::insert(node* &n, string passed_ele, double passed_weight)
{
	if (n == NULL)
		n = new node(passed_weight, passed_ele);
	else
		insert(n->next, passed_ele, passed_weight);
}
double Hash_Table::retrieve(double d, string element)
{
	int index = hash(d);
	if (array[index]->element == element)
		return array[index]->data;
	else
		return retrieve(d, element, array[index]->next);
}
double Hash_Table::retrieve(double d, string element, node* n)
{
	if (n->element == element)
		return n->data;
	return retrieve(d, element, n->next);
}
int Hash_Table::hash(double d)
{
	int ret = (int)(d / .05555) % SIZE;
	return ret;
}