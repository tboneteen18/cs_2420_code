//I <tyler> have not used any code other than my own(or that in the textbook) for this project.I also have not used any function or data - structure from the Standard - Template Library.I understand that any violation of this disclaimer will result in a 0 for the project.
#ifndef __STACK_H__
#define __STACK_H__
#include <cstddef>
#include <cassert>

template <class C>
class Node
{
public:
	C data;
	Node *next;

	// Constructor
	// Postcondition: 
	Node(C n) {
		data = n;
		next = NULL;
	}
};

template <class C>
class stack
{

public:
	stack();
	~stack();
	void push(C& data);
	void pop();
	bool empty();
	C& top();
private:
	Node<C>* head;

};
#endif // __STACK_H__

template <class C>
stack<C>::stack()
{
	head = NULL;
}

template <class C>
bool stack<C>::empty()
{
	return (head == NULL);
}


template <class C>
stack<C>::~stack()
{
	while (head != NULL)
	{
		Node<C> *temp = head;
		head = head->next;
		delete temp;
	}
}

template <class C>
void stack<C>::push(C& data)
{
	Node<C> *temp = new Node<C>(data);
	if (head == NULL)
	{
		head = temp;
	}
	else
		temp->next = head;
	head = temp;
}

template <class C>
void stack<C>::pop()
{
	if (head == NULL)
	{
		return;
	}
	else
	{
		Node<C>* current = head;
		head = head->next;
	//	return current->data;
	}

}

template <class C>
C& stack<C>::top()
{
	assert(head != NULL);
	return head->data;
}