//I <tyler russon> have not used any code other than my own(or that in the textbook) for this project.I also have not used any function or data - structure from the Standard - Template Library.I understand that any violation of this disclaimer will result in a 0 for the project.
#pragma once

namespace list_1
{
	struct Node
	{
		int data;
		Node *next;

		// Constructor
		// Postcondition: 
		Node (int d);
	};
	Node::Node(int n)
	{
		data = n;
		next = NULL;
	}

}