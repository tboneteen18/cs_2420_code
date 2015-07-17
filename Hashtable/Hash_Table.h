#pragma once
#include <cstdlib>
#include <string>
using namespace std;
struct node
{
	double data;
	string element;
	node* next;
	node(double d, string ele)
	{
		data = d;
		element = ele;
		next = NULL;
	}
};
const int SIZE = 50;
class Hash_Table
{
	node* array[SIZE];
public:
	Hash_Table();
	~Hash_Table();
	void deconstructor_help(node* n);
	void insert(string , double , double );
	void insert(node* &n, string passed_ele, double passed_weight);
	double retrieve(double d, string element);
	double retrieve(double d, string element, node* n);
	int hash(double);
	Hash_Table operator[](int);
	void clear(node* array[]){ Hash_Table::~Hash_Table(); }
};