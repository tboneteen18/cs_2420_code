//I <tyler russon> have not used any code other than my own(or that in the textbook) for this project.I also have not used any function or data - structure from the Standard - Template Library.I also have not shared my code with any student in this class.I understand that any violation of this disclaimer will result in a 0 for the project.

#include "sequence2.h"
#include "assert.h"
using namespace main_savitch_4;

sequence::sequence(int initial_capacity)
{
	used = 0;
	current_index = -1;
	capacity = initial_capacity;
	data = new value_type[initial_capacity];
}
sequence::sequence(const sequence& source)
{
	used = source.used;
	current_index = source.current_index;
	capacity = source.capacity;
	data = new value_type[source.capacity];
	for (int i = 0; i < source.capacity; i++)
	{
		data[i] = source.data[i];
	}
}
sequence::~sequence()
{
	delete[] data;
}
void sequence::resize(int new_capacity)
{
	value_type *large_array;
	if (new_capacity == capacity)
		return;
	if (new_capacity < used)
		new_capacity = used;
	large_array = new value_type[new_capacity];
	for (int i = 0; i <= used; i++)
	{
		large_array[i] = data[i];
	}
	delete data;
	data = large_array;
	capacity = new_capacity;
}
void sequence::start()
{
	if (used != 0)
	{
		current_index = 0;
	}
	else
	{
		current_index = -1;
	}
}
void sequence::advance()
{
	if (! is_item())
		return;
	if (current_index < used)
	{
		current_index++;
	}
	else
	{
		current_index = -1;
	}
}
void sequence::insert(const value_type& entry)
{
	if (current_index == -1)
		current_index = 0;
	if (used == capacity)
	{
		resize(capacity *2);
	}
	if (current_index < used)
	{
		for (int i = used; i > current_index; i--)
		{
			data[i] = data[i - 1];
		}
	}
	data[current_index] = entry;
	used++;
}
void sequence::attach(const value_type& entry)
{
	//if (current_index == -1)
		//current_index = 0;
	if (used == capacity) 
	{
		resize(capacity *2);
	}
	if (size() < capacity)
	{
		for (int i = used; i > current_index; i--)
		{
			data[i] = data[i + 1];
			data[current_index] = entry;
			used++;
		}
	}
}
void sequence::remove_current()
{
	assert(is_item());
	for (int i = current_index /*+ 1*/; i < used /*- 1*/; i++)
	{
		data[i] = data[i + 1];
		used--;
	}
}
void sequence::operator = (const sequence& source)
{
	if (this == &source)
	{
		return;
	}
	delete[] data;

	used = source.used;
	current_index = source.current_index;
	capacity = source.capacity;
	data = new value_type[source.capacity];
	for (int i = 0; i < source.capacity; i++)
	{
		data[i] = source.data[i];
	}
}
int sequence::size() const
{
	return used;
}
bool sequence::is_item() const
{
	if (current_index == -1)
		return false;
	else
		return true;
}
value_type sequence::current() const
{
	assert(is_item());
	return data[current_index];
}