// TYPEDEFS and MEMBER CONSTANTS for the sequence class:
//   typedef ____ value_type
//     sequence::value_type is the data type of the items in the sequence. It
//     may be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, an assignment operator, and a copy constructor.
//
//   static const int DEFAULT_CAPACITY = _____
//     sequence::DEFAULT_CAPACITY is the initial capacity of a sequence that is
//     created by the default constructor.
//

#include "sequence2.h"
#include "assert.h"
namespace main_savitch_4
{
// CONSTRUCTORS for the sequence class:
//     sequence(int initial_capacity = DEFAULT_CAPACITY)
//     Postcondition: The sequence has been initialized as an empty sequence.
//     The insert/attach functions will work efficiently (without allocating
//     new memory) until this capacity is reached.

	sequence::sequence(int initial_capacity)
	{
		 used = 0;
         current_index = -1;
		 capacity = initial_capacity;
		 data = new value_type [initial_capacity];

	}


//   sequence(const sequence& source)
//     Postcondition: the sequence has made a deep copy of the source sequence.


	sequence::sequence(const sequence& source) 
	{
		 used = source.used;
         current_index = source.current_index;
		 capacity = source.capacity;
		 data = new value_type [source.capacity];
		 for(int i = 0; i < source.capacity; i++)
		 {
			 data[i] = source.data[i];
		 }
	}

//
//  DESTRUCTOR:
//	 ~sequence()
//		Poscondition: all dynamically allocated memory has been destroyed.
//
	sequence::~sequence()
	{
		delete [] data;
	}
//	OPERATOR:
//	  void operator =(const sequence& source);
//	  Postondition: a deep copy of the source sequence replaces the current sequence.
//                  Unused dynamic memory is deallocated.
//

	void sequence::operator =(const sequence& source)
	{
		 delete [] data;

		 used = source.used;
         current_index = source.current_index;
		 capacity = source.capacity;
		 data = new value_type [source.capacity];
		 for(int i = 0; i < source.capacity; i++)
		 {
			 data[i] = source.data[i];
		 }
	}

// MODIFICATION MEMBER FUNCTIONS for the sequence class:
//	   void resize(int new_capacity)
//     Postcondition: The sequence's current capacity is changed to the 
//     new_capacity (but not less that the number of items already on the
//     list). The insert/attach functions will work efficiently (without
//     allocating new memory) until this new capacity is reached.
//
	void sequence::resize(int new_capacity)
	{
		int new_size;
		value_type *temp;
		
		if (used > new_capacity)
		{
			new_size = used;
		}
		else
		{
			new_size = new_capacity;
		}
		temp = new value_type [new_size];
		for (int i = 0; i <= used; i++)
		{
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;
		

	}

//   void start( )
//     Postcondition: The first item on the sequence becomes the current item
//     (but if the sequence is empty, then there is no current item).
//
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

//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
	void sequence::advance()
	{
		assert(is_item());
		// if cur + 1 >= used then resize
		// always increment current_index
		if (current_index < used)
		{
			current_index++;
		}
		else
		{
			// why -1?
			current_index = -1;
		}
	}

//   void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence
//     before the current item. If there was no current item, then the new entry 
//     has been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
	void sequence::insert(const value_type& entry)
	{
		if (used == capacity)
		{
			resize(capacity * 2);
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

//   void attach(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has 
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
	void sequence::attach(const value_type& entry)
	{
		// push it one back so +1 and the call insert
		if (used == capacity)
		{
			resize(capacity * 2);
		}
		if (current_index < used)
		{
			insert(current_index + 1);
			//broken
			//for (int i = used; i > current_index; i--)
			//{
			//	data[i] = data[i + 1];
			//}
		}
		//broken
		data[current_index] = entry;
		used++;
		
	}

//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and the
//     item after this (if there is one) is now the new current item.
//	   else there is no current item.
//
	void sequence::remove_current()
	{
		assert(is_item());
		// broken
		for (int i = current_index + 1; i < used - 1; i++)
		{
			data[i] = data[i + 1];
			
		}
			used--;
	}

// CONSTANT MEMBER FUNCTIONS for the sequence class:
//   int size( ) const
//     Postcondition: The return value is the number of items in the sequence.
//
	int sequence::size() const
	{
		return used;
	}

//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
	bool sequence::is_item() const
	{
		return current_index < used;
	}

//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequence.
//
	value_type sequence::current() const
	{
		assert(is_item());
		//if (current_item >= used) {}
		return data[current_index];
	}

// VALUE SEMANTICS for the sequence class:
//    Assignments and the copy constructor may be used with sequence objects.
//
	
}