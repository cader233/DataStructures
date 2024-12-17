#include "LinkedList.h"

LinkedList::LinkedList(const LinkedList& ll)
{
	LNode* temp = ll.head;
	head = nullptr;
	tail = nullptr;
	while (temp != nullptr)
	{
		append(temp->data);
		temp = temp->next;
	}
}

bool LinkedList::search(int num)
{
	LNode* temp = head;

	while (temp != nullptr)
	{
		if (temp->data == num)
		{
			return true;
		}

		temp = temp->next;
	}

	return false;
}

bool LinkedList::append(int num)
{
	LNode* temp = new LNode(num);

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

bool LinkedList::prepend(int num)
{
	LNode* temp = new LNode(num);

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

bool LinkedList::remove(int num)
{
	LNode* temp = head;

	while (temp != nullptr)
	{
		if (temp->data == num)
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
	LNode* temp = head;
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
