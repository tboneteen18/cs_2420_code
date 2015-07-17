#pragma once

namespace list_2
{
	struct Node
	{
		int data;
		Node* next;

		//Postcondition: Node data is initialized
		Node(int d)
		{
			data = d;
			next = NULL;
		}
	};
}