//I <tyler> have not used any code other than my own(or that in the textbook) for this project.I also have not used any function or data - structure from the Standard - Template Library.I understand that any violation of this disclaimer will result in a 0 for the project.
#include "Heap.h"
#include <iostream>
#include <cstdlib>
using namespace std;
const int twenty = 20;
Heap::Heap(int size)
{
	array = new int[size];
	for (int i = 0; i < twenty; i++)
	{
		array[i] = 0;
	}
}

Heap::~Heap()
{
	delete[] array;
}
void Heap::swap(int first, int second)
{
	int temp;
	temp = array[first];
	array[first] = array[second];
	array[second] = temp;
}
void Heap::insert(int item)
{
	array[end] = item;
	int endChild = end;
	while (endChild != 0 && array[parent(endChild)] >= array[endChild])
	{
		swap(parent(endChild), endChild);
		endChild = parent(endChild);
	}
	end++;
	print();
} 

int Heap::removeFront()
{
	end--;
	swap(end, 0);
	int temp = array[end];
	array[end]=0;
	int i = 0;
	while (leftChild(i) < end && rightChild(i) < end && (array[leftChild(i)] <= array[i] || array[rightChild(i)] <= array[i]))
	{
		if (array[leftChild(i)] <= array[rightChild(i)])
		{
			swap(leftChild(i), i);
			i = leftChild(i);
		}
		else
		{
			swap(rightChild(i), i);
			i = rightChild(i);
		}
	}
	print();
	return temp;
}
int Heap::parent(int index)
{
	int par;
	par = (index - 1) / 2;
	return par;
}

int Heap::leftChild(int index)
{
	int left;
	left = (2 * index) + 1;
	return left;
}
int Heap::rightChild(int index)
{
	int right;
	right = (2 * index) + 2;
	return right;
}
void Heap::print()
{
	for (int i = 0; i < twenty; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
void Heap::printTree()
{

}

int main()
{
	const int hund = 100;
	int array[twenty];
	Heap h(twenty);
	for (int i = 0; i < twenty; i++)
	{
		int rnd = rand() % hund + 1;
		array[i] = rnd;
		h.insert(array[i]);
	}
	for (int i = 0; i < twenty; i++)
	{
		array[i] = h.removeFront();
	}
	for (int i = 0; i < twenty; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	system("PAUSE");
}