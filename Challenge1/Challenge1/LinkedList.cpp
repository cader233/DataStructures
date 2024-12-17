#include "LinkedList.h"

LinkedList::~LinkedList()
{
	Node* temp = head, *rmv;
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

bool LinkedList::append(string word)
{
	Node* temp = new Node(word);

	temp->prev = tail;

	if (head == nullptr)
	{
		head = temp;
	}
	else
	{
		tail->next = temp;
	}
	tail = temp;
	return true;
}

bool LinkedList::prepend(string word)
{
	Node* temp = new Node(word);

	temp->next = head;

	if (head == nullptr)
	{
		tail = temp;
	}
	else
	{
		head->prev = temp;
	}
	head = temp;
	return true;
}

bool LinkedList::remove(string word)
{
    Node* temp = head;

	while (temp != nullptr)
	{
		if (temp->data == word)
		{
			if (temp == head)
			{
				head = temp->next;
			}
			else
			{
				temp->prev->next = temp->next;
			}
			if (temp == tail)
			{
				tail = tail->prev;
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

void LinkedList::display(ostream& os)
{
	Node* temp = head;
	while (temp != nullptr)
	{
		os << temp->data << " ";
		temp = temp->next;
	}
	os << endl;
}

ostream& operator<<(ostream& os, LinkedList& ll)
{
	ll.display(os);
	return os;
}

bool LinkedList::tailRemove(string word)
{
	Node* temp = tail;

	while (temp != nullptr)
	{
		if (temp->data == word)
		{
			if (temp == head)
			{
				head = temp->next;
			}
			else
			{
				temp->prev->next = temp->next;
			}
			if (temp == tail)
			{
				tail = tail->prev;
			}
			else
			{
				temp->next->prev = temp->prev;
			}

			delete temp;
			return true;
		}
		temp = temp->prev;
	}
	return false;
}

void LinkedList::tailDisplay(ostream& os)
{
	Node* temp = tail;
	while (temp != nullptr)
	{
		os << temp->data << " ";
		temp = temp->prev;
	}
	os << endl;
}