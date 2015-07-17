// Template CLASS PROVIDED: Iterator 
//I <tyler russon> have not used any code other than my own(or that in the textbook) for this project.I also have not used any function or data - structure from the Standard - Template Library.I understand that any violation of this disclaimer will result in a 0 for the project.
#pragma once
#include "Node.h"

namespace list_1
{
	class Iterator
	{
	public:
		// Constructor
		Iterator (Node *np);
		// precondition: is_item is true
		// post condition n points to the next item in the list
		void operator++();
		// precondition: 
		// postcondition: returns true if there is a valid item
		bool is_item();
		// precondition: is_item == true
		// postcondition returns data that n is pointing at
		int operator* ();

	private:
		Node* n;

	};
	// Constructor
	Iterator::Iterator(Node *np)
	{
		n = np;
	}
	// precondition: is_item is true
	// post condition n points to the next item in the list
	void Iterator::operator++()
	{
		n = n->next;
	}
	// precondition: 
	// postcondition: returns true if there is a valid item
	bool Iterator::is_item()
	{
		return n!=NULL;
	}
	// precondition: is_item == true
	// postcondition returns data that n is pointing at
	int Iterator::operator* ()
	{
		return n->data;
	}
}
