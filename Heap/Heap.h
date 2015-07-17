#pragma once
class Heap
{
public:
	Heap(int size);
	~Heap();
	void insert(int item);
	int removeFront();
	void print();
	void printTree();
private:
	int end = 0;
	int *array;
	int leftChild(int index);
	int rightChild(int index);
	int parent(int index);
	int index;
	void swap(int first, int second);
};

