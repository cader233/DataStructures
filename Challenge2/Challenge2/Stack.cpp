#include "Stack.h"

Stack::~Stack()
{
	while (pop());
}

void Stack::push(int data)
{
	Node* temp = new Node(data);
	if (front == nullptr)
	{
		front = temp;
	}
	else
	{
		end->next = temp;
	}
	end = temp;
}

bool Stack::pop()
{
	if (front == nullptr) return false;
	Node* temp = front;
	front = front->next;
	delete temp;
	return true;
}

bool Stack::peek(int& data)
{
	if (front == nullptr) return false;
	data = front->data;
	return true;
}

void Stack::display(ostream& os)
{
	Node* temp = front;
	while (temp != nullptr)
	{
		os << temp->data << " ";
		temp = temp->next;
	}
	os << endl;
}