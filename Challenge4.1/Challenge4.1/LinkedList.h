#pragma once
#include <iostream>
using namespace std;

class LNode
{
public:
	int data;
	LNode* next;
	LNode* prev;

	LNode() : data(), next(nullptr), prev(nullptr) {};
	LNode(int data) : data(data), next(nullptr), prev(nullptr) {};
};

class LinkedList
{
private:
	LNode* head;
	LNode* tail;

public:
	LinkedList() : head(nullptr), tail(nullptr) {};
	~LinkedList() { destroy(); }
	LinkedList(const LinkedList& ll);

	void destroy()
	{
		LNode* current = head;
		while (current != nullptr)
		{
			LNode* temp = current;
			current = current->next;
			delete temp;
		}
		head = tail = nullptr;
	}

	bool search(int num);
	bool append(int num);
	bool prepend(int num);
	bool remove(int num);
	void display(ostream& os);

	friend std::ostream& operator<<(ostream& os, LinkedList& ll);
};

