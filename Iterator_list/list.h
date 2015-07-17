//I <tyler russon> have not used any code other than my own(or that in the textbook) for this project.I also have not used any function or data - structure from the Standard - Template Library.I understand that any violation of this disclaimer will result in a 0 for the project.
#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include "Iterator.h"

namespace list_1
{
	class list
    {
    public:
		//allowed to use while loops and for loops
        // CONSTRUCTOR
        list( );
		// postcondition: all nodes in the list are destroyed.
		~list();
        // MODIFICATION MEMBER FUNCTIONS
		//postcondition: entry is added to the front of the list
        void insert_front(const int& entry);
        //postcondition: entry is added to the back of the list
        void add_back(const int& entry);
		// postcondition: all nodes with data == entry are removed from the list
        void remove_all(const int& entry);
		// postcondition: an iterator is created pointing to the head of the list
		Iterator begin(void);
		
		// CONSTANT MEMBER FUNCTIONS
		// postcondition: the size of the list is returned
        int size( ) const;
    private:
		Node* head;
	};
	//allowed to use while loops and for loops
	// CONSTRUCTOR
	list::list()
	{
		head = NULL;
	}
	// postcondition: all nodes in the list are destroyed.
	list::~list()
	{
		while (head != NULL)
		{
			Node *temp = head;
			head = head->next;
			delete temp;
		}
	}
	// MODIFICATION MEMBER FUNCTIONS
	//postcondition: entry is added to the front of the list
	void list::insert_front(const int& entry)
	{
		Node *temp = new Node(entry);
		temp->next = head;
		head = temp;
	}
	//postcondition: entry is added to the back of the list
	void list::add_back(const int& entry)
	{
		Node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		Node *tempNode = new Node(entry);
		temp->next = tempNode;
	}
	// postcondition: all nodes with data == entry are removed from the list
	void list::remove_all(const int& entry)
	{
		Node* current = head;
		Node* prev = NULL;
		while (current != NULL)
		{
			if (current->data == entry)
			{
				if (prev == NULL)
				{
					head = current->next;
					delete current;
					current = head;
				}
				else
				{
					prev->next = current->next;
					delete current;
					current = prev->next;
				}
				
			}
			else
			{
				prev = current;
				current = current->next;
			}
		}

	}
	// postcondition: an iterator is created pointing to the head of the list
	Iterator list::begin(void)
	{
		return Iterator(head);
	}

	// CONSTANT MEMBER FUNCTIONS
	// postcondition: the size of the list is returned
	int list::size() const
	{
		Node * temp = head;
		for (int i = 0; temp->next != NULL; i++)
		return i;
	}
}

#endif

