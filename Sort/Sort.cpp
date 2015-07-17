#include "Sort.h"
#include <random>
#include <ctime>
#include <cstdlib>
//I <tyler> have not used any code other than my own(or that in the textbook) for this project.I also have not used any function or data - structure from the Standard - Template Library.I understand that any violation of this disclaimer will result in a 0 for the project.

Sort::Sort(int size,int seed)
{
	this->size = size;
	this->data = new int[size];
	set_seed(seed);
}


Sort::~Sort()
{
	
}


void Sort::set_seed(int seed)
{
	srand(seed);
}

void Sort::insertion_sort(int data[], size_t n) 
{
	int i, j, tmp;
	for (i = 1; i < n; i++) 
	{
		j = i;
		while (j > 0 && data[j - 1] > data[j]) 
		{
			tmp = data[j];
			data[j] = data[j - 1];
			data[j - 1] = tmp;
			j--;
		}
	}
}

void Sort::selectionsort(int data[], size_t n)
{
	size_t i, j, index_of_largest;
	int largest;
	int temp;

	if (n == 0)
		return; 

	for (i = n - 1; i > 0; --i)
	{
		largest = data[0];
		index_of_largest = 0;
		for (j = 1; j <= i; ++j)
		{
			if (data[j] > largest)
			{
				largest = data[j];
				index_of_largest = j;
			}
		}
		temp = data[index_of_largest];
		data[index_of_largest] = data[i];
		data[i] = temp;

	}
}

void Sort::mergesort(int data[], size_t n)
{
	size_t n1;
	size_t n2;

	if (n > 1)
	{
		n1 = n / 2;
		n2 = n - n1;
		mergesort(data, n1);
		mergesort((data + n1), n2);
		merge(data, n1, n2);
	}
}

void Sort::merge(int data[], size_t n1, size_t n2)
{
	int *temp;
	size_t copied = 0;
	size_t copied1 = 0;
	size_t copied2 = 0;
	size_t i;
	temp = new int[n1 + n2];

	while ((copied1 < n1) && (copied2 < n2))
	{
		if (data[copied1] < (data + n1)[copied2])
			temp[copied++] = data[copied1++];      
		else
			temp[copied++] = (data + n1)[copied2++];
	}
	while (copied1 < n1)
		temp[copied++] = data[copied1++];
	while (copied2 < n2)
		temp[copied++] = (data + n1)[copied2++];
	for (i = 0; i < n1 + n2; i++)
		data[i] = temp[i];
	delete[] temp;
}

int Sort::partition(int data[], size_t n, size_t pivot_point)
{
	int pivot = data[pivot_point];

	while (n < pivot_point)
	{
		while (data[n] < pivot)
			n++;

		while (data[pivot_point] > pivot)
			pivot_point--;

		if (data[n] == data[pivot_point])
			n++;
		else if (n < pivot_point)
		{
			int tmp = data[n];
			data[n] = data[pivot_point];
			data[pivot_point] = tmp;
		}
	}

	return pivot_point;
}

void Sort::quicksort(int data[], size_t n, size_t r)
{
	if (n < r)
	{
		int j = partition(data, n, r);
		quicksort(data, n, j - 1);
		quicksort(data, j + 1, r);
	}
}


int main()
{
	double sum = 0;
	const int size = 10;
	int array[size];
	int array1[10];
	Sort Sort_Prgm(size, 0);
	
	for (int i = 0; i < 10000; i++)
	{	
		for (int i = 0; i < size; i++)
		{
			array[i] = rand() % size;
		}
		clock_t start = clock();
		Sort_Prgm.insertion_sort(array, size);
		clock_t end = clock();
		clock_t diff = end - start;
		sum += diff;
	}
	sum = sum / 1000;
	cout << "Insert Sort took " << sum << " milliseconds";
	cout << endl;
	sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		for (int i = 0; i < size; i++)
		{
			array[i] = rand() % size;
		}
		clock_t start = clock();
		Sort_Prgm.selectionsort(array, size);
		clock_t end = clock();
		clock_t diff = end - start;
		sum += diff;
	}
	sum = sum / 1000;
	cout << "Selection Sort took " << sum << " milliseconds";
	cout << endl;
	sum = 0;
	for (int i = 0; i < 1000; i++)
	{
		for (int i = 0; i < size; i++)
		{
			array[i] = rand() % size;
		}
		clock_t start = clock();
		Sort_Prgm.mergesort(array, size);
		clock_t end = clock();
		clock_t diff = end - start;
		sum += diff;
	}
	sum = sum / 1000;
	cout << "Merge Sort took " << sum << " milliseconds";
	cout << endl;
	sum = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int i = 0; i < size; i++)
		{
			array[i] = rand() % size;
		}
		clock_t start = clock();
		Sort_Prgm.quicksort(array, 0, size - 1);
		clock_t end = clock();
		clock_t diff = end - start;
		sum += diff;
	}
		sum = sum / 1000;
		cout << "quick Sort took " << sum << " milliseconds";
		cout << endl;
	system("pause");
	return EXIT_SUCCESS;
}