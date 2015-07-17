#pragma once
#pragma once

#include <iostream>
#include <fstream>
//I <tyler> have not used any code other than my own(or that in the textbook) for this project.I also have not used any function or data - structure from the Standard - Template Library.I understand that any violation of this disclaimer will result in a 0 for the project.

using namespace std;

class Sort
{
public:
	Sort(int size, int seed = 0);
	~Sort();
	void insertion_sort(int data[], size_t n);
	void selectionsort(int data[], size_t n);
	void mergesort(int data[], size_t n);
	void merge(int data[], size_t n1, size_t n2);
	void quicksort(int data[], size_t n, size_t r);
	int partition(int data[], size_t n, size_t pivot_point);
	void set_seed(int seed);
	int getSize() const
	{
		return size;
	}
	int* getArray() const
	{
		return data;
	}

	// this is just for practice and debugging.
	friend ostream& operator<< (ostream& out, const Sort& s)
	{
		const int* array = s.getArray();
		for (int i = 0; i < s.getSize(); ++i)
		{
			out << array[i] << ' ';
		}
		return out;
	}
private:
	size_t size;
	int* data;
};
