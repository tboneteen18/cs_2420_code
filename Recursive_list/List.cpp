#include "List.h"
#include <iostream>
using namespace std;

namespace list_2
{
	// helper function for the destructor
	// add other helper functions here to complete your program.
	// they should all contain one or more Node* as parameters
	void List::destroy(Node *n)
	{
		if (n->next != NULL) 
		{
			destroy(n->next);
		}
		delete n;
	} 
	// postcondition: all nodes are destroyed using recursion
	List::~List()
	{
		if (head == NULL)
		{
			return;
		}
		else
		{
			destroy(head->next);
		}
		delete(head);
		head = NULL;
	}

	void addEnd_Helper(Node* n,int d)
	{
		if (n->next != NULL)
		{
			addEnd_Helper(n->next, d);
		}
		else // the end of the linked list
		{
			// just make a new node and add that as n->next = newNode;
			Node* newNode = new Node(d);
			n->next = newNode;
		}
	}
	// postcondition: add element d at the end of the list
	//                using recursion
	void List::addEnd(int d)
	{
		if (head == NULL)
		{
			head = new Node(d);
		}
		else 
		{
			addEnd_Helper(head, d);
		}
	}

	void printhelper(Node* n)
	{
		cout << n->data;
		if (n->next != NULL)
		{
			cout << "->";
			printhelper(n->next);
		}

	}
	// postcondition: print the list ussing recursion
	void List::print()
	{
		if (head == NULL)
		{
			cout << "No items in the list" << endl;
		}
		else
		{
			printhelper(head);
		}
		
	}

	void helperinsert(Node* n, int d);
	// precondition: list is in sorted order
	//                 (don't use addEnd with this function)
	// postcondition: d is inserted into the list so the list maintains
	//                sorted order. using recursison.
	void List::insert(int d)
	{
		if (head == NULL)
		{
			head = new Node(d);
		}
		else if (head->data >= d)
		{
			Node* newHeadNode = new Node(d);
			newHeadNode->next = head;
			head = newHeadNode;
		}
		else
		{
			helperinsert(head, d);
		}
	}

	void helperinsert(Node* n, int d)
	{
		if (n->next != NULL)
		{
			if (n->data <= d && n->next->data >= d)
			{
				// insert here
				Node* newNode = new Node(d);
				newNode->next = n->next;
				n->next = newNode;

			}
			else
			{
				helperinsert(n->next, d);
			}
		}
		else // the end of the linked list
		{
			// just make a new node and add that as n->next = newNode;
			Node* newNode = new Node(d);
			n->next = newNode;
		}
	}
	bool findhelper(Node* n, int d)
	{
		if (n->data == d)
		{
			return true;
		} else if (n->next == NULL)
		{
			return false;
		} else
		{
			return findhelper(n->next, d);
		}
	}
	// postcondition: if d is in the list then find returns true
	//                else find returns false
	bool List::find(int d)
	{
		if (head == NULL)
		{
			return false;
		}
		else
		{
			findhelper(head, d);
		}
	}
	
	int sizehelper(Node* n)
	{
		if (n->next != NULL)
		{
			return sizehelper(n->next) + 1;
		}
		else 
		{
			return 1;
		}
	}
	// postcondition: size is returned. Must be calculated using recursion.
	
	int List::size()
	{
		if (head->next != NULL)
		{
			return sizehelper(head);
		}
		else 
		{
			return 0;
		}
	}
}