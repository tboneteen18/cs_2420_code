#include "queue.h"
#include <cassert>

queue::queue()
{
	count = 0;
	first = 0;
	last = CAPACITY - 1;
}

queue::~queue()
{
}

int queue::top() const
{
	assert(!empty());
	return data[first];
}

void queue::pop()
{
	assert(!empty());
	first = next_index(first);
	--count;
}

void queue::push(const int& entry)
{
	assert(size() < CAPACITY);
	last = next_index(last);
	data[last] = entry;
	++count;
}