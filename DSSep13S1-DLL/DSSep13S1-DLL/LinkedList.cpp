#include "LinkedList.h"

LinkedList::~LinkedList()
{
	Node* temp = head, * rmv;
	while (temp != nullptr)
	{
		rmv = temp;
		temp = temp->next;
		delete rmv;
	}
	head = nullptr;
	tail = nullptr;
}

LinkedList::LinkedList(const LinkedList& ll)
{
	Node* temp = ll.head;
	head = nullptr;
	tail = nullptr;
	while (temp != nullptr)
	{
		append(temp->data);
		temp = temp->next;
	}
}

bool LinkedList::append(const Data & val)
{
	Node* temp = new Node(val);
	if (head == nullptr)
	{
		head = temp;
	}
	else
	{
		tail->next = temp;
	}
	temp->prev = tail;
	tail = temp;
	return true;
}

bool LinkedList::prepend(const Data & val)
{
	Node* temp = new Node(val);
	if (head == nullptr)
	{
		tail = temp;
	}
	else
	{
		head->prev = temp;
	}
	temp->next = head;
	head = temp;
	return true;
}

bool LinkedList::search(int id, Data &val)
{
	Node* temp = head;
	while (temp != nullptr)
	{
		if (temp->data.id == id)
		{
			val = temp->data;
			return true;
		}
		temp = temp->next;
	}
	return false;
}

bool LinkedList::remove(const Data &val)
{
	Node* temp = head;
	while (temp != nullptr)
	{
		if (temp->data.id == val.id)
		{
			if (temp->prev == nullptr)
			{
				head = temp->next;
			}
			else
			{
				temp->prev->next = temp->next;

			}
			if (temp->next = nullptr)
			{
				tail = temp->prev;
			}
			else
			{
				temp->next->prev = temp->prev;
			}

			delete temp;
			return true;
		}

		temp = temp->next;
	}
	return false;
}

void LinkedList::display(std::ostream& os)
{
	Node* temp = head;
	while (temp != nullptr)
	{
		os << temp->data << std::endl;
		temp = temp->next;
	}
}

std::ostream& operator<<(std::ostream& os, LinkedList& ll)
{
	ll.display(os);
	return os;
}

std::ostream& operator<<(std::ostream& os, Data& d)
{
	os << "Id: " << d.id << " Cost: $" << d.cost << " ";
	return os;
}
