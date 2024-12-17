#include "Queue.h"

Queue::~Queue()
{
	while (pop());
}

Queue::Queue(const Queue& q)
{
	Node* temp = q.front;

	front = end = nullptr;

	while (temp != nullptr)
	{
		push(temp->data);
		temp = temp->next;
	}
}

void Queue::push(int data)
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

bool Queue::pop()
{
	if (front == nullptr) return false;
	Node* temp = front;

	front = front->next;

	if (front == nullptr)
	{
		end = nullptr;
	}

	delete temp;
	return true;
}

bool Queue::peek(int& data)
{
	if (front == nullptr) return false;
	data = front->data;
	return true;
}
